#include "io/system_controller.hpp"

namespace indyemu {

SystemController::SystemController() {
    reset();
}

void SystemController::reset() {
    mac_ = {0x08u, 0x00u, 0x69u, 0x12u, 0x34u, 0x56u};
}

void SystemController::setMacAddress(const std::array<u8, 6>& mac) {
    mac_ = mac;
}

}  // namespace indyemu
