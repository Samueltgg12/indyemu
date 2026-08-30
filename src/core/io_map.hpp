#pragma once

#include "core/audio.hpp"
#include "core/common.hpp"

#include <array>
#include <cstddef>
#include <cstdint>

namespace indyemu {

class IoMap {
public:
    static constexpr u32 kBase = 0x1F000000u;
    static constexpr u32 kSize = 0x01000000u;

    IoMap();

    void reset();

    u32 read32(u32 address) const;
    void write32(u32 address, u32 value);

    AudioDevice& audio() { return audio_; }
    const AudioDevice& audio() const { return audio_; }

private:
    AudioDevice audio_;
    std::array<u32, 64> registers_{};

    static u32 normalizeAddress(u32 address);
    std::size_t indexFor(u32 address) const;
};

}  // namespace indyemu
