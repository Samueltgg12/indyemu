#include "core/memory.hpp"
#include "core/indy_system.hpp"

#include <cassert>
#include <cstdint>

int main() {
    // Build a full system so the VINO device is registered on the bus.
    indyemu::IndySystem sys;
    sys.reset();
    indyemu::Memory& mem = sys.memory();

    // The EISA I/O region must be classified as I/O, not RAM.
    assert(mem.regionForAddress(0x00080000u) == indyemu::Memory::Region::kIo);
    assert(mem.regionName(0x00080000u) == std::string("I/O"));

    // Rev/ID register (offset 0x0000) reads back the VINO ID/revision.
    const uint32_t rev_id = mem.read32(0x00080000u);
    assert((rev_id & 0xF0u) == 0xB0u); // VINO ID value B in bits 7:4

    // A read/write register round-trips through the bus.
    const uint32_t control_addr = 0x00080008u; // CONTROL register
    mem.write32(control_addr, 0xDEADBEEFu);
    assert(mem.read32(control_addr) == 0xDEADBEEFu);

    // A channel register round-trips as well.
    const uint32_t chb_alpha = 0x000800B0u; // CHB_ALPHA
    mem.write32(chb_alpha, 0x12345678u);
    assert(mem.read32(chb_alpha) == 0x12345678u);

    return 0;
}