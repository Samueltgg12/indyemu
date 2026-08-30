#include "io/register_map.hpp"

namespace indyemu {

bool RegisterMap::contains(u32 address) const {
    return address >= 0x1F000000u && address < 0x20000000u;
}

u32 RegisterMap::read32(u32 address) const {
    if (address >= kGio64Base && address < (kGio64Base + 0x1000u)) {
        const std::size_t index = (address - kGio64Base) / 4u;
        if (index < gio64_regs.size()) {
            return gio64_regs[index];
        }
    }
    if (address >= kHal2Base && address < (kHal2Base + 0x1000u)) {
        const std::size_t index = (address - kHal2Base) / 4u;
        if (index < hal2_regs.size()) {
            return hal2_regs[index];
        }
    }
    if (address >= kIoc2Base && address < (kIoc2Base + 0x1000u)) {
        const std::size_t index = (address - kIoc2Base) / 4u;
        if (index < ioc2_regs.size()) {
            return ioc2_regs[index];
        }
    }
    if (address >= kRtcBase && address < (kRtcBase + 0x1000u)) {
        const std::size_t index = (address - kRtcBase) / 4u;
        if (index < rtc_regs.size()) {
            return rtc_regs[index];
        }
    }
    if (address >= kNVRAMBase && address < (kNVRAMBase + 0x1000u)) {
        const std::size_t index = (address - kNVRAMBase) / 4u;
        if (index < nvram_regs.size()) {
            return nvram_regs[index];
        }
    }
    if (address >= kHpc3Base && address < (kHpc3Base + 0x1000u)) {
        const std::size_t index = (address - kHpc3Base) / 4u;
        if (index < hpc3_regs.size()) {
            return hpc3_regs[index];
        }
    }
    return 0u;
}

void RegisterMap::write32(u32 address, u32 value) {
    if (address >= kGio64Base && address < (kGio64Base + 0x1000u)) {
        const std::size_t index = (address - kGio64Base) / 4u;
        if (index < gio64_regs.size()) {
            gio64_regs[index] = value;
        }
        return;
    }
    if (address >= kHal2Base && address < (kHal2Base + 0x1000u)) {
        const std::size_t index = (address - kHal2Base) / 4u;
        if (index < hal2_regs.size()) {
            hal2_regs[index] = value;
        }
        return;
    }
    if (address >= kIoc2Base && address < (kIoc2Base + 0x1000u)) {
        const std::size_t index = (address - kIoc2Base) / 4u;
        if (index < ioc2_regs.size()) {
            ioc2_regs[index] = value;
        }
        return;
    }
    if (address >= kRtcBase && address < (kRtcBase + 0x1000u)) {
        const std::size_t index = (address - kRtcBase) / 4u;
        if (index < rtc_regs.size()) {
            rtc_regs[index] = value;
        }
        return;
    }
    if (address >= kNVRAMBase && address < (kNVRAMBase + 0x1000u)) {
        const std::size_t index = (address - kNVRAMBase) / 4u;
        if (index < nvram_regs.size()) {
            nvram_regs[index] = value;
        }
        return;
    }
    if (address >= kHpc3Base && address < (kHpc3Base + 0x1000u)) {
        const std::size_t index = (address - kHpc3Base) / 4u;
        if (index < hpc3_regs.size()) {
            hpc3_regs[index] = value;
        }
    }
}

std::string RegisterMap::descriptionFor(u32 address) const {
    if (address >= kGio64Base && address < (kGio64Base + 0x1000u)) {
        return "GIO64 / XL graphics register window";
    }
    if (address >= kHal2Base && address < (kHal2Base + 0x1000u)) {
        return "HAL2 audio register window";
    }
    if (address >= kIoc2Base && address < (kIoc2Base + 0x1000u)) {
        return "IOC2 controller register window";
    }
    if (address >= kRtcBase && address < (kRtcBase + 0x1000u)) {
        return "RTC / real time clock register window";
    }
    if (address >= kNVRAMBase && address < (kNVRAMBase + 0x1000u)) {
        return "NVRAM configuration window";
    }
    if (address >= kHpc3Base && address < (kHpc3Base + 0x1000u)) {
        return "HPC3 / memory controller register window";
    }
    return "unknown Indy register window";
}

}  // namespace indyemu
