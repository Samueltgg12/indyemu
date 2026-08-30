#include "system/rtc.hpp"

#include <chrono>

namespace indyemu {

RealTimeClock::RealTimeClock(bool sync_to_host, bool host_independent)
    : sync_to_host_(sync_to_host), host_independent_(host_independent) {
    reset();
}

void RealTimeClock::reset() {
    const auto now = std::chrono::system_clock::now().time_since_epoch();
    base_epoch_ = std::chrono::duration_cast<std::chrono::seconds>(now).count();
}

void RealTimeClock::setHostSyncEnabled(bool enabled) {
    sync_to_host_ = enabled;
}

void RealTimeClock::setHostIndependent(bool enabled) {
    host_independent_ = enabled;
    if (enabled) {
        sync_to_host_ = false;
    }
}

std::uint64_t RealTimeClock::nowSeconds() const {
    if (host_independent_) {
        return base_epoch_;
    }
    if (sync_to_host_) {
        const auto now = std::chrono::system_clock::now().time_since_epoch();
        return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::seconds>(now).count());
    }
    return base_epoch_;
}

}  // namespace indyemu
