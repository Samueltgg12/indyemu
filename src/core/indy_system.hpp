#pragma once

#include "core/audio.hpp"
#include "core/cpu/mips_cpu.hpp"
#include "core/graphics.hpp"
#include "core/indy_hardware.hpp"
#include "core/memory.hpp"
#include "gfx/xl_graphics.hpp"
#include "io/hal2_audio.hpp"
#include "io/ioc2.hpp"
#include "io/register_map.hpp"
#include "system/rtc.hpp"

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

private:
    MachineConfig config_;
    Memory memory_;
    MipsCpu cpu_;
    GraphicsController graphics_;
    RegisterMap registers_;
    XLGraphics xl_graphics_;
    Hal2Audio hal2_audio_;
    Ioc2Controller ioc2_;
    RealTimeClock rtc_;
};

}  // namespace indyemu
