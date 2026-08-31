// Test: DS1386 RAMified timekeeper — BCD time registers, NVRAM, command
// register semantics. See hardware-docs/Dallas 1386 Indy.md.

#include <cassert>
#include <cstdint>
#include <ctime>
#include <iostream>

#include "io/ds1386_rtc.hpp"

using namespace indyemu;

namespace {

unsigned fromBcd(u8 v) { return ((v >> 4) * 10u) + (v & 0x0Fu); }

} // namespace

int main() {
    Ds1386Rtc rtc;

    // Time registers reflect the host clock in BCD.
    const std::time_t now = std::time(nullptr);
    std::tm tm{};
    gmtime_r(&now, &tm);
    assert(fromBcd(rtc.read8(Ds1386Rtc::kYears)) ==
           static_cast<unsigned>(tm.tm_year % 100));
    assert(fromBcd(rtc.read8(Ds1386Rtc::kMonths) & 0x1Fu) ==
           static_cast<unsigned>(tm.tm_mon + 1));
    assert(fromBcd(rtc.read8(Ds1386Rtc::kDate)) ==
           static_cast<unsigned>(tm.tm_mday));
    assert(fromBcd(rtc.read8(Ds1386Rtc::kHours) & 0x3Fu) ==
           static_cast<unsigned>(tm.tm_hour));

    // Command register: TE set, alarms masked after reset.
    const u8 cmd = rtc.read8(Ds1386Rtc::kCommand);
    assert((cmd & Ds1386Rtc::kCmdTe) != 0);
    assert((cmd & Ds1386Rtc::kCmdWam) != 0);
    assert((cmd & Ds1386Rtc::kCmdTdm) != 0);

    // NVRAM is plain read/write storage.
    rtc.write8(Ds1386Rtc::kUserRamStart, 0x5Au);
    rtc.write8(Ds1386Rtc::kSize - 1, 0xA5u);
    assert(rtc.read8(Ds1386Rtc::kUserRamStart) == 0x5Au);
    assert(rtc.read8(Ds1386Rtc::kSize - 1) == 0xA5u);

    // Freezing transfers (TE=0) stops updates; registers stay readable.
    rtc.write8(Ds1386Rtc::kCommand, Ds1386Rtc::kCmdWam | Ds1386Rtc::kCmdTdm);
    const u8 frozenSec = rtc.read8(Ds1386Rtc::kSeconds);
    assert(rtc.read8(Ds1386Rtc::kSeconds) == frozenSec);

    // WAF/TDF are read-only: writing them must not set the flags.
    rtc.write8(Ds1386Rtc::kCommand,
               Ds1386Rtc::kCmdTe | Ds1386Rtc::kCmdWaf | Ds1386Rtc::kCmdTdf);
    assert((rtc.read8(Ds1386Rtc::kCommand) & Ds1386Rtc::kCmdWaf) == 0);
    assert((rtc.read8(Ds1386Rtc::kCommand) & Ds1386Rtc::kCmdTdf) == 0);

    // Bus-level 32-bit access mirrors the byte across the lane.
    const uint32_t word = rtc.read32(Ds1386Rtc::kBase + Ds1386Rtc::kSeconds);
    assert((word & 0xFFu) == ((word >> 8) & 0xFFu));

    std::cout << "ds1386_rtc_test passed\n";
    return 0;
}
