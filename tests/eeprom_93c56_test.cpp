// Test: 93C56 EEPROM MICROWIRE protocol via the MC EEROM register.
// Drives CS/SCK/SO through MemoryController::write32 and reads SI back,
// exactly as the PROM does (hardware-docs/mc.md section 5.6).

#include <cassert>
#include <cstdint>
#include <iostream>

#include "io/eeprom_93c56.hpp"
#include "system/memory_controller.hpp"

using namespace indyemu;

namespace {

constexpr uint32_t kEeromAddr = MemoryController::kBase + MemoryController::EEROM;
constexpr uint32_t kCs  = 1u << 1;
constexpr uint32_t kSck = 1u << 2;
constexpr uint32_t kSo  = 1u << 3;
constexpr uint32_t kSi  = 1u << 4;

void writePins(MemoryController& mc, bool cs, bool sck, bool di) {
    uint32_t value = 0;
    if (cs) value |= kCs;
    if (sck) value |= kSck;
    if (di) value |= kSo;
    mc.write32(kEeromAddr, value);
}

void clockBit(MemoryController& mc, bool di) {
    writePins(mc, true, false, di);
    writePins(mc, true, true, di);
}

// Shift out `bits` bits of `value`, MSB first.
void shiftOut(MemoryController& mc, uint32_t value, int bits) {
    for (int i = bits - 1; i >= 0; --i) {
        clockBit(mc, (value >> i) & 1u);
    }
}

uint16_t eepromRead(MemoryController& mc, uint8_t address) {
    writePins(mc, false, false, false);
    writePins(mc, true, false, false);
    clockBit(mc, true);                       // start bit
    shiftOut(mc, 0x2u, 2);                    // READ opcode (10)
    shiftOut(mc, address, 7);                 // address
    // Skip the dummy 0 bit.
    writePins(mc, true, false, false);
    writePins(mc, true, true, false);
    uint16_t result = 0;
    for (int i = 0; i < 16; ++i) {
        writePins(mc, true, false, false);
        writePins(mc, true, true, false);
        result = static_cast<uint16_t>((result << 1) |
                ((mc.read32(kEeromAddr) & kSi) ? 1u : 0u));
    }
    writePins(mc, false, false, false);
    return result;
}

void eepromWrite(MemoryController& mc, uint8_t address, uint16_t data) {
    // EWEN first.
    writePins(mc, false, false, false);
    writePins(mc, true, false, false);
    clockBit(mc, true);                       // start bit
    shiftOut(mc, 0x0u, 2);                    // control opcode (00)
    shiftOut(mc, 0x60u, 7);                   // address 11xxxxx = EWEN
    writePins(mc, false, false, false);

    // WRITE cycle.
    writePins(mc, true, false, false);
    clockBit(mc, true);                       // start bit
    shiftOut(mc, 0x1u, 2);                    // WRITE opcode (01)
    shiftOut(mc, address, 7);
    shiftOut(mc, data, 16);
    writePins(mc, false, false, false);       // CS drop commits
}

} // namespace

int main() {
    MemoryController mc;
    Eeprom93c56 eeprom;
    mc.attachEeprom(&eeprom);

    // Erased EEPROM reads back 0xFFFF.
    assert(eepromRead(mc, 0x00) == 0xFFFFu);
    assert(eepromRead(mc, 0x7F) == 0xFFFFu);

    // Write a word and read it back through the serial interface.
    eepromWrite(mc, 0x10, 0xBEEFu);
    assert(eepromRead(mc, 0x10) == 0xBEEFu);
    // Neighbouring word untouched.
    assert(eepromRead(mc, 0x11) == 0xFFFFu);

    // Direct accessor agrees with the serial read.
    assert(eeprom.readWord(0x10) == 0xBEEFu);

    std::cout << "eeprom_93c56_test passed\n";
    return 0;
}
