#pragma once

#include "core/common.hpp"

#include <cstdint>
#include <string>

namespace indyemu {

class AudioDevice {
public:
    AudioDevice();

    void reset();
    bool loadStartupSample(const std::string& path);
    void playStartupChime();
    bool enabled() const { return enabled_; }
    void setEnabled(bool enabled) { enabled_ = enabled; }

    u32 readRegister(u32 offset) const;
    void writeRegister(u32 offset, u32 value);

private:
    bool enabled_ = true;
    std::string startup_sample_path_;
    std::uint32_t control_reg_ = 0;
    std::uint32_t volume_reg_ = 0;
    std::uint32_t status_reg_ = 0;
};

}  // namespace indyemu
