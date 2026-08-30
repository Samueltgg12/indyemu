#pragma once

#include "core/common.hpp"
#include "io/register_map.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <memory>
#include <vector>

namespace indyemu {

class Memory {
public:
    enum class Region {
        kUnknown,
        kRam,
        kProm,
        kIo,
    };

    static constexpr std::size_t kRamSize = 64 * 1024 * 1024;
    static constexpr std::size_t kPromSize = 2 * 1024 * 1024;

    Memory();
    ~Memory() = default;

    bool loadProm(const std::string& path);
    void reset();

    Region regionForAddress(u32 address) const;
    const char* regionName(u32 address) const;
    u8 read8(u32 address) const;
    u16 read16(u32 address) const;
    u32 read32(u32 address) const;

    void write8(u32 address, u8 value);
    void write16(u32 address, u16 value);
    void write32(u32 address, u32 value);

    void dumpRange(u32 start, std::size_t length) const;

private:
    std::unique_ptr<u8[]> ram_;
    std::unique_ptr<u8[]> prom_;
    RegisterMap registers_{};
    bool prom_loaded_ = false;

    static u32 translateAddress(u32 address);
    bool isPromAddress(u32 address) const;
    bool isRamAddress(u32 address) const;
    bool isIoRegisterAddress(u32 address) const;
};

}  // namespace indyemu
