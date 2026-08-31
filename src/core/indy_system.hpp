// src/core/indy_system.hpp
#pragma once

#include "core/audio.hpp"
#include "core/cpu/mips_cpu.hpp"
#include "core/graphics.hpp"
#include "core/indy_hardware.hpp"
#include "core/memory.hpp"
#include "gfx/xl_graphics.hpp"
#include "io/ds1386_rtc.hpp"
#include "io/eeprom_93c56.hpp"
#include "io/hal2_audio.hpp"
#include "io/ioc2.hpp"
#include "system/gio64_bus.hpp"
#include "system/memory_controller.hpp"
#include "system/rex3.hpp"
#include "system/rtc.hpp"
#include "system/vino.hpp"

namespace indyemu {

class IndySystem {
public:
    IndySystem();
    explicit IndySystem(const MachineConfig& config);

    bool loadProm(const std::string& path);
    void reset();
    void run(std::size_t steps);
    void dumpState() const;
    void setTraceEnabled(bool enabled) { cpu_.setTraceEnabled(enabled); }

    const MachineConfig& config() const { return config_; }
    Memory& memory() { return memory_; }
    const Memory& memory() const { return memory_; }
    MipsCpu& cpu() { return cpu_; }
    const MipsCpu& cpu() const { return cpu_; }
    Rex3* rex3() { return rex3_.get(); }
    const Rex3* rex3() const { return rex3_.get(); }

private:
    MachineConfig config_;
    Memory memory_;
    MipsCpu cpu_;
    GIO64Bus io_bus_;
    Hal2Audio hal2_audio_;
    Ioc2Controller ioc2_;
    RealTimeClock rtc_;
    Ds1386Rtc ds1386_;
    MemoryController memory_controller_;
    Eeprom93c56 eeprom_;
    Vino vino_;
    std::unique_ptr<Rex3> rex3_;
};

}  // namespace indyemu
