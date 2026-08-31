#include "core/indy_system.hpp"

namespace indyemu {

IndySystem::IndySystem() : IndySystem(MachineConfig{}) {
}

IndySystem::IndySystem(const MachineConfig& config)
    : config_(config),
      memory_(config.ram_bytes),
      cpu_(memory_),
      hal2_audio_(),
      ioc2_(),
      rtc_(true, false),
      rex3_(std::make_unique<Rex3>()) {
    // Route IOC2 interrupts to the CPU
    cpu_.setInterruptController(&ioc2_);
    // Add the Rex3 to the IO bus at the GIO64 slot 0 base address (0x1F000000) with size 16MB
    memory_.addIoDevice(rex3_.get(), 0x1F000000u, 0x01000000u);
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
        if (i % 1000 == 0) {
            std::cerr << "Step: " << i << ", PC: 0x" << std::hex << cpu_.registers().pc << std::dec << std::endl;
        }
    }
}

void IndySystem::dumpState() const {
    cpu_.dumpState();
}

}  // namespace indyemu
