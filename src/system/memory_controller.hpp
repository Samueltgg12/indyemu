// src/system/memory_controller.hpp
#ifndef INDYEMU_MEMORY_CONTROLLER_HPP
#define INDYEMU_MEMORY_CONTROLLER_HPP

#include <cstdint>
#include <array>
#include <string>
#include "system/gio64_bus.hpp"

namespace indyemu {

class Eeprom93c56;

// Memory controller (MC) chip. Handles the CPU/GIO memory control registers
// at 0x1FA00000. See hardware-docs/mc.md section 5.
class MemoryController : public IODevice {
public:
    static constexpr uint32_t kBase = 0x1FA00000u;
    static constexpr uint32_t kSize = 0x00100000u; // 1MB range

    // Register offsets (relative to kBase)
    enum Register : uint32_t {
        CPUCTRL0        = 0x0000,
        CPUCTRL1        = 0x0008,
        DOGC            = 0x0010, // read: watchdog timer, write: clear
        SYSID           = 0x0018,
        RPSS_DIVIDER    = 0x0028,
        EEROM           = 0x0030,
        CTRLD           = 0x0040,
        REF_CTR         = 0x0048,
        GIO64_ARB       = 0x0080,
        CPU_TIME        = 0x0088,
        LB_TIME         = 0x0098,
        MEMCFG0         = 0x00C0,
        MEMCFG1         = 0x00C8,
        CPU_MEMACC      = 0x00D0,
        GIO_MEMACC      = 0x00D8,
        CPU_ERROR_ADDR  = 0x00E0,
        CPU_ERROR_STAT  = 0x00E8,
        GIO_ERROR_ADDR  = 0x00F0,
        GIO_ERROR_STAT  = 0x00F8,
        SYS_SEMAPHORE   = 0x0100,
        LOCK_MEMORY     = 0x0108,
        EISA_LOCK       = 0x0110,
        DMA_GIO_MASK    = 0x0150,
        DMA_GIO_SUB     = 0x0158,
        DMA_CAUSE       = 0x0160,
        DMA_CTL         = 0x0168,
        DMA_TLB_HI_0    = 0x0180,
        DMA_TLB_LO_0    = 0x0188,
        DMA_TLB_HI_1    = 0x0190,
        DMA_TLB_LO_1    = 0x0198,
        DMA_TLB_HI_2    = 0x01A0,
        DMA_TLB_LO_2    = 0x01A8,
        DMA_TLB_HI_3    = 0x01B0,
        DMA_TLB_LO_3    = 0x01B8,
        RPSS_CTR        = 0x1000,
        DMA_MEMADR      = 0x2000,
    };

    MemoryController();

    bool contains(uint32_t address) const override;
    uint32_t read32(uint32_t address) const override;
    void write32(uint32_t address, uint32_t value) override;
    std::string descriptionFor(uint32_t address) const override;

    void reset();

    // Attach the CPU configuration EEPROM (93C56) driven via the EEROM
    // register. See hardware-docs/mc.md section 5.6.
    void attachEeprom(Eeprom93c56* eeprom) { eeprom_ = eeprom; }

    // Program MEMCFG0/1 to describe `ramBytes` of contiguous RAM at
    // physical address 0. See hardware-docs/mc.md section 5.12.
    void configureMemory(uint32_t ramBytes);

    // Advance the refresh counter and watchdog timer by `cycles` CPU cycles.
    void tick(uint32_t cycles);

    // True once the enabled watchdog timer has rolled over (machine reset).
    bool watchdogExpired() const { return watchdogExpired_; }
    void clearWatchdogExpired() { watchdogExpired_ = false; }

private:
    // EEROM register bits (hardware-docs/mc.md section 5.6).
    static constexpr uint32_t kEepromCs  = 1u << 1;  // chip select, active high
    static constexpr uint32_t kEepromSck = 1u << 2;  // serial clock
    static constexpr uint32_t kEepromSo  = 1u << 3;  // data to EEPROM (DI)
    static constexpr uint32_t kEepromSi  = 1u << 4;  // data from EEPROM (DO)

    // Storage for read/write registers. Indexed by (offset / 4).
    std::array<uint32_t, kSize / 4u> regs_;
    Eeprom93c56* eeprom_ = nullptr;

    // Refresh counter: counts down at CPU frequency, reloads from CTRLD.
    // See hardware-docs/mc.md sections 5.7/5.8.
    uint32_t refreshCounter_ = 0;
    // Watchdog: 20-bit counter of refresh bursts (section 5.3).
    uint32_t watchdogCounter_ = 0;
    bool watchdogExpired_ = false;
};

} // namespace indyemu

#endif // INDYEMU_MEMORY_CONTROLLER_HPP