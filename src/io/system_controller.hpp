#pragma once

#include "core/common.hpp"

#include <array>
#include <cstdint>

namespace indyemu {

class SystemController {
public:
    SystemController();

    void reset();
    void setMacAddress(const std::array<u8, 6>& mac);
    const std::array<u8, 6>& macAddress() const { return mac_; }

private:
    std::array<u8, 6> mac_ = {0x08u, 0x00u, 0x69u, 0x12u, 0x34u, 0x56u};
};

}  // namespace indyemu
