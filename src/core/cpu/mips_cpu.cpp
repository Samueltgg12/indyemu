#include "core/cpu/mips_cpu.hpp"

namespace indyemu {

MipsCpu::MipsCpu(Memory& memory) : memory_(memory) {
    reset();
}

void MipsCpu::reset() {
    regs_.gpr.fill(0);
    regs_.cop0.fill(0);
    regs_.hi = 0;
    regs_.lo = 0;
    regs_.pc = kInitialPc;
    regs_.next_pc = kInitialPc + 4;
}

u32 MipsCpu::fetchInstruction() const {
    return memory_.read32(regs_.pc);
}

void MipsCpu::setReg(u32 index, u32 value) {
    if (index != 0) {
        regs_.gpr[index] = value;
    }
}

u32 MipsCpu::getReg(u32 index) const {
    return regs_.gpr[index];
}

bool MipsCpu::step() {
    const u32 current_pc = regs_.pc;
    const u32 instr = fetchInstruction();
    regs_.pc = regs_.next_pc;
    regs_.next_pc = regs_.pc + 4;

    executeInstruction(instr, current_pc);
    return true;
}

void MipsCpu::dumpState() const {
    std::cout << "PC=0x" << std::hex << regs_.pc << " NextPC=0x" << regs_.next_pc << "\n";
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
    std::cerr << "Illegal instruction at PC 0x" << std::hex << regs_.pc << ": 0x" << instr << "\n";
}

void MipsCpu::executeInstruction(u32 instr, u32 current_pc) {
    const u32 op = (instr >> 26) & 0x3Fu;

    switch (op) {
        case 0x00:
            handleRType(instr, current_pc);
            break;
        case 0x01:
            handleCop0Type(instr, current_pc);
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
        case 0x1C:
            handleSpecial2(instr, current_pc);
            break;
        default:
            illegalInstruction(instr);
            break;
    }
}

void MipsCpu::handleRType(u32 instr, u32 current_pc) {
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
        case 0x04: // sllv
            setReg(rd, getReg(rt) << (getReg(rs) & 0x1F));
            break;
        case 0x06: // srlv
            setReg(rd, getReg(rt) >> (getReg(rs) & 0x1F));
            break;
        case 0x07: // srav
            setReg(rd, static_cast<u32>(static_cast<i32>(getReg(rt)) >> (getReg(rs) & 0x1F)));
            break;
        case 0x08: // jr
            regs_.next_pc = getReg(rs);
            break;
        case 0x09: // jalr
            setReg(rd == 0 ? 31 : rd, regs_.pc + 8);
            regs_.next_pc = getReg(rs);
            break;
        case 0x0C: // syscall
            std::cout << "System call encountered (instruction 0x" << std::hex << instr << ")\n";
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
                const u64 result = static_cast<u64>(static_cast<i64>(static_cast<i32>(getReg(rs))) * static_cast<i64>(static_cast<i32>(getReg(rt))));
                regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
                regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
            }
            break;
        case 0x19: // multu
            {
                const u64 result = static_cast<u64>(getReg(rs)) * static_cast<u64>(getReg(rt));
                regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
                regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
            }
            break;
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
            setReg(rd, (static_cast<i32>(getReg(rs)) < static_cast<i32>(getReg(rt))) ? 1u : 0u);
            break;
        case 0x2B: // sltu
            setReg(rd, (getReg(rs) < getReg(rt)) ? 1u : 0u);
            break;
        default:
            illegalInstruction(instr);
            break;
    }
}

void MipsCpu::handleJType(u32 instr, u32 current_pc) {
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

void MipsCpu::handleIType(u32 instr, u32 current_pc) {
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
        case 0x0F: // lui
            setReg(rt, imm << 16);
            break;
        case 0x20: // lb
            setReg(rt, static_cast<u32>(static_cast<i32>(static_cast<i8>(memory_.read8(getReg(rs) + static_cast<u32>(simm))))));
            break;
        case 0x21: // lh
            setReg(rt, static_cast<u32>(static_cast<i32>(static_cast<i16>(memory_.read16(getReg(rs) + static_cast<u32>(simm))))));
            break;
        case 0x23: // lw
            setReg(rt, memory_.read32(getReg(rs) + static_cast<u32>(simm)));
            break;
        case 0x24: // lbu
            setReg(rt, memory_.read8(getReg(rs) + static_cast<u32>(simm)));
            break;
        case 0x25: // lhu
            setReg(rt, memory_.read16(getReg(rs) + static_cast<u32>(simm)));
            break;
        case 0x28: // sb
            memory_.write8(getReg(rs) + static_cast<u32>(simm), static_cast<u8>(getReg(rt) & 0xFFu));
            break;
        case 0x29: // sh
            memory_.write16(getReg(rs) + static_cast<u32>(simm), static_cast<u16>(getReg(rt) & 0xFFFFu));
            break;
        case 0x2B: // sw
            memory_.write32(getReg(rs) + static_cast<u32>(simm), getReg(rt));
            break;
        default:
            illegalInstruction(instr);
            break;
    }
}

void MipsCpu::handleCop0Type(u32 instr, u32 current_pc) {
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

void MipsCpu::handleSpecial2(u32 instr, u32 current_pc) {
    const u32 funct = instr & 0x3Fu;
    const u32 rs = (instr >> 21) & 0x1F;
    const u32 rt = (instr >> 16) & 0x1F;
    const u32 rd = (instr >> 11) & 0x1F;

    switch (funct) {
        case 0x00: // madd
            {
                const u64 lhs = (static_cast<u64>(regs_.hi) << 32) | regs_.lo;
                const u64 rhs = static_cast<u64>(static_cast<i64>(static_cast<i32>(getReg(rs))) * static_cast<i64>(static_cast<i32>(getReg(rt))));
                const u64 result = lhs + rhs;
                regs_.lo = static_cast<u32>(result & 0xFFFFFFFFULL);
                regs_.hi = static_cast<u32>((result >> 32) & 0xFFFFFFFFULL);
            }
            break;
        case 0x03: // clz
            {
                u32 value = getReg(rs);
                u32 count = 0;
                while (value && (value & 0x80000000u) == 0) {
                    ++count;
                    value <<= 1;
                }
                setReg(rd, count);
            }
            break;
        default:
            illegalInstruction(instr);
            break;
    }
}

}  // namespace indyemu
