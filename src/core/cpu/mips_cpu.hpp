#pragma once

#include "core/common.hpp"
#include "core/memory.hpp"

#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

namespace indyemu {

class MipsCpu {
public:
    static constexpr u32 kInitialPc = 0xBFC00000u;

    struct Registers {
        std::array<u32, 32> gpr{};
        std::array<u32, 32> cop0{};
        bool fpu_condition = false;
        u32 hi = 0;
        u32 lo = 0;
        u32 pc = kInitialPc;
        u32 next_pc = kInitialPc + 4;
    };

    explicit MipsCpu(Memory& memory);

    void reset();
    bool step();
    void dumpState() const;

    Registers& registers() { return regs_; }
    const Registers& registers() const { return regs_; }

private:
    Memory& memory_;
    Registers regs_{};

    u32 fetchInstruction() const;
    void executeInstruction(u32 instr, u32 current_pc);

    void handleRType(u32 instr, u32 current_pc);
    void handleJType(u32 instr, u32 current_pc);
    void handleIType(u32 instr, u32 current_pc);
    void handleRegimmType(u32 instr, u32 current_pc);
    void handleCop0Type(u32 instr, u32 current_pc);
    void handleCop1Type(u32 instr, u32 current_pc);
    void handleSpecial2(u32 instr, u32 current_pc);
    void handleSpecial3(u32 instr, u32 current_pc);

    void setReg(u32 index, u32 value);
    u32 getReg(u32 index) const;

    void illegalInstruction(u32 instr) const;
};

}  // namespace indyemu
