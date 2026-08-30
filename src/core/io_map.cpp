#include "core/io_map.hpp"

namespace indyemu {

IoMap::IoMap() {
    reset();
}

u32 IoMap::normalizeAddress(u32 address) {
    const u32 masked = address & 0x1FFFFFFFu;
    return masked;
}

void IoMap::reset() {
    registers_.fill(0);
    audio_.reset();
}

std::size_t IoMap::indexFor(u32 address) const {
    const u32 normalized = normalizeAddress(address) - kBase;
    return static_cast<std::size_t>(normalized / 4u);
}

u32 IoMap::read32(u32 address) const {
    const u32 normalized = normalizeAddress(address);
    if (normalized >= kBase && normalized < (kBase + kSize)) {
        const std::size_t index = indexFor(address);
        if (index < registers_.size()) {
            return registers_[index];
        }
    }

    // Audio device window.
    if (normalized >= (kBase + 0x1000u) && normalized < (kBase + 0x1100u)) {
        const u32 offset = normalized - (kBase + 0x1000u);
        return audio_.readRegister(offset);
    }

    return 0;
}

void IoMap::write32(u32 address, u32 value) {
    const u32 normalized = normalizeAddress(address);
    if (normalized >= kBase && normalized < (kBase + kSize)) {
        const std::size_t index = indexFor(address);
        if (index < registers_.size()) {
            registers_[index] = value;
            if (normalized >= (kBase + 0x1000u) && normalized < (kBase + 0x1100u)) {
                const u32 offset = normalized - (kBase + 0x1000u);
                audio_.writeRegister(offset, value);
            }
            return;
        }
    }

    if (normalized >= (kBase + 0x1000u) && normalized < (kBase + 0x1100u)) {
        const u32 offset = normalized - (kBase + 0x1000u);
        audio_.writeRegister(offset, value);
    }
}

}  // namespace indyemu
