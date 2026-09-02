// src/core/cpu/mips_cpu.hpp
#pragma once

#include "core/common.hpp"
#include "core/memory.hpp"

#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

namespace indyemu {

// Interface for a device that can assert CPU interrupt lines (IP bits).
// The CPU queries this each cycle to decide whether to take an interrupt
// exception.
class InterruptController {
public:
  virtual ~InterruptController() = default;
  // Returns a bitmask of currently-asserted interrupt lines, where bit N
  // corresponds to CPU Cause register IP bit N (e.g. bit 2 = IP2, bit 3 = IP3).
  virtual u32 pendingInterruptLines() const = 0;
};

class MipsCpu {
public:
  static constexpr u32 kInitialPc = 0xBFC00000u;

  // CP0 register indices
  static constexpr u32 kCp0Index = 0;
  static constexpr u32 kCp0Random = 1;
  static constexpr u32 kCp0EntryLo0 = 2;
  static constexpr u32 kCp0EntryLo1 = 3;
  static constexpr u32 kCp0Context = 4;
  static constexpr u32 kCp0PageMask = 5;
  static constexpr u32 kCp0Wired = 6;
  static constexpr u32 kCp0BadVAddr = 8;
  static constexpr u32 kCp0Count = 9;
  static constexpr u32 kCp0EntryHi = 10;
  static constexpr u32 kCp0Compare = 11;
  static constexpr u32 kCp0Status = 12;
  static constexpr u32 kCp0Cause = 13;
  static constexpr u32 kCp0EPC = 14;
  static constexpr u32 kCp0PRId = 15;
  static constexpr u32 kCp0Config = 16;
  static constexpr u32 kCp0LLAddr = 17;
  static constexpr u32 kCp0WatchLo = 18;
  static constexpr u32 kCp0WatchHi = 19;
  static constexpr u32 kCp0XContext = 20;
  static constexpr u32 kCp0ErrorEPC = 30;

  // Status register bit masks
  static constexpr u32 kStatusIE = 0x1u;   // Interrupt Enable
  static constexpr u32 kStatusEXL = 0x2u;  // Exception Level
  static constexpr u32 kStatusERL = 0x4u;  // Error Level
  static constexpr u32 kStatusIMShift = 8; // Interrupt Mask bits 8-15
  static constexpr u32 kStatusIM = 0xFFu << kStatusIMShift;

  // Cause register bit masks
  static constexpr u32 kCauseIPShift = 8; // Interrupt Pending bits 8-15
  static constexpr u32 kCauseIP = 0xFFu << kCauseIPShift;
  static constexpr u32 kCauseExcCodeShift = 2; // Exception code bits 2-6
  static constexpr u32 kCauseExcCode = 0x1Fu << kCauseExcCodeShift;

  // Exception codes
  static constexpr u32 kExcInt = 0;     // Interrupt
  static constexpr u32 kExcTLBMod = 1;  // TLB modification
  static constexpr u32 kExcTLBL = 2;    // TLB load
  static constexpr u32 kExcTLBS = 3;    // TLB store
  static constexpr u32 kExcAdEL = 4;    // Address error load
  static constexpr u32 kExcAdES = 5;    // Address error store
  static constexpr u32 kExcSyscall = 8; // Syscall
  static constexpr u32 kExcBreak = 9;   // Breakpoint
  static constexpr u32 kExcCpU = 11;    // Coprocessor unusable
  static constexpr u32 kExcOv = 12;     // Arithmetic overflow
  static constexpr u32 kExcRI = 10;     // Reserved instruction

  // Exception vector bases
  static constexpr u32 kExceptionBase = 0x80000180u; // General exception vector
  static constexpr u32 kTLBRefillBase = 0x80000000u; // TLB refill vector
  static constexpr u32 kResetVector = 0xBFC00000u;   // Reset vector

  struct Registers {
    std::array<u64, 32> gpr{};
    std::array<u32, 32> cop0{};
    bool fpu_condition = false;
    u64 hi = 0;
    u64 lo = 0;
    u64 pc = kInitialPc;
    u64 next_pc = kInitialPc + 4;
  };

  explicit MipsCpu(Memory &memory);

  void reset();
  bool step();
  void dumpState() const;
  void setTraceEnabled(bool enabled) { trace_enabled_ = enabled; }
  bool traceEnabled() const { return trace_enabled_; }

  void setInterruptController(InterruptController *controller) {
    interrupt_controller_ = controller;
  }

  Registers &registers() { return regs_; }
  const Registers &registers() const { return regs_; }

private:
  Memory &memory_;
  Registers regs_{};
  bool trace_enabled_ = false;
  InterruptController *interrupt_controller_ = nullptr;

  u32 fetchInstruction() const;
  void executeInstruction(u32 instr, u64 current_pc);

  void handleRType(u32 instr, u64 current_pc);
  void handleJType(u32 instr, u64 current_pc);
  void handleIType(u32 instr, u64 current_pc);
  void handleRegimmType(u32 instr, u64 current_pc);
  void handleCop0Type(u32 instr, u64 current_pc);
  void handleCop1Type(u32 instr, u64 current_pc);
  void handleSpecial2(u32 instr, u64 current_pc);
  void handleSpecial3(u32 instr, u64 current_pc);

  void setReg(u32 index, u64 value);
  u64 getReg(u32 index) const;

  void illegalInstruction(u32 instr) const;

  // Exception handling
  void takeException(u32 exc_code, u64 epc, bool in_delay_slot);
  bool checkInterrupts();
  void updateCauseIPBits();
};

} // namespace indyemu
