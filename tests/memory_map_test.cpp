#include "core/memory.hpp"

#include <cassert>

int main() {
    indyemu::Memory mem;

    // SGI Indy PROM and RAM must live in the correct windows.
    assert(mem.regionForAddress(0xBFC00000u) == indyemu::Memory::Region::kProm);
    assert(mem.regionForAddress(0x80000000u) == indyemu::Memory::Region::kRam);
    assert(mem.regionForAddress(0x1F000000u) == indyemu::Memory::Region::kIo);

    // The explicit MIPS reset vector lands in PROM.
    assert(mem.regionName(0xBFC00000u) == std::string("PROM"));
    assert(mem.regionName(0x80000000u) == std::string("RAM"));
    assert(mem.regionName(0x1F000000u) == std::string("I/O"));

    return 0;
}
