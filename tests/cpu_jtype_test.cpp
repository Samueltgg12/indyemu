#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <cstdio>
#include <fstream>
#include <string>

int main() {
    const std::string prom_path = "./test_prom.bin";
    std::ofstream out(prom_path, std::ios::binary);
    const unsigned char prom[] = {0x0b, 0xf0, 0x00, 0xf0, 0x0b, 0xf0, 0x01, 0xed};
    out.write(reinterpret_cast<const char*>(prom), sizeof(prom));
    out.close();

    indyemu::Memory mem;
    if (!mem.loadProm(prom_path)) {
        std::fprintf(stderr, "failed to load test PROM\n");
        return 2;
    }

    indyemu::MipsCpu cpu(mem);
    cpu.step();

    const auto regs = cpu.registers();
    const indyemu::u32 expected = 0xBFC003C0u; // decoded J target for 0x0bf000f0
    if (regs.next_pc != expected) {
        std::fprintf(stderr, "J-type decode failed: next_pc=0x%08x expected=0x%08x\n", regs.next_pc, expected);
        std::remove(prom_path.c_str());
        return 1;
    }

    std::remove(prom_path.c_str());
    return 0;
}
