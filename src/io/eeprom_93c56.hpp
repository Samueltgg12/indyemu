#ifndef INDYEMU_EEPROM_93C56_HPP
#define INDYEMU_EEPROM_93C56_HPP

#include <array>
#include <cstdint>
#include <string>

#include "core/common.hpp"

namespace indyemu {

// 93C56 / FM93CS56 2048-bit serial EEPROM (128 x 16-bit words) with a
// MICROWIRE 4-wire interface (CS, SK, DI, DO). See hardware-docs/FM93CS56.md.
//
// The CPU drives the chip through the MC EEROM register (hardware-docs/mc.md
// section 5.6): software wiggles CS/SCK/SO(DI) and reads back SI(DO).
class Eeprom93c56 {
public:
    static constexpr std::size_t kNumWords = 128;  // 128 x 16-bit = 2048 bits

    Eeprom93c56();

    void reset();

    // Pin interface. The MC calls these when the EEROM register is written.
    void setChipSelect(bool cs);
    void setClock(bool sck);
    void setDataIn(bool di);

    // DO pin state, surfaced through the EEROM register SI bit.
    bool dataOut() const { return do_; }

    // Optional persistence of the EEPROM image (16-bit words, big-endian file).
    bool loadFromFile(const std::string& path);
    bool saveToFile(const std::string& path) const;

    // Direct word access (for tests and tooling).
    u16 readWord(u8 address) const { return data_[address & 0x7Fu]; }
    void writeWord(u8 address, u16 value) { data_[address & 0x7Fu] = value; }

private:
    // MICROWIRE opcodes (2 bits following the start bit).
    enum Opcode : u8 {
        kOpControl = 0x0,  // EWDS / WRAL / ERAL / EWEN selected by address[6:5]
        kOpWrite   = 0x1,
        kOpRead    = 0x2,
        kOpErase   = 0x3,
    };

    enum class State {
        kIdle,        // waiting for start bit
        kOpcode,      // shifting in opcode + address (9 bits)
        kReadData,    // shifting out 16 data bits (then sequential reads)
        kWriteData,   // shifting in 16 data bits
    };

    void onClockRise();
    void executeControl(u8 address);
    void commitWrite();

    std::array<u16, kNumWords> data_{};

    bool cs_ = false;
    bool sck_ = false;
    bool di_ = false;
    bool do_ = true;   // ready/busy: high = ready (writes complete instantly)

    State state_ = State::kIdle;
    u16 shift_ = 0;        // shift register for opcode/address/data
    u32 bitCount_ = 0;     // bits shifted in the current state
    u8 opcode_ = 0;
    u8 address_ = 0;
    bool writeEnabled_ = false;
};

} // namespace indyemu

#endif // INDYEMU_EEPROM_93C56_HPP
