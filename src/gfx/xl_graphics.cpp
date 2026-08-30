#include "gfx/xl_graphics.hpp"

#include <iostream>

namespace indyemu {

XLGraphics::XLGraphics() {
    reset();
}

void XLGraphics::reset() {
    regs_.fill(0);
    frame_buffer_.fill(0);
    enabled_ = true;
    std::cout << "[gfx] XL graphics reset\n";
}

u32 XLGraphics::read32(u32 offset) const {
    const std::size_t index = offset / 4u;
    if (index < regs_.size()) {
        return regs_[index];
    }
    return 0u;
}

void XLGraphics::write32(u32 offset, u32 value) {
    const std::size_t index = offset / 4u;
    if (index >= regs_.size()) {
        return;
    }

    regs_[index] = value;

    if (offset == 0x00u) {
        enabled_ = (value != 0u);
    }
}

}  // namespace indyemu
