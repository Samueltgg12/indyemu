#pragma once

#include "core/common.hpp"

#include <array>
#include <cstdint>
#include <string>

namespace indyemu {

enum class IndyRegisterWindow : std::uint32_t {
    kGio64 = 0x1F000000u,
    kHpc3 = 0x1F0A0000u,
    kHal2 = 0x1F0B0000u,
    kRtc = 0x1F0C0000u,
    kIoc2 = 0x1F0D0000u,
    kNVRAM = 0x1F0E0000u,
    kEprom = 0x1FC00000u,
};

struct RegisterMap {
    static constexpr u32 kGio64Base = static_cast<u32>(IndyRegisterWindow::kGio64);
    static constexpr u32 kHpc3Base = static_cast<u32>(IndyRegisterWindow::kHpc3);
    static constexpr u32 kHal2Base = static_cast<u32>(IndyRegisterWindow::kHal2);
    static constexpr u32 kRtcBase = static_cast<u32>(IndyRegisterWindow::kRtc);
    static constexpr u32 kIoc2Base = static_cast<u32>(IndyRegisterWindow::kIoc2);
    static constexpr u32 kNVRAMBase = static_cast<u32>(IndyRegisterWindow::kNVRAM);

    std::array<u32, 64> gio64_regs{};
    std::array<u32, 32> hal2_regs{};
    std::array<u32, 32> ioc2_regs{};
    std::array<u32, 16> rtc_regs{};
    std::array<u32, 32> nvram_regs{};
    std::array<u32, 32> hpc3_regs{};

    bool contains(u32 address) const;
    u32 read32(u32 address) const;
    void write32(u32 address, u32 value);
    std::string descriptionFor(u32 address) const;
};

}  // namespace indyemu
