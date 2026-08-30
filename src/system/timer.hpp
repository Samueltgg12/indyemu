#pragma once

#include "core/common.hpp"

namespace indyemu {

class TimerDevice {
public:
    TimerDevice();

    void reset();
    void setPeriod(u32 period);
    void tick();
    u32 elapsedTicks() const { return elapsed_ticks_; }
    u32 period() const { return period_; }

private:
    u32 period_ = 0;
    u32 elapsed_ticks_ = 0;
};

}  // namespace indyemu
