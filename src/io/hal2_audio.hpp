#pragma once

#include "core/common.hpp"

#include <array>
#include <cstdint>

namespace indyemu {

class Hal2Audio {
public:
    static constexpr u32 kBase = 0x1F0B0000u;

    Hal2Audio();

    void reset();
    u32 read32(u32 offset) const;
    void write32(u32 offset, u32 value);

    bool enabled() const { return enabled_; }
    void setEnabled(bool enabled) { enabled_ = enabled; }

    void triggerStartupTone();

private:
    bool enabled_ = true;
    std::array<u32, 32> regs_{};
    u32 status_ = 0;
    u32 volume_ = 0;
    u32 control_ = 0;
};

}  // namespace indyemu
