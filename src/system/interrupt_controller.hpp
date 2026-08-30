#pragma once

#include "core/common.hpp"

#include <cstdint>

namespace indyemu {

class InterruptController {
public:
    InterruptController();

    void reset();
    void trigger(u32 line);
    void clear(u32 line);
    u32 pendingMask() const { return pending_mask_; }

private:
    u32 pending_mask_ = 0;
};

}  // namespace indyemu
