#include "core/audio.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

namespace indyemu {

AudioDevice::AudioDevice() {
    reset();
    startup_sample_path_ = "samples/indy_boot.aiff";
}

void AudioDevice::reset() {
    control_reg_ = 0;
    volume_reg_ = 0;
    status_reg_ = 0;
}

bool AudioDevice::loadStartupSample(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return false;
    }
    startup_sample_path_ = path;
    return true;
}

void AudioDevice::playStartupChime() {
    if (!enabled_) {
        return;
    }

    status_reg_ = 1;

    // Prefer the actual extracted startup sample when available.
    const std::string path = startup_sample_path_.empty() ? "samples/indy_boot.aiff" : startup_sample_path_;

    // Try to play it with a local host utility if present; otherwise keep the emulated device state in sync.
    // This acts as the startup-sound path for the PROM boot flow without forcing a hard dependency on a specific audio stack.
    std::cout << "[audio] PROM startup chime requested: " << path << "\n";

#if defined(__linux__)
    const std::string cmd = "command -v ffplay >/dev/null 2>&1 && ffplay -nodisp -autoexit -loglevel quiet \"" + path + "\" >/dev/null 2>&1 || true";
    std::system(cmd.c_str());
#elif defined(_WIN32)
    const std::string cmd = "powershell -NoProfile -Command \"(New-Object Media.SoundPlayer '\"" + path + "\').PlaySync()\"";
    std::system(cmd.c_str());
#else
    (void)path;
#endif
}

u32 AudioDevice::readRegister(u32 offset) const {
    switch (offset) {
        case 0x00:
            return control_reg_;
        case 0x04:
            return volume_reg_;
        case 0x08:
            return status_reg_;
        default:
            return 0;
    }
}

void AudioDevice::writeRegister(u32 offset, u32 value) {
    switch (offset) {
        case 0x00:
            control_reg_ = value;
            if (value != 0) {
                playStartupChime();
            }
            break;
        case 0x04:
            volume_reg_ = value;
            break;
        case 0x08:
            status_reg_ = value;
            break;
        default:
            break;
    }
}

}  // namespace indyemu
