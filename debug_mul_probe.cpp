#include "src/core/cpu/mips_cpu.hpp"
#include "src/core/memory.hpp"

#include <iostream>

int main() {
    indyemu::Memory mem;
    indyemu::MipsCpu cpu(mem);

    const indyemu::u32 ori1 = 0x34010003u;
    const indyemu::u32 ori2 = 0x34020004u;
    const indyemu::u32 mul_instr = (0x1Cu << 26) | (1u << 21) | (2u << 16) | (3u << 11) | 0x02u;
    mem.write32(0xBFC00000u, ori1);
    mem.write32(0xBFC00004u, ori2);
    mem.write32(0xBFC00008u, mul_instr);

    for (int i = 0; i < 4; ++i) {
        std::cout << "before step " << i << ": pc=0x" << std::hex << cpu.registers().pc
                  << " next=0x" << cpu.registers().next_pc << std::dec << " r1=" << cpu.registers().gpr[1]
                  << " r2=" << cpu.registers().gpr[2] << " r3=" << cpu.registers().gpr[3] << "\n";
        cpu.step();
        std::cout << "after step " << i << ": pc=0x" << std::hex << cpu.registers().pc
                  << " next=0x" << cpu.registers().next_pc << std::dec << " r1=" << cpu.registers().gpr[1]
                  << " r2=" << cpu.registers().gpr[2] << " r3=" << cpu.registers().gpr[3] << "\n";
    }
    return 0;
}
