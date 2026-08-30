#pragma once

#include "core/common.hpp"

#include <array>
#include <cstdint>

namespace indyemu {

class Ioc2Controller {
public:
    static constexpr u32 kBase = 0x1F0D0000u;

    Ioc2Controller();

    void reset();
    u32 read32(u32 offset) const;
    void write32(u32 offset, u32 value);

private:
    std::array<u32, 64> regs_{};
};

}  // namespace indyemu
