// src/gfx/xl_graphics.hpp
#pragma once

#include "core/common.hpp"

#include <array>
#include <cstdint>

namespace indyemu {

class XLGraphics {
public:
    static constexpr u32 kBase = 0x1F000000u;
    static constexpr u32 kWidth = 1280u;
    static constexpr u32 kHeight = 1024u;
    static constexpr u32 kBitsPerPixel = 24u;

    XLGraphics();

    void reset();
    u32 read32(u32 offset) const;
    void write32(u32 offset, u32 value);

    bool enabled() const { return enabled_; }
    void setEnabled(bool enabled) { enabled_ = enabled; }

private:
    bool enabled_ = true;
    std::array<u32, 128> regs_{};
    std::array<u32, 128> frame_buffer_{};
};

}  // namespace indyemu
