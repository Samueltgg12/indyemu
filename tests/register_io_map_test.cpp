#include "core/memory.hpp"

#include <cassert>
#include <iostream>

int main() {
    indyemu::Memory mem;

    mem.write32(0x1F0B0000u + 0x08u, 0x12345678u);
    assert(mem.read32(0x1F0B0000u + 0x08u) == 0x12345678u);

    mem.write32(0x1F0D0000u + 0x10u, 0xCAFEBABEu);
    assert(mem.read32(0x1F0D0000u + 0x10u) == 0xCAFEBABEu);

    std::cout << "register io map ok\n";
    return 0;
}
