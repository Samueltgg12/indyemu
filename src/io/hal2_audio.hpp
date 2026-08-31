#pragma once

#include "core/common.hpp"
#include "system/gio64_bus.hpp"

#include <array>
#include <cstdint>

namespace indyemu {

class Hal2Audio : public IODevice {
public:
    // Physical register offsets
    static constexpr u32 kBase = 0x1FBD8000u;  // Indy HAL2 base
    static constexpr u32 kIsrOffset = 0x10u;   // Interrupt/global control
    static constexpr u32 kRevOffset = 0x20u;   // Chip revision (read-only)
    static constexpr u32 kIarOffset = 0x30u;   // Indirect address register
    static constexpr u32 kIdr0Offset = 0x40u;  // Indirect data register 0
    static constexpr u32 kIdr1Offset = 0x50u;  // Indirect data register 1
    static constexpr u32 kIdr2Offset = 0x60u;  // Indirect data register 2
    static constexpr u32 kIdr3Offset = 0x70u;  // Indirect data register 3

    // Chip revision value
    static constexpr u32 kRevision = 0x4010u;

    // Indirect register addresses (IAR values)
    static constexpr u32 kDmaEnableW = 0x9104u;
    static constexpr u32 kDmaEnableR = 0x9904u;
    static constexpr u32 kDmaDriveW = 0x910Cu;
    static constexpr u32 kDmaDriveR = 0x990Cu;
    static constexpr u32 kDmaEndianW = 0x9108u;
    static constexpr u32 kCodecACtrl1W = 0x1404u;
    static constexpr u32 kCodecACtrl2W = 0x1408u;
    static constexpr u32 kCodecBCtrl1W = 0x1504u;
    static constexpr u32 kCodecBCtrl2W = 0x1508u;
    static constexpr u32 kAesTxCtrlW = 0x0304u;
    static constexpr u32 kAesRxCtrlW = 0x0204u;
    static constexpr u32 kBres1Ctrl1W = 0x2104u;
    static constexpr u32 kBres1Ctrl2W = 0x2108u;
    static constexpr u32 kBres2Ctrl1W = 0x2204u;
    static constexpr u32 kBres2Ctrl2W = 0x2208u;
    static constexpr u32 kBres3Ctrl1W = 0x2304u;
    static constexpr u32 kBres3Ctrl2W = 0x2308u;
    static constexpr u32 kRelayControlW = 0x1504u;

    Hal2Audio();

    void reset();
    u32 read32(u32 offset) const;
    void write32(u32 offset, u32 value);

    bool enabled() const { return enabled_; }
    void setEnabled(bool enabled) { enabled_ = enabled; }

    void triggerStartupTone();

private:
    // Indirect register storage
    u32 dma_enable_ = 0;
    u32 dma_drive_ = 0;
    u32 dma_endian_ = 0;
    u32 codec_a_ctrl1_ = 0;
    u32 codec_a_ctrl2_ = 0;
    u32 codec_b_ctrl1_ = 0;
    u32 codec_b_ctrl2_ = 0;
    u32 aes_tx_ctrl_ = 0;
    u32 aes_rx_ctrl_ = 0;
    u32 bres1_ctrl1_ = 0;
    u32 bres1_ctrl2_ = 0;
    u32 bres2_ctrl1_ = 0;
    u32 bres2_ctrl2_ = 0;
    u32 bres3_ctrl1_ = 0;
    u32 bres3_ctrl2_ = 0;
    u32 relay_control_ = 0;

    // Physical registers
    u32 isr_ = 0;
    u32 iar_ = 0;
    std::array<u32, 4> idr_{};

    bool enabled_ = true;

    // Handle an IAR write (commit indirect register)
    void handleIarWrite(u32 iar_value);
    // Handle an IAR read (load indirect register into IDR)
    u32 handleIarRead(u32 iar_value) const;
};

}  // namespace indyemu
