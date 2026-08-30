#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <cassert>
#include <cstdint>

int main() {
    indyemu::Memory mem;
    indyemu::MipsCpu cpu(mem);

    const indyemu::u32 bgezl_instr = 0x04000003u; // BGEZL $zero, +1 with rs=0, rt=3
    mem.write32(0xBFC00000u, bgezl_instr);
    cpu.reset();
    cpu.step();

    const auto& regs = cpu.registers();
    if (regs.pc != 0xBFC00004u || regs.next_pc != 0xBFC00008u) {
        return 1;
    }

    indyemu::Memory mem2;
    indyemu::MipsCpu cpu2(mem2);
    cpu2.registers().gpr[8] = 0xFFFFFFFFu;
    const indyemu::u32 bltzl_instr = 0x05000001u; // BLTZL $8, +1 with rs=8, rt=2 (opcode 0x01, rt=2)
    mem2.write32(0xBFC00000u, bltzl_instr);
    cpu2.step();
    if (cpu2.registers().pc != 0xBFC00004u || cpu2.registers().next_pc != 0xBFC00008u) {
        return 2;
    }

    return 0;
}
