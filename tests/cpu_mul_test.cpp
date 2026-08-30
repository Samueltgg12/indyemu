#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <array>
#include <cassert>
#include <cstdint>
#include <fstream>
#include <string>

int main() {
    const std::string prom_path = "./cpu_mul_test_prom.bin";
    std::ofstream out(prom_path, std::ios::binary);
    const std::array<unsigned char, 12> prom = {
        0x34, 0x01, 0x00, 0x03,  // ori $1, $zero, 3
        0x34, 0x02, 0x00, 0x04,  // ori $2, $zero, 4
        0x7c, 0x02, 0x00, 0x02,  // mul $3, $1, $2 (opcode 0x1c, funct 0x02)
    };
    out.write(reinterpret_cast<const char*>(prom.data()), prom.size());
    out.close();

    indyemu::Memory mem;
    if (!mem.loadProm(prom_path)) {
        return 2;
    }

    indyemu::MipsCpu cpu(mem);
    cpu.step();
    cpu.step();
    cpu.step();

    if (cpu.registers().gpr[3] != 12u) {
        return 1;
    }

    return 0;
}
