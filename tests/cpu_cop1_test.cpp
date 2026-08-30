#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <cassert>
#include <iostream>

int main() {
    indyemu::Memory mem;
    indyemu::MipsCpu cpu(mem);

    cpu.registers().pc = 0x80000000u;
    cpu.registers().next_pc = 0x80000004u;
    mem.write32(0x80000000u, 0x45010004u);
    cpu.registers().fpu_condition = true;

    cpu.step();
    assert(cpu.registers().next_pc == 0x80000014u);

    std::cout << "cpu cop1 branch ok\n";
    return 0;
}
