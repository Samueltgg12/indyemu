#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <array>
#include <cassert>
#include <fstream>
#include <string>

int main() {
    const std::string prom_path = "./cop0_test_prom.bin";
    std::ofstream out(prom_path, std::ios::binary);
    const std::array<unsigned char, 12> prom = {
        0x34, 0x02, 0x12, 0x34,  // ori $2, $zero, 0x1234
        0x40, 0x82, 0x60, 0x00,  // mtc0 $2, $12
        0x40, 0x03, 0x60, 0x00,  // mfc0 $3, $12
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

    if (cpu.registers().gpr[3] != 0x00001234u) {
        return 1;
    }

    return 0;
}
