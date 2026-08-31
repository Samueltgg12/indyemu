#include "io/eeprom_93c56.hpp"

#include <fstream>

namespace indyemu {

Eeprom93c56::Eeprom93c56() {
    reset();
}

void Eeprom93c56::reset() {
    // Erased state is all-ones.
    data_.fill(0xFFFFu);
    cs_ = false;
    sck_ = false;
    di_ = false;
    do_ = true;
    state_ = State::kIdle;
    shift_ = 0;
    bitCount_ = 0;
    opcode_ = 0;
    address_ = 0;
    writeEnabled_ = false;
}

void Eeprom93c56::setChipSelect(bool cs) {
    if (cs_ == cs) {
        return;
    }
    cs_ = cs;
    if (cs_) {
        // CS rising: begin a new instruction cycle.
        state_ = State::kIdle;
        shift_ = 0;
        bitCount_ = 0;
    } else {
        // CS falling: terminate the cycle. Writes/erases commit here
        // (self-timed write completes instantly in this model).
        if (state_ == State::kWriteData && bitCount_ >= 16 && writeEnabled_) {
            commitWrite();
        } else if (state_ == State::kIdle && opcode_ == kOpErase && writeEnabled_) {
            data_[address_ & 0x7Fu] = 0xFFFFu;
        }
        state_ = State::kIdle;
        do_ = true;  // ready
    }
}

void Eeprom93c56::setClock(bool sck) {
    const bool rising = !sck_ && sck;
    sck_ = sck;
    if (rising && cs_) {
        onClockRise();
    }
}

void Eeprom93c56::setDataIn(bool di) {
    di_ = di;
}

void Eeprom93c56::onClockRise() {
    switch (state_) {
        case State::kIdle:
            // Wait for the start bit (a '1' on DI).
            if (di_) {
                state_ = State::kOpcode;
                shift_ = 0;
                bitCount_ = 0;
            }
            break;

        case State::kOpcode:
            // Shift in 2 opcode bits + 7 address bits (9 total), MSB first.
            shift_ = static_cast<u16>((shift_ << 1) | (di_ ? 1u : 0u));
            ++bitCount_;
            if (bitCount_ == 9) {
                opcode_ = static_cast<u8>((shift_ >> 7) & 0x3u);
                address_ = static_cast<u8>(shift_ & 0x7Fu);
                switch (opcode_) {
                    case kOpRead:
                        // Dummy 0 on DO for the first clock, then 16 data bits.
                        state_ = State::kReadData;
                        shift_ = data_[address_ & 0x7Fu];
                        bitCount_ = 0;
                        do_ = false;
                        break;
                    case kOpWrite:
                        state_ = State::kWriteData;
                        shift_ = 0;
                        bitCount_ = 0;
                        break;
                    case kOpErase:
                        // Commits on CS falling edge.
                        state_ = State::kIdle;
                        break;
                    default:  // kOpControl
                        executeControl(address_);
                        state_ = State::kIdle;
                        break;
                }
            }
            break;

        case State::kReadData:
            if (bitCount_ == 0) {
                // First clock after the address outputs the dummy 0 bit.
                do_ = false;
                bitCount_ = 1;
            } else {
                // Present current MSB, then advance. After 16 data bits,
                // sequential read continues with the next address (no new
                // dummy bit). See FM93CS56 sequential read timing.
                do_ = (shift_ & 0x8000u) != 0;
                shift_ = static_cast<u16>(shift_ << 1);
                ++bitCount_;
                if (bitCount_ == 17) {
                    address_ = static_cast<u8>((address_ + 1u) & 0x7Fu);
                    shift_ = data_[address_];
                    bitCount_ = 1;
                }
            }
            break;

        case State::kWriteData:
            shift_ = static_cast<u16>((shift_ << 1) | (di_ ? 1u : 0u));
            ++bitCount_;
            break;
    }
}

void Eeprom93c56::executeControl(u8 address) {
    // Control instructions are selected by the top two address bits.
    switch ((address >> 5) & 0x3u) {
        case 0x0:  // EWDS: erase/write disable
            writeEnabled_ = false;
            break;
        case 0x1:  // WRAL: write all words with the 16 data bits that follow
            // Not commonly used by the PROM; treat as unsupported no-op.
            break;
        case 0x2:  // ERAL: erase entire array
            if (writeEnabled_) {
                data_.fill(0xFFFFu);
            }
            break;
        case 0x3:  // EWEN: erase/write enable
            writeEnabled_ = true;
            break;
    }
}

void Eeprom93c56::commitWrite() {
    data_[address_ & 0x7Fu] = shift_;
}

bool Eeprom93c56::loadFromFile(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        return false;
    }
    for (std::size_t i = 0; i < kNumWords; ++i) {
        char bytes[2] = {0, 0};
        if (!in.read(bytes, 2)) {
            return false;
        }
        data_[i] = static_cast<u16>((static_cast<u8>(bytes[0]) << 8) |
                                    static_cast<u8>(bytes[1]));
    }
    return true;
}

bool Eeprom93c56::saveToFile(const std::string& path) const {
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) {
        return false;
    }
    for (std::size_t i = 0; i < kNumWords; ++i) {
        const char bytes[2] = {static_cast<char>((data_[i] >> 8) & 0xFFu),
                               static_cast<char>(data_[i] & 0xFFu)};
        if (!out.write(bytes, 2)) {
            return false;
        }
    }
    return true;
}

} // namespace indyemu
