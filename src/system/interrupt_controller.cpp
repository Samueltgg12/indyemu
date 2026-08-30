#include "system/interrupt_controller.hpp"

namespace indyemu {

InterruptController::InterruptController() {
    reset();
}

void InterruptController::reset() {
    pending_mask_ = 0;
}

void InterruptController::trigger(u32 line) {
    pending_mask_ |= (1u << line);
}

void InterruptController::clear(u32 line) {
    pending_mask_ &= ~(1u << line);
}

}  // namespace indyemu
