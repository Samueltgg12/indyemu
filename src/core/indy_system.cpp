// src/core/indy_system.cpp
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
    // Add the Rex3 to the IO bus at the GIO64 slot 0 base address (0x1F000000) with size 4MB
    memory_.addIoDevice(rex3_.get(), Rex3::kBase, Rex3::kSize);
    // Register HAL2 audio and IOC2 interrupt controller on the IO bus
    memory_.addIoDevice(&hal2_audio_, Hal2Audio::kBase, Hal2Audio::kSize);
    memory_.addIoDevice(&ioc2_, Ioc2Controller::kBase, Ioc2Controller::kSize);
    // Register the memory controller (MC) at 0x1FA00000 and attach the
    // CPU configuration EEPROM (93C56) to its EEROM register.
    memory_controller_.attachEeprom(&eeprom_);
    memory_controller_.configureMemory(static_cast<uint32_t>(config.ram_bytes));
    memory_.addIoDevice(&memory_controller_, MemoryController::kBase, MemoryController::kSize);
    // Register the VINO video input ASIC in the low EISA I/O space (0x00080000)
    memory_.addIoDevice(&vino_, Vino::kBase, Vino::kSize);    // Register the DS1386 RTC/NVRAM on the HPC3 PBUS (0x1FBD9400)
    memory_.addIoDevice(&ds1386_, Ds1386Rtc::kBase, Ds1386Rtc::kSize);    reset();
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
        // Advance the MC refresh/watchdog timers by one CPU cycle.
        memory_controller_.tick(1);
        if (memory_controller_.watchdogExpired()) {
            // Watchdog rollover resets the machine (mc.md section 5.3).
            std::cerr << "[mc] Watchdog timer expired, resetting machine\n";
            reset();
            memory_controller_.clearWatchdogExpired();
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
