#include "core/memory.hpp"

#include <cstdio>
#include <fstream>
#include <string>

int main() {
    const std::string path = "./test_prom.bin";
    std::ofstream out(path, std::ios::binary);
    const unsigned char bytes[] = {0x0b, 0xf0, 0x00, 0xf0};
    out.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
    out.close();

    indyemu::Memory mem;
    if (!mem.loadProm(path)) {
        std::fprintf(stderr, "failed to load test PROM\n");
        return 2;
    }

    const indyemu::u32 value = mem.read32(0x1fc00000u);
    if (value != 0x0bf000f0u) {
        std::fprintf(stderr, "endian mismatch: got 0x%08x expected 0x%08x\n", value, 0x0bf000f0u);
        return 1;
    }

    std::remove(path.c_str());
    return 0;
}
