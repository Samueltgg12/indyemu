#ifndef INDYEMU_DS1386_RTC_HPP
#define INDYEMU_DS1386_RTC_HPP

#include <array>
#include <cstdint>
#include <ctime>
#include <string>

#include "core/common.hpp"
#include "system/gio64_bus.hpp"

namespace indyemu {

// Dallas DS1386 RAMified Timekeeper: 8KB battery-backed RAM plus 14
// timekeeping registers (BCD time-of-day, alarms, watchdog, command).
// On the Indy it sits on the HPC3 PBUS at 0x1FBD9400.
// See hardware-docs/Dallas 1386 Indy.md.
class Ds1386Rtc : public IODevice {
public:
    static constexpr uint32_t kBase = 0x1FBD9400u;
    // PBUS decodes a 1KB slot for the RTC; the DS1386 has 8KB of RAM but
    // only the low 1KB (timekeeping registers + first NVRAM page) is
    // reachable through this window on the Indy.
    static constexpr uint32_t kSize = 0x400u;

    // Timekeeping register offsets (byte addresses).
    enum Register : uint32_t {
        kHundredths   = 0x0,  // 0.01/0.1 seconds, BCD
        kSeconds      = 0x1,
        kMinutes      = 0x2,
        kMinutesAlarm = 0x3,
        kHours        = 0x4,
        kHoursAlarm   = 0x5,
        kDay          = 0x6,  // day of week 01-07
        kDayAlarm     = 0x7,
        kDate         = 0x8,
        kMonths       = 0x9,  // bit7 EOSC, bit6 ESQW
        kYears        = 0xA,
        kCommand      = 0xB,
        kWdHundredths = 0xC,  // watchdog alarm, BCD
        kWdSeconds    = 0xD,
        kUserRamStart = 0xE,
    };

    // Command register bits.
    static constexpr u8 kCmdTe   = 1u << 7;  // transfer enable
    static constexpr u8 kCmdIpsw = 1u << 6;  // interrupt switch
    static constexpr u8 kCmdIbh  = 1u << 5;
    static constexpr u8 kCmdPu   = 1u << 4;  // pulse width
    static constexpr u8 kCmdWam  = 1u << 3;  // watchdog alarm mask
    static constexpr u8 kCmdTdm  = 1u << 2;  // time-of-day alarm mask
    static constexpr u8 kCmdWaf  = 1u << 1;  // watchdog alarm flag (RO)
    static constexpr u8 kCmdTdf  = 1u << 0;  // time-of-day alarm flag (RO)

    Ds1386Rtc();

    void reset();

    bool contains(uint32_t address) const override;
    uint32_t read32(uint32_t address) const override;
    void write32(uint32_t address, uint32_t value) override;
    std::string descriptionFor(uint32_t address) const override;

    // Byte-level access (the DS1386 is an 8-bit device on the PBUS).
    u8 read8(uint32_t offset) const;
    void write8(uint32_t offset, u8 value);

    // NVRAM persistence.
    bool loadFromFile(const std::string& path);
    bool saveToFile(const std::string& path) const;

private:
    // Refresh the external time-of-day registers from the host clock.
    // No-op while TE is 0 (registers frozen) or the oscillator is off.
    void updateTime();

    static u8 toBcd(unsigned value) {
        return static_cast<u8>(((value / 10) << 4) | (value % 10));
    }

    // Backing store; offsets 0x0-0xD are the timekeeping registers.
    std::array<u8, kSize> ram_{};
    // Last host time used to fill the registers (for change detection).
    std::time_t lastSync_ = 0;
};

} // namespace indyemu

#endif // INDYEMU_DS1386_RTC_HPP
