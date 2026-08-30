#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace indyemu {
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

constexpr u32 kPromBase = 0x1FC00000u;
constexpr u32 kRamBase = 0x80000000u;
constexpr u32 kIoBase = 0x1F000000u;

inline u32 signExtend16(u32 value) {
    return static_cast<u32>(static_cast<i32>(static_cast<i16>(value & 0xFFFFu)));
}
}  // namespace indyemu
