#include "io/ioc2.hpp"

namespace indyemu {

Ioc2Controller::Ioc2Controller() {
    reset();
}

void Ioc2Controller::reset() {
    regs_.fill(0);
}

u32 Ioc2Controller::read32(u32 offset) const {
    const std::size_t index = offset / 4u;
    if (index < regs_.size()) {
        return regs_[index];
    }
    return 0;
}

void Ioc2Controller::write32(u32 offset, u32 value) {
    const std::size_t index = offset / 4u;
    if (index < regs_.size()) {
        regs_[index] = value;
    }
}

}  // namespace indyemu
