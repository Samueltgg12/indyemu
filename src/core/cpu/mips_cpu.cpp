// src/core/cpu/mips_cpu.cpp
#include "core/cpu/mips_cpu.hpp"

namespace indyemu {

// ---------------------------------------------------------------------------
// 128-bit arithmetic helpers (portable, no __int128 dependency).
// Used by the MIPS III 64-bit multiply/divide instructions (dmult/dmultu/
// ddiv/ddivu), which operate on the 128-bit HI:LO pair.
// ---------------------------------------------------------------------------

// Unsigned 64x64 -> 128-bit product, split into (hi, lo).
static void mul64x64(u64 a, u64 b, u64 &hi, u64 &lo) {
  const u64 a_lo = a & 0xFFFFFFFFu;
  const u64 a_hi = a >> 32;
  const u64 b_lo = b & 0xFFFFFFFFu;
  const u64 b_hi = b >> 32;

  const u64 p0 = a_lo * b_lo;
  const u64 p1 = a_lo * b_hi;
  const u64 p2 = a_hi * b_lo;
  const u64 p3 = a_hi * b_hi;

  const u64 mid = (p0 >> 32) + (p1 & 0xFFFFFFFFu) + (p2 & 0xFFFFFFFFu);
  lo = (mid << 32) | (p0 & 0xFFFFFFFFu);
  hi = p3 + (p1 >> 32) + (p2 >> 32) + (mid >> 32);
}

// Negate a 128-bit value in place (two's complement).
static void neg128(u64 &hi, u64 &lo) {
  const u64 new_lo = ~lo + 1;
  const u64 carry = (new_lo == 0) ? 1 : 0;
  lo = new_lo;
  hi = ~hi + carry;
}

// Unsigned 128-bit (hi:lo) / 64-bit divisor -> 64-bit quotient + remainder.
// Divisor of zero is architecturally undefined; we return zero to keep the
// interpreter deterministic.
static void div128x64(u64 hi, u64 lo, u64 divisor, u64 &quot, u64 &rem) {
  if (divisor == 0) {
    quot = 0;
    rem = 0;
    return;
  }
  u64 q_hi = 0, q_lo = 0, r = 0;
  for (int i = 127; i >= 0; --i) {
    const u64 bit = (i >= 64) ? ((hi >> (i - 64)) & 1) : ((lo >> i) & 1);
    r = (r << 1) | bit;
    if (r >= divisor) {
      r -= divisor;
      if (i >= 64) {
        q_hi |= (1ULL << (i - 64));
      } else {
        q_lo |= (1ULL << i);
      }
    }
  }
  (void)q_hi; // quotient is 64-bit; overflow of the 128/64 divide is undefined
  quot = q_lo;
  rem = r;
}

MipsCpu::MipsCpu(Memory &memory) : memory_(memory) { reset(); }

void MipsCpu::reset() {
  regs_.gpr.fill(0);
  regs_.cop0.fill(0);
  regs_.hi = 0;
  regs_.lo = 0;
  regs_.pc = kInitialPc;
  regs_.next_pc = kInitialPc + 4;
}

u32 MipsCpu::fetchInstruction() const { return memory_.read32(regs_.pc); }

void MipsCpu::setReg(u32 index, u64 value) {
  if (index != 0) {
    regs_.gpr[index] = value;
  }
}

u64 MipsCpu::getReg(u32 index) const { return regs_.gpr[index]; }

bool MipsCpu::step() {
  static u64 step_count = 0;
  step_count++;
  if (step_count % 100000 == 0) {
    std::cerr << "Step: " << step_count << ", PC=0x" << std::hex << regs_.pc
              << std::dec << std::endl;
  }

  // Update Cause register IP bits from the interrupt controller before checking
  updateCauseIPBits();

  // Check for pending interrupts before executing the next instruction
  if (checkInterrupts()) {
    return true;
  }

  const u64 current_pc = regs_.pc;
  const u32 instr = fetchInstruction();
  regs_.pc = regs_.next_pc;
  regs_.next_pc = regs_.pc + 4;

  executeInstruction(instr, current_pc);
  return true;
}

void MipsCpu::dumpState() const {
  if (!trace_enabled_) {
    return;
  }
  std::cout << "PC=0x" << std::hex << regs_.pc << " NextPC=0x" << regs_.next_pc
            << "\n";
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 4; ++j) {
      const int index = i * 4 + j;
      std::cout << "R" << std::dec << index << "=0x" << std::hex << std::setw(8)
                << std::setfill('0') << regs_.gpr[index] << "  ";
    }
    std::cout << "\n";
  }
  std::cout << std::dec;
}

void MipsCpu::illegalInstruction(u32 instr) const {
  std::cerr << "Illegal instruction at PC 0x" << std::hex << regs_.pc << ": 0x"
            << instr << "\n";
}

void MipsCpu::updateCauseIPBits() {
  // Clear the IP bits in the Cause register
  regs_.cop0[kCp0Cause] &= ~kCauseIP;

  // Query the interrupt controller for pending interrupt lines
  if (interrupt_controller_) {
    const u32 pending = interrupt_controller_->pendingInterruptLines();
    // Map pending lines (bit N = IP bit N) into the Cause register IP field
    // (bits 8-15)
    regs_.cop0[kCp0Cause] |= (pending & 0xFFu) << kCauseIPShift;
  }
}

bool MipsCpu::checkInterrupts() {
  const u32 status = regs_.cop0[kCp0Status];
  const u32 cause = regs_.cop0[kCp0Cause];

  // Interrupts are only taken when:
  //  - IE (Status bit 0) is set
  //  - EXL (Status bit 1) is clear (not already in an exception)
  //  - ERL (Status bit 2) is clear (not in error level)
  //  - At least one pending IP bit is enabled by the IM field
  if ((status & kStatusIE) == 0) {
    return false;
  }
  if ((status & (kStatusEXL | kStatusERL)) != 0) {
    return false;
  }

  const u32 pending = (cause & kCauseIP) >> kCauseIPShift;
  const u32 enabled = (status & kStatusIM) >> kStatusIMShift;
  if ((pending & enabled) == 0) {
    return false;
  }

  // Take the interrupt exception. EPC is the current PC (no delay slot for
  // interrupts taken at instruction boundary).
  takeException(kExcInt, regs_.pc, false);
  return true;
}

void MipsCpu::takeException(u32 exc_code, u64 epc, bool in_delay_slot) {
  // Set the exception code in the Cause register
  regs_.cop0[kCp0Cause] &= ~kCauseExcCode;
  regs_.cop0[kCp0Cause] |= (exc_code << kCauseExcCodeShift);

  // Set EPC. If in a delay slot, EPC points to the branch instruction and BD
  // bit is set.
  regs_.cop0[kCp0EPC] = epc;
  if (in_delay_slot) {
    regs_.cop0[kCp0Cause] |= 0x80000000u; // BD bit
  } else {
    regs_.cop0[kCp0Cause] &= ~0x80000000u;
  }

  // Set EXL bit to prevent nested exceptions
  regs_.cop0[kCp0Status] |= kStatusEXL;

  // Jump to the general exception vector
  regs_.pc = kExceptionBase;
  regs_.next_pc = kExceptionBase + 4;
}

void MipsCpu::executeInstruction(u32 instr, u64 current_pc) {
  const u32 op = (instr >> 26) & 0x3Fu;

  switch (op) {
  case 0x00:
    handleRType(instr, current_pc);
    break;
  case 0x01:
    handleRegimmType(instr, current_pc);
    break;
  case 0x02:
  case 0x03:
    handleJType(instr, current_pc);
    break;
  case 0x04:
  case 0x05:
  case 0x06:
  case 0x07:
  case 0x08:
  case 0x09:
  case 0x0A:
  case 0x0B:
  case 0x0C:
  case 0x0D:
  case 0x0E:
  case 0x0F:
  case 0x20:
  case 0x21:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2A:
  case 0x2B:
  case 0x2C:
  case 0x2D:
  case 0x2E:
  case 0x2F:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3A:
  case 0x3B:
    handleIType(instr, current_pc);
    break;
  case 0x10:
    handleCop0Type(instr, current_pc);
    break;
  case 0x11:
    handleCop1Type(instr, current_pc);
    break;
  case 0x13:
    // COP3 paths are not used by the early Indy PROM flow; treat as a safe
    // no-op to keep the boot ROM moving.
    break;
  case 0x1C:
    handleSpecial2(instr, current_pc);
    break;
  case 0x1F:
    handleSpecial3(instr, current_pc);
    break;
  default:
    illegalInstruction(instr);
    break;
  }

  // Check for TLB exceptions after instruction execution
  u32 vaddr;
  bool is_store;
  Memory::TLBExceptionType type;
  if (memory_.checkAndClearTLBException(vaddr, is_store, type)) {
    // Handle TLB exception - for now just print and continue
    // In a real implementation, this would trigger an exception
    std::cerr << "TLB Exception: vaddr=0x" << std::hex << vaddr
              << ", type=" << static_cast<int>(type)
              << ", is_store=" << is_store << std::dec << std::endl;

    // Set the BadVAddr register (CP0 register 8)
    regs_.cop0[8] = vaddr;
  }
}

void MipsCpu::handleRType(u32 instr, u64 current_pc) {
  const u32 funct = instr & 0x3Fu;
  const u32 rs = (instr >> 21) & 0x1Fu;
  const u32 rt = (instr >> 16) & 0x1Fu;
  const u32 rd = (instr >> 11) & 0x1Fu;
  const u32 shamt = (instr >> 6) & 0x1Fu;

  switch (funct) {
  case 0x00: // sll
    setReg(rd, getReg(rt) << shamt);
    break;
  case 0x02: // srl
    setReg(rd, getReg(rt) >> shamt);
    break;
  case 0x03: // sra
    setReg(rd, static_cast<u32>(static_cast<i32>(getReg(rt)) >> shamt));
    break;
  case 0x38: // dsll (64-bit shift left logical)
    setReg(rd, getReg(rt) << shamt);
    break;
  case 0x3A: // dsrl (64-bit shift right logical)
    setReg(rd, getReg(rt) >> shamt);
    break;
  case 0x3B: // dsra (64-bit shift right arithmetic)
    setReg(rd, static_cast<u64>(static_cast<i64>(getReg(rt)) >> shamt));
    break;
  case 0x3C: // dsll32 (64-bit shift left logical +32)
    setReg(rd, getReg(rt) << (shamt + 32));
    break;
  case 0x3E: // dsrl32 (64-bit shift right logical +32)
    setReg(rd, getReg(rt) >> (shamt + 32));
    break;
  case 0x3F: // dsra32 (64-bit shift right arithmetic +32)
    setReg(rd, static_cast<u64>(static_cast<i64>(getReg(rt)) >> (shamt + 32)));
    break;
  case 0x04: // sllv
    setReg(rd, getReg(rt) << (getReg(rs) & 0x1F));
    break;
  case 0x06: // srlv
    setReg(rd, getReg(rt) >> (getReg(rs) & 0x1F));
    break;
  case 0x07: // srav
    setReg(rd, static_cast<u32>(static_cast<i32>(getReg(rt)) >>
                                (getReg(rs) & 0x1F)));
    break;
  case 0x14: // dsllv (64-bit shift left logical, variable)
    setReg(rd, getReg(rt) << (getReg(rs) & 0x3F));
    break;
  case 0x16: // dsrlv (64-bit shift right logical, variable)
    setReg(rd, getReg(rt) >> (getReg(rs) & 0x3F));
    break;
  case 0x17: // dsrav (64-bit shift right arithmetic, variable)
    setReg(rd, static_cast<u64>(static_cast<i64>(getReg(rt)) >>
                                (getReg(rs) & 0x3F)));
    break;
  case 0x08: // jr
    regs_.next_pc = getReg(rs);
    break;
  case 0x09: // jalr
    setReg(rd == 0 ? 31 : rd, regs_.pc + 8);
    regs_.next_pc = getReg(rs);
    break;
  case 0x0C: // syscall
    std::cout << "System call encountered (instruction 0x" << std::hex << instr
              << ")\n";
    break;
  case 0x0F: // sync
    // Real MIPS III/IV PROM and kernel code uses SYNC as a memory ordering
    // barrier. Treat it as a no-op for the interpreter stage while preserving
    // the architectural ordering point.
    break;
  case 0x10: // mfhi
    setReg(rd, regs_.hi);
    break;
  case 0x11: // mthi
    regs_.hi = getReg(rs);
    break;
  case 0x12: // mflo
    setReg(rd, regs_.lo);
    break;
  case 0x13: // mtlo
    regs_.lo = getReg(rs);
    break;
  case 0x18: // mult
  {
    const u64 result =
        static_cast<u64>(static_cast<i64>(static_cast<i32>(getReg(rs))) *
                         static_cast<i64>(static_cast<i32>(getReg(rt))));
    regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
    regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
  } break;
  case 0x19: // multu
  {
    const u64 result =
        static_cast<u64>(getReg(rs)) * static_cast<u64>(getReg(rt));
    regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
    regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
  } break;
  case 0x1C: // dmult (64x64 -> 128-bit, signed)
  {
    const u64 a = getReg(rs);
    const u64 b = getReg(rt);
    const bool neg = ((a ^ b) & 0x8000000000000000ULL) != 0;
    const u64 ua = (a & 0x8000000000000000ULL) ? (~a + 1) : a;
    const u64 ub = (b & 0x8000000000000000ULL) ? (~b + 1) : b;
    mul64x64(ua, ub, regs_.hi, regs_.lo);
    if (neg) {
      neg128(regs_.hi, regs_.lo);
    }
  } break;
  case 0x1D: // dmultu (64x64 -> 128-bit, unsigned)
    mul64x64(getReg(rs), getReg(rt), regs_.hi, regs_.lo);
    break;
  case 0x1E: // ddiv (128-bit HI:LO / 64-bit, signed)
  {
    u64 hi = regs_.hi, lo = regs_.lo;
    i64 divisor = static_cast<i64>(getReg(rt));
    if (divisor == 0) {
      break; // undefined; leave HI:LO unchanged
    }
    const bool dividend_neg = (hi & 0x8000000000000000ULL) != 0;
    if (dividend_neg) {
      neg128(hi, lo);
    }
    bool quot_neg = dividend_neg;
    if (divisor < 0) {
      divisor = -divisor;
      quot_neg = !quot_neg;
    }
    u64 quot, rem;
    div128x64(hi, lo, static_cast<u64>(divisor), quot, rem);
    regs_.lo = quot_neg ? (~quot + 1) : quot;
    regs_.hi = dividend_neg ? (~rem + 1) : rem;
  } break;
  case 0x1F: // ddivu (128-bit HI:LO / 64-bit, unsigned)
  {
    const u64 divisor = getReg(rt);
    if (divisor == 0) {
      break; // undefined; leave HI:LO unchanged
    }
    u64 quot, rem;
    div128x64(regs_.hi, regs_.lo, divisor, quot, rem);
    regs_.lo = quot;
    regs_.hi = rem;
  } break;
  case 0x20: // add
    setReg(rd, getReg(rs) + getReg(rt));
    break;
  case 0x21: // addu
    setReg(rd, getReg(rs) + getReg(rt));
    break;
  case 0x22: // sub
    setReg(rd, getReg(rs) - getReg(rt));
    break;
  case 0x23: // subu
    setReg(rd, getReg(rs) - getReg(rt));
    break;
  case 0x2C: // dadd (64-bit add, trap on overflow)
  {
    const i64 a = static_cast<i64>(getReg(rs));
    const i64 b = static_cast<i64>(getReg(rt));
    const i64 result = a + b;
    if (((a ^ result) & (b ^ result)) < 0) {
      takeException(kExcOv, current_pc, false);
      break;
    }
    setReg(rd, static_cast<u64>(result));
  } break;
  case 0x2D: // daddu (64-bit add, no trap)
    setReg(rd, getReg(rs) + getReg(rt));
    break;
  case 0x2E: // dsub (64-bit subtract, trap on overflow)
  {
    const i64 a = static_cast<i64>(getReg(rs));
    const i64 b = static_cast<i64>(getReg(rt));
    const i64 result = a - b;
    if (((a ^ b) & (a ^ result)) < 0) {
      takeException(kExcOv, current_pc, false);
      break;
    }
    setReg(rd, static_cast<u64>(result));
  } break;
  case 0x2F: // dsubu (64-bit subtract, no trap)
    setReg(rd, getReg(rs) - getReg(rt));
    break;
  case 0x24: // and
    setReg(rd, getReg(rs) & getReg(rt));
    break;
  case 0x25: // or
    setReg(rd, getReg(rs) | getReg(rt));
    break;
  case 0x26: // xor
    setReg(rd, getReg(rs) ^ getReg(rt));
    break;
  case 0x27: // nor
    setReg(rd, ~(getReg(rs) | getReg(rt)));
    break;
  case 0x2A: // slt
    setReg(rd, (static_cast<i32>(getReg(rs)) < static_cast<i32>(getReg(rt)))
                   ? 1u
                   : 0u);
    break;
  case 0x2B: // sltu
    setReg(rd, (getReg(rs) < getReg(rt)) ? 1u : 0u);
    break;
  default:
    illegalInstruction(instr);
    break;
  }
}

void MipsCpu::handleJType(u32 instr, u64 current_pc) {
  const u32 opcode = (instr >> 26) & 0x3F;
  const u32 target = (instr & 0x03FFFFFFu) << 2;
  const u32 new_pc = (current_pc & 0xF0000000u) | target;

  switch (opcode) {
  case 0x02: // j
    regs_.next_pc = new_pc;
    break;
  case 0x03: // jal
    setReg(31, current_pc + 8);
    regs_.next_pc = new_pc;
    break;
  default:
    illegalInstruction(instr);
    break;
  }
}

void MipsCpu::handleIType(u32 instr, u64 current_pc) {
  const u32 opcode = (instr >> 26) & 0x3F;
  const u32 rs = (instr >> 21) & 0x1F;
  const u32 rt = (instr >> 16) & 0x1F;
  const u32 imm = instr & 0xFFFFu;
  const i32 simm = static_cast<i32>(signExtend16(imm));

  switch (opcode) {
  case 0x04: // beq
    if (getReg(rs) == getReg(rt)) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x05: // bne
    if (getReg(rs) != getReg(rt)) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x06: // blez
    if (static_cast<i32>(getReg(rs)) <= 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x07: // bgtz
    if (static_cast<i32>(getReg(rs)) > 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x14: // beql
    if (getReg(rs) == getReg(rt)) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    } else {
      regs_.pc = regs_.next_pc;
      regs_.next_pc = regs_.pc + 4;
    }
    break;
  case 0x15: // bnel
    if (getReg(rs) != getReg(rt)) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    } else {
      regs_.pc = regs_.next_pc;
      regs_.next_pc = regs_.pc + 4;
    }
    break;
  case 0x08: // addi
    setReg(rt, getReg(rs) + static_cast<u32>(simm));
    break;
  case 0x09: // addiu
    setReg(rt, getReg(rs) + static_cast<u32>(simm));
    break;
  case 0x0A: // slti
    setReg(rt, (static_cast<i32>(getReg(rs)) < simm) ? 1u : 0u);
    break;
  case 0x0B: // sltiu
    setReg(rt, (getReg(rs) < static_cast<u32>(simm)) ? 1u : 0u);
    break;
  case 0x0C: // andi
    setReg(rt, getReg(rs) & imm);
    break;
  case 0x0D: // ori
    setReg(rt, getReg(rs) | imm);
    break;
  case 0x0E: // xori
    setReg(rt, getReg(rs) ^ imm);
    break;
  case 0x0F: // lui (MIPS III: sign-extend the 32-bit result to 64 bits)
    setReg(rt, static_cast<u64>(static_cast<i32>(imm << 16)));
    break;
  case 0x20: // lb
    setReg(rt, static_cast<u32>(static_cast<i32>(static_cast<i8>(
                   memory_.read8(getReg(rs) + static_cast<u32>(simm))))));
    break;
  case 0x21: // lh
    setReg(rt, static_cast<u32>(static_cast<i32>(static_cast<i16>(
                   memory_.read16(getReg(rs) + static_cast<u32>(simm))))));
    break;
  case 0x22: // lwl
  {
    const u32 addr = getReg(rs) + static_cast<u32>(simm);
    const u32 aligned = addr & ~3u;
    const u32 word = memory_.read32(aligned);
    const u32 mask = (0xFFFFFFFFu >> ((addr & 3u) * 8u));
    setReg(rt, (getReg(rt) & ~mask) | (word << ((addr & 3u) * 8u)));
  } break;
  case 0x23: // lw
    setReg(rt, memory_.read32(getReg(rs) + static_cast<u32>(simm)));
    break;
  case 0x24: // lbu
    setReg(rt, memory_.read8(getReg(rs) + static_cast<u32>(simm)));
    break;
  case 0x25: // lhu
    setReg(rt, memory_.read16(getReg(rs) + static_cast<u32>(simm)));
    break;
  case 0x26: // lwr
  {
    const u32 addr = getReg(rs) + static_cast<u32>(simm);
    const u32 aligned = addr & ~3u;
    const u32 word = memory_.read32(aligned);
    const u32 shift = (addr & 3u) * 8u;
    setReg(rt, (getReg(rt) & (0xFFFFFFFFu << (32u - shift))) |
                   (word >> (24u - shift)));
  } break;
  case 0x28: // sb
    memory_.write8(getReg(rs) + static_cast<u32>(simm),
                   static_cast<u8>(getReg(rt) & 0xFFu));
    break;
  case 0x29: // sh
    memory_.write16(getReg(rs) + static_cast<u32>(simm),
                    static_cast<u16>(getReg(rt) & 0xFFFFu));
    break;
  case 0x2A: // swl
  {
    const u32 addr = getReg(rs) + static_cast<u32>(simm);
    const u32 aligned = addr & ~3u;
    const u32 word = memory_.read32(aligned);
    const u32 shift = (addr & 3u) * 8u;
    memory_.write32(aligned, (word & (0xFFFFFFFFu << (shift + 8u))) |
                                 ((getReg(rt) >> (24u - shift)) & 0xFFu));
  } break;
  case 0x2B: // sw
    memory_.write32(getReg(rs) + static_cast<u32>(simm), getReg(rt));
    break;
  case 0x2E: // swr
  {
    const u32 addr = getReg(rs) + static_cast<u32>(simm);
    const u32 aligned = addr & ~3u;
    const u32 word = memory_.read32(aligned);
    const u32 shift = (addr & 3u) * 8u;
    memory_.write32(aligned, (word & (0xFFFFFFFFu >> (32u - shift))) |
                                 ((getReg(rt) << (24u - shift)) & 0xFFFFFFFFu));
  } break;
  case 0x2F: // cache / pref: no-op in early PROM boot and warm startup paths
    break;
  case 0x30: // ll
    setReg(rt, memory_.read32(getReg(rs) + static_cast<u32>(simm)));
    break;
  case 0x31: // lwc1 / no-op stub
    break;
  case 0x32: // lwc2 / no-op stub
    break;
  case 0x33: // ldc1 / no-op stub
    break;
  case 0x34: // lwc3 / no-op stub
    break;
  case 0x35: // ldc2 / no-op stub
    break;
  case 0x36: // swc1 / no-op stub
    break;
  case 0x37: // swc2 / no-op stub
    break;
  case 0x38: // sc
    memory_.write32(getReg(rs) + static_cast<u32>(simm), getReg(rt));
    setReg(rt, 1u);
    break;
  default:
    illegalInstruction(instr);
    break;
  }
}

void MipsCpu::handleRegimmType(u32 instr, u64 current_pc) {
  const u32 rs = (instr >> 21) & 0x1Fu;
  const u32 rt = (instr >> 16) & 0x1Fu;
  const i32 simm = static_cast<i32>(signExtend16(instr & 0xFFFFu));

  switch (rt) {
  case 0x00: // bltz
    if (static_cast<i32>(getReg(rs)) < 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x01: // bgez
    if (static_cast<i32>(getReg(rs)) >= 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x02: // bltzl
    if (static_cast<i32>(getReg(rs)) < 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    } else {
      regs_.pc = regs_.next_pc;
      regs_.next_pc = regs_.pc + 4;
    }
    break;
  case 0x03: // bgezl
    if (static_cast<i32>(getReg(rs)) >= 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    } else {
      regs_.pc = regs_.next_pc;
      regs_.next_pc = regs_.pc + 4;
    }
    break;
  case 0x10: // bltzal
    setReg(31, current_pc + 8);
    if (static_cast<i32>(getReg(rs)) < 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x11: // bgezal
    setReg(31, current_pc + 8);
    if (static_cast<i32>(getReg(rs)) >= 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
    break;
  case 0x12: // bltzall
    setReg(31, current_pc + 8);
    if (static_cast<i32>(getReg(rs)) < 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    } else {
      regs_.pc = regs_.next_pc;
      regs_.next_pc = regs_.pc + 4;
    }
    break;
  case 0x13: // bgezall
    setReg(31, current_pc + 8);
    if (static_cast<i32>(getReg(rs)) >= 0) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    } else {
      regs_.pc = regs_.next_pc;
      regs_.next_pc = regs_.pc + 4;
    }
    break;
  default:
    illegalInstruction(instr);
    break;
  }
}

void MipsCpu::handleCop1Type(u32 instr, u64 current_pc) {
  const u32 fmt = (instr >> 21) & 0x1Fu;
  const u32 rt = (instr >> 16) & 0x1Fu;
  const i32 simm = static_cast<i32>(signExtend16(instr & 0xFFFFu));

  switch (fmt) {
  case 0x00: // MFC1 / BCF1-like moves
    break;
  case 0x04: // MTC1
    break;
  case 0x08: // BC1
  {
    const bool taken =
        (rt & 0x01u) != 0u ? regs_.fpu_condition : !regs_.fpu_condition;
    if (taken) {
      regs_.next_pc = current_pc + 4 + (simm << 2);
    }
  } break;
  case 0x10:
  case 0x11:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
    // Generic COP1 arithmetic / comparison instructions are ignored for the
    // PROM boot path.
    break;
  default:
    break;
  }
}

void MipsCpu::handleCop0Type(u32 instr, u64 current_pc) {
  const u32 rs = (instr >> 21) & 0x1Fu;
  const u32 rt = (instr >> 16) & 0x1Fu;
  const u32 rd = (instr >> 11) & 0x1Fu;
  const u32 sel = instr & 0x7u;

  switch (rs) {
  case 0x00: // MFC0
    setReg(rt, regs_.cop0[rd]);
    break;
  case 0x04: // MTC0
    regs_.cop0[rd] = getReg(rt);
    break;
  case 0x08: // BC0
  {
    const i32 offset = static_cast<i32>(static_cast<i16>(instr & 0xFFFFu));
    const bool branch_taken = (regs_.cop0[12] & 0x1u) != 0u;
    if (branch_taken) {
      regs_.next_pc = current_pc + 4 + (offset << 2);
    }
  } break;
  case 0x10: // COP0 special control ops
    switch (sel) {
    case 0x00u: // MFC0/MTC0 (already handled above)
    case 0x01u: // TLBR - Read TLB entry
      memory_.tlb_read(rd);
      break;
    case 0x02u: // TLBWI - Write TLB entry indexed
      memory_.tlb_write(rd);
      break;
    case 0x03u: // RESERVED
      break;
    case 0x04u: // RESERVED
      break;
    case 0x05u: // RESERVED
      break;
    case 0x06u:                                // TLBWR - Write TLB entry random
      memory_.tlb_write(regs_.cop0[1] & 0x3F); // Use Random register
      break;
    case 0x07u: // RESERVED
      break;
    case 0x08u: // TLBP - Probe TLB for matching entry
      memory_.tlb_probe(getReg(rt));
      break;
    default:
      // Handle other COP0 instructions
      if (sel == 0x02u) {
        // ERET:
        // The early Indy PROM uses a simplified flow; leave the status bits
        // as-is.
        break;
      }
      if (sel == 0x00u) {
        break;
      }
      if (sel != 0u) {
        // Some COP0 special cases use sel; treat them as register moves for
        // now.
        setReg(rt, regs_.cop0[rd]);
      } else {
        illegalInstruction(instr);
      }
      break;
    }
    break;
  default:
    if (sel != 0u) {
      // Some COP0 special cases use sel; treat them as register moves for now.
      if (rs == 0x10u) {
        setReg(rt, regs_.cop0[rd]);
      } else {
        illegalInstruction(instr);
      }
    } else {
      illegalInstruction(instr);
    }
    break;
  }
}

void MipsCpu::handleSpecial2(u32 instr, u64 current_pc) {
  const u32 funct = instr & 0x3Fu;
  const u32 rs = (instr >> 21) & 0x1F;
  const u32 rt = (instr >> 16) & 0x1F;
  const u32 rd = (instr >> 11) & 0x1F;

  switch (funct) {
  case 0x00: // madd
  {
    const u64 lhs = (static_cast<u64>(regs_.hi) << 32) | regs_.lo;
    const u64 rhs =
        static_cast<u64>(static_cast<i64>(static_cast<i32>(getReg(rs))) *
                         static_cast<i64>(static_cast<i32>(getReg(rt))));
    const u64 result = lhs + rhs;
    regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
    regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
  } break;
  case 0x01: // maddu
  {
    const u64 lhs = (static_cast<u64>(regs_.hi) << 32) | regs_.lo;
    const u64 rhs = static_cast<u64>(getReg(rs)) * static_cast<u64>(getReg(rt));
    const u64 result = lhs + rhs;
    regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
    regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
  } break;
  case 0x02: // mul
    setReg(rd,
           static_cast<u32>(static_cast<i64>(static_cast<i32>(getReg(rs))) *
                            static_cast<i64>(static_cast<i32>(getReg(rt)))));
    break;
  case 0x04: // msub
  {
    const u64 lhs = (static_cast<u64>(regs_.hi) << 32) | regs_.lo;
    const u64 rhs =
        static_cast<u64>(static_cast<i64>(static_cast<i32>(getReg(rs))) *
                         static_cast<i64>(static_cast<i32>(getReg(rt))));
    const u64 result = lhs - rhs;
    regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
    regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
  } break;
  case 0x05: // msubu
  {
    const u64 lhs = (static_cast<u64>(regs_.hi) << 32) | regs_.lo;
    const u64 rhs = static_cast<u64>(getReg(rs)) * static_cast<u64>(getReg(rt));
    const u64 result = lhs - rhs;
    regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
    regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
  } break;
  case 0x20: // clz
  {
    u32 value = getReg(rs);
    u32 count = 0;
    while (value && (value & 0x80000000u) == 0) {
      ++count;
      value <<= 1;
    }
    setReg(rd, count);
  } break;
  case 0x21: // clo
  {
    u32 value = ~getReg(rs);
    u32 count = 0;
    while (value && (value & 0x80000000u) == 0) {
      ++count;
      value <<= 1;
    }
    setReg(rd, count);
  } break;
  default:
    illegalInstruction(instr);
    break;
  }
}

void MipsCpu::handleSpecial3(u32 instr, u64 current_pc) {
  const u32 funct = instr & 0x3Fu;
  const u32 rs = (instr >> 21) & 0x1F;
  const u32 rt = (instr >> 16) & 0x1F;
  const u32 rd = (instr >> 11) & 0x1F;
  const u32 sa = (instr >> 6) & 0x1F;

  switch (funct) {
  case 0x00: // ext
  {
    const u32 pos = (instr >> 11) & 0x1Fu;
    const u32 size = ((instr >> 6) & 0x1Fu) + 1u;
    const u32 mask = (size >= 32u) ? 0xFFFFFFFFu : ((1u << size) - 1u);
    setReg(rt, (getReg(rs) >> pos) & mask);
  } break;
  case 0x04: // ins
  {
    const u32 pos = (instr >> 11) & 0x1Fu;
    const u32 size = ((instr >> 6) & 0x1Fu) + 1u;
    const u32 mask = (size >= 32u) ? 0xFFFFFFFFu : ((1u << size) - 1u);
    const u32 src = getReg(rt);
    const u32 dest = getReg(rs);
    const u32 value = (src & mask) << pos;
    setReg(rs, (dest & ~(mask << pos)) | value);
  } break;
  case 0x20:
    switch (sa) {
    case 0x02: // wsbh
    {
      const u32 value = getReg(rt);
      setReg(rd, ((value & 0x00FF00FFu) << 8) | ((value & 0xFF00FF00u) >> 8));
    } break;
    case 0x10: // seb
      setReg(rd, static_cast<u32>(
                     static_cast<i32>(static_cast<i8>(getReg(rt) & 0xFFu))));
      break;
    case 0x18: // seh
      setReg(rd, static_cast<u32>(
                     static_cast<i32>(static_cast<i16>(getReg(rt) & 0xFFFFu))));
      break;
    default:
      illegalInstruction(instr);
      break;
    }
    break;
  default:
    illegalInstruction(instr);
    break;
  }
}

} // namespace indyemu
