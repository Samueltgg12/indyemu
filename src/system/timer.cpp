#include "system/timer.hpp"

namespace indyemu {

TimerDevice::TimerDevice() {
    reset();
}

void TimerDevice::reset() {
    period_ = 0;
    elapsed_ticks_ = 0;
}

void TimerDevice::setPeriod(u32 period) {
    period_ = period;
}

void TimerDevice::tick() {
    if (period_ == 0u) {
        return;
    }
    ++elapsed_ticks_;
}

}  // namespace indyemu
