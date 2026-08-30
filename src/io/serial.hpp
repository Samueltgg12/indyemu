#pragma once

#include "core/common.hpp"

#include <array>
#include <cstdint>

namespace indyemu {

class SerialPort {
public:
    SerialPort();

    void reset();
    void writeByte(u8 value);
    u8 readByte();
    bool hasData() const;

private:
    std::array<u8, 256> fifo_{};
    std::size_t head_ = 0;
    std::size_t tail_ = 0;
    std::size_t count_ = 0;
};

}  // namespace indyemu
