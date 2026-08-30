#pragma once

#include <cstdint>
#include <ctime>

namespace indyemu {

class RealTimeClock {
public:
    // Default behavior: sync the machine RTC to the host clock while the
    // emulator is in its early boot / testing stages.
    RealTimeClock(bool sync_to_host = true, bool host_independent = false);

    void reset();
    void setHostSyncEnabled(bool enabled);
    bool hostSyncEnabled() const { return sync_to_host_; }

    void setHostIndependent(bool enabled);
    bool hostIndependent() const { return host_independent_; }

    std::uint64_t nowSeconds() const;

private:
    bool sync_to_host_ = true;
    bool host_independent_ = false;
    std::time_t base_epoch_ = 0;
};

}  // namespace indyemu
