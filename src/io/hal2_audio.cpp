#include "io/hal2_audio.hpp"

#include <iostream>

namespace indyemu {

Hal2Audio::Hal2Audio() {
    reset();
}

void Hal2Audio::reset() {
    regs_.fill(0);
    status_ = 0;
    volume_ = 0;
    control_ = 0;
}

u32 Hal2Audio::read32(u32 offset) const {
    const std::size_t index = offset / 4u;
    if (index < regs_.size()) {
        return regs_[index];
    }
    return 0;
}

void Hal2Audio::write32(u32 offset, u32 value) {
    const std::size_t index = offset / 4u;
    if (index >= regs_.size()) {
        return;
    }

    regs_[index] = value;

    switch (offset) {
        case 0x00:
            control_ = value;
            if (value != 0u) {
                triggerStartupTone();
            }
            break;
        case 0x04:
            volume_ = value;
            break;
        case 0x08:
            status_ = value;
            break;
        default:
            break;
    }
}

void Hal2Audio::triggerStartupTone() {
    if (!enabled_) {
        return;
    }
    status_ = 1u;
    std::cout << "[hal2] PROM startup tone triggered\n";
}

}  // namespace indyemu
