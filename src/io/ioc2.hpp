#pragma once

#include "core/common.hpp"
#include "core/cpu/mips_cpu.hpp"
#include "system/gio64_bus.hpp"

#include <array>
#include <cstdint>

namespace indyemu {

// IOC2 Interrupt Controller (INT3)
// Located at HPC3 PBUS channel 6 @ 0x1FBD9800
class Ioc2Controller : public InterruptController, public IODevice {
public:
    static constexpr u32 kBase = 0x1FBD9800u;  // HPC3 PBUS channel 6
    static constexpr u32 kSize = 0x100u;       // Register block size
    
    // Register offsets
    static constexpr u32 kL0StatOffset = 0x00u;   // Local 0 Status (ISR)
    static constexpr u32 kL0MaskOffset = 0x04u;   // Local 0 Mask
    static constexpr u32 kL1StatOffset = 0x08u;   // Local 1 Status (ISR)
    static constexpr u32 kL1MaskOffset = 0x0Cu;   // Local 1 Mask
    static constexpr u32 kMapStatOffset = 0x10u;  // Mappable Status (ISR)
    static constexpr u32 kMapMask0Offset = 0x14u; // Mappable Mask 0
    static constexpr u32 kMapMask1Offset = 0x18u; // Mappable Mask 1
    static constexpr u32 kMapPolOffset = 0x1Cu;   // Mappable Polarity
    
    // Interrupt lines (to CPU)
    enum class InterruptLine {
        kIP2 = 2,  // Local 0 & Mappable (via MAP_INT0)
        kIP3 = 3,  // Local 1 & Mappable (via MAP_INT1)
    };
    
    // Local 0 interrupt bit definitions
    enum class Local0Interrupt : u8 {
        kFifoFull = 0x01,   // REX3 GFIFO full (bit 0)
        kScsi0 = 0x02,      // SCSI0 interrupt (bit 1)
        kScsi1 = 0x04,      // SCSI1 interrupt (bit 2)
        kEnet = 0x08,       // Ethernet interrupt (bit 3)
        kMcDma = 0x10,      // MC DMA done (bit 4)
        kCentr = 0x20,      // Parallel port (bit 5)
        kGio1 = 0x40,       // REX3 GIO_INT_1 (bit 6)
        kMapInt0 = 0x80,    // Mappable interrupt 0 (bit 7)
    };
    
    // Local 1 interrupt bit definitions
    enum class Local1Interrupt : u8 {
        kPower = 0x01,      // Power button (bit 0)
        kIsdnHscx = 0x02,   // ISDN HSCX (bit 1)
        kIsdnIsac = 0x04,   // ISDN ISAC (bit 2)
        kReserved = 0x08,   // Reserved (bit 3)
        kHpc3 = 0x10,       // HPC3 DMA done (bit 4)
        kAcFail = 0x20,     // AC fail (bit 5)
        kVideo = 0x40,      // VINO video/vertical retrace (bit 6)
        kGio2 = 0x80,       // REX3 VERT_RETRACE_N / GIO_INT_2 (bit 7)
    };
    
    // Mappable interrupt bit definitions
    enum class MapInterrupt : u8 {
        kGioExp0 = 0x40,    // GIO expansion slot 0 (bit 6)
        kGioExp1 = 0x80,    // GIO expansion slot 1 (bit 7)
        kKeybd = 0x10,      // Keyboard/mouse (bit 4)
        kDuart = 0x20,      // Serial DUART (bit 5)
    };

    Ioc2Controller();

    void reset();

    // IODevice interface (bus passes full physical address)
    bool contains(u32 address) const override;
    u32 read32(u32 address) const override;
    void write32(u32 address, u32 value) override;
    
    // Interrupt API
    void assertInterrupt(Local0Interrupt int_bit);
    void clearInterrupt(Local0Interrupt int_bit);
    void assertInterrupt(Local1Interrupt int_bit);
    void clearInterrupt(Local1Interrupt int_bit);
    void assertInterrupt(MapInterrupt int_bit);
    void clearInterrupt(MapInterrupt int_bit);
    
    // Query interrupt state
    u8 isEnabled(InterruptLine line) const;
    bool hasPendingInterrupt(InterruptLine line) const;

    // InterruptController interface
    u32 pendingInterruptLines() const override;
    
private:
    // Interrupt status and mask registers
    u8 l0_stat_ = 0;
    u8 l0_mask_ = 0;
    u8 l1_stat_ = 0;
    u8 l1_mask_ = 0;
    u8 map_stat_ = 0;
    u8 map_mask0_ = 0;
    u8 map_mask1_ = 0;
    u8 map_pol_ = 0;
    
    // Derived interrupt lines (output to CPU)
    // IP2 = (l0_stat & l0_mask) | ((map_stat & map_mask0) ? MAP_INT0 : 0)
    // IP3 = (l1_stat & l1_mask) | ((map_stat & map_mask1) ? MAP_INT1 : 0)
    bool ip2_active_ = false;
    bool ip3_active_ = false;
};

}  // namespace indyemu
