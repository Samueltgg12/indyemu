#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <cassert>
#include <cstdint>

int main() {
    indyemu::Memory mem;
    indyemu::MipsCpu cpu(mem);

    // beq $zero, $zero, +1 (target = current_pc + 8)
    const indyemu::u32 beq_instr = 0x10000001u;
    mem.write32(0xBFC00000u, beq_instr);

    const bool stepped = cpu.step();
    if (!stepped) {
        return 1;
    }

    const auto& regs = cpu.registers();
    if (regs.pc != 0xBFC00004u) {
        return 2;
    }
    if (regs.next_pc != 0xBFC00008u) {
        return 3;
    }

    return 0;
}
