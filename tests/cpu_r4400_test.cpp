#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <array>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>

int main() {
    const std::string prom_path = "./cpu_r4400_test_prom.bin";
    std::ofstream out(prom_path, std::ios::binary);
    const std::array<unsigned char, 16> prom = {
        0x34, 0x01, 0x00, 0x01,  // ori $1, $zero, 1
        0x34, 0x02, 0x00, 0x02,  // ori $2, $zero, 2
        0x00, 0x00, 0x00, 0x0f,  // sync
        0x00, 0x00, 0x00, 0x00   // nop
    };
    out.write(reinterpret_cast<const char*>(prom.data()), prom.size());
    out.close();

    indyemu::Memory mem;
    if (!mem.loadProm(prom_path)) {
        return 2;
    }

    indyemu::MipsCpu cpu(mem);

    // The R4400-era PROM path uses the standard MIPS move/synchronization patterns:
    // - move from HI/LO for arithmetic results
    // - sync / cache / nop-like control instructions
    // This test fails if the decoder emits an illegal-instruction trap on SYNC.
    mem.write32(0xBFC00000u, 0x34010001u);
    mem.write32(0xBFC00004u, 0x34020002u);
    mem.write32(0xBFC00008u, 0x0000000Fu); // sync
    mem.write32(0xBFC0000Cu, 0x00000000u); // nop

    std::stringstream captured;
    auto* original = std::cerr.rdbuf(captured.rdbuf());
    cpu.reset();
    cpu.step();
    cpu.step();
    cpu.step();
    cpu.step();
    cpu.step();
    std::cerr.rdbuf(original);

    const auto& regs = cpu.registers();
    if (regs.gpr[1] != 1u || regs.gpr[2] != 2u) {
        return 1;
    }
    if (!captured.str().empty()) {
        std::fprintf(stderr, "unexpected illegal instruction output: %s\n", captured.str().c_str());
        return 3;
    }

    std::remove(prom_path.c_str());
    return 0;
}
