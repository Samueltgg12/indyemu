#include "io/ds1386_rtc.hpp"

#include <chrono>
#include <fstream>

namespace indyemu {

Ds1386Rtc::Ds1386Rtc() {
    reset();
}

void Ds1386Rtc::reset() {
    ram_.fill(0);
    // Command register: TE=1 (transfers enabled), alarms masked.
    ram_[kCommand] = kCmdTe | kCmdWam | kCmdTdm;
    // Months register: EOSC=0 (oscillator enabled), ESQW=1 (SQW hi-Z).
    ram_[kMonths] = 0x40u;
    lastSync_ = 0;
}

bool Ds1386Rtc::contains(uint32_t address) const {
    return address >= kBase && address < (kBase + kSize);
}

void Ds1386Rtc::updateTime() {
    // Frozen while TE=0 or the oscillator is disabled (EOSC=1).
    if ((ram_[kCommand] & kCmdTe) == 0 || (ram_[kMonths] & 0x80u) != 0) {
        return;
    }
    const auto now = std::chrono::system_clock::now().time_since_epoch();
    const std::time_t secs =
        std::chrono::duration_cast<std::chrono::seconds>(now).count();
    if (secs == lastSync_) {
        return;
    }
    lastSync_ = secs;

    std::tm tm{};
    gmtime_r(&secs, &tm);
    ram_[kSeconds] = toBcd(static_cast<unsigned>(tm.tm_sec));
    ram_[kMinutes] = toBcd(static_cast<unsigned>(tm.tm_min));
    // 24-hour mode (bit 6 of hours = 0).
    ram_[kHours] = toBcd(static_cast<unsigned>(tm.tm_hour));
    // Day of week 01-07 (Sunday = 1).
    ram_[kDay] = toBcd(static_cast<unsigned>(tm.tm_wday + 1));
    ram_[kDate] = toBcd(static_cast<unsigned>(tm.tm_mday));
    // Preserve EOSC/ESQW in the months register.
    ram_[kMonths] = static_cast<u8>((ram_[kMonths] & 0xC0u) |
                                    toBcd(static_cast<unsigned>(tm.tm_mon + 1)));
    ram_[kYears] = toBcd(static_cast<unsigned>(tm.tm_year % 100));
}

u8 Ds1386Rtc::read8(uint32_t offset) const {
    const_cast<Ds1386Rtc*>(this)->updateTime();
    return ram_[offset & (kSize - 1)];
}

void Ds1386Rtc::write8(uint32_t offset, u8 value) {
    offset &= (kSize - 1);
    switch (offset) {
        case kHundredths:
            // Hundredths always read as written but are not host-synced.
            ram_[offset] = value;
            break;
        case kCommand:
            // WAF/TDF are read-only flags.
            ram_[kCommand] = static_cast<u8>((value & ~(kCmdWaf | kCmdTdf)) |
                                             (ram_[kCommand] & (kCmdWaf | kCmdTdf)));
            break;
        case kMonths:
            // Preserve nothing special on write; EOSC/ESQW are writable.
            ram_[offset] = value;
            break;
        case kWdHundredths:
        case kWdSeconds:
            // Accessing the watchdog registers clears WAF and restarts the
            // countdown. Zero in both registers disables the watchdog.
            ram_[offset] = value;
            ram_[kCommand] &= ~kCmdWaf;
            break;
        case kMinutesAlarm:
        case kHoursAlarm:
        case kDayAlarm:
            // Accessing the alarm registers clears TDF.
            ram_[offset] = value;
            ram_[kCommand] &= ~kCmdTdf;
            break;
        default:
            ram_[offset] = value;
            break;
    }
}

uint32_t Ds1386Rtc::read32(uint32_t address) const {
    if (!contains(address)) {
        return 0;
    }
    // PBUS 8-bit device: the byte is mirrored across the 32-bit lane.
    const u8 byte = read8(address - kBase);
    return static_cast<uint32_t>(byte) * 0x01010101u;
}

void Ds1386Rtc::write32(uint32_t address, uint32_t value) {
    if (!contains(address)) {
        return;
    }
    write8(address - kBase, static_cast<u8>(value & 0xFFu));
}

std::string Ds1386Rtc::descriptionFor(uint32_t address) const {
    if (!contains(address)) {
        return "unknown address";
    }
    const uint32_t offset = address - kBase;
    switch (offset) {
        case kHundredths:   return "RTC hundredths";
        case kSeconds:      return "RTC seconds";
        case kMinutes:      return "RTC minutes";
        case kMinutesAlarm: return "RTC minutes alarm";
        case kHours:        return "RTC hours";
        case kHoursAlarm:   return "RTC hours alarm";
        case kDay:          return "RTC day of week";
        case kDayAlarm:     return "RTC day alarm";
        case kDate:         return "RTC date";
        case kMonths:       return "RTC months";
        case kYears:        return "RTC years";
        case kCommand:      return "RTC command";
        case kWdHundredths: return "RTC watchdog hundredths";
        case kWdSeconds:    return "RTC watchdog seconds";
        default:            return "RTC NVRAM";
    }
}

bool Ds1386Rtc::loadFromFile(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        return false;
    }
    in.read(reinterpret_cast<char*>(ram_.data()),
            static_cast<std::streamsize>(ram_.size()));
    return in.good() || in.eof();
}

bool Ds1386Rtc::saveToFile(const std::string& path) const {
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) {
        return false;
    }
    out.write(reinterpret_cast<const char*>(ram_.data()),
              static_cast<std::streamsize>(ram_.size()));
    return out.good();
}

} // namespace indyemu
