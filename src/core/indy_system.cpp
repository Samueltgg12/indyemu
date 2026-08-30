#include "core/indy_system.hpp"

namespace indyemu {

IndySystem::IndySystem() : IndySystem(MachineConfig{}) {
}

IndySystem::IndySystem(const MachineConfig& config)
    : config_(config),
      memory_(),
      cpu_(memory_),
      graphics_(GraphicsConfig{config_.framebuffer_width, config_.framebuffer_height, config_.bits_per_pixel, 0x1F000000u}),
      registers_(),
      xl_graphics_(),
      hal2_audio_(),
      ioc2_(),
      rtc_(true, false) {
    reset();
}

bool IndySystem::loadProm(const std::string& path) {
    return memory_.loadProm(path);
}

void IndySystem::reset() {
    memory_.reset();
    cpu_.reset();
}

void IndySystem::run(std::size_t steps) {
    for (std::size_t i = 0; i < steps; ++i) {
        if (!cpu_.step()) {
            break;
        }
    }
}

void IndySystem::dumpState() const {
    cpu_.dumpState();
}

}  // namespace indyemu
