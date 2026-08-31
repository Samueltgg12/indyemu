#include "io/hal2_audio.hpp"

#include <iostream>

namespace indyemu {

Hal2Audio::Hal2Audio() {
    reset();
}

void Hal2Audio::reset() {
    isr_ = 0;
    iar_ = 0;
    idr_.fill(0);
    dma_enable_ = 0;
    dma_drive_ = 0;
    dma_endian_ = 0;
    codec_a_ctrl1_ = 0;
    codec_a_ctrl2_ = 0;
    codec_b_ctrl1_ = 0;
    codec_b_ctrl2_ = 0;
    aes_tx_ctrl_ = 0;
    aes_rx_ctrl_ = 0;
    bres1_ctrl1_ = 0;
    bres1_ctrl2_ = 0;
    bres2_ctrl1_ = 0;
    bres2_ctrl2_ = 0;
    bres3_ctrl1_ = 0;
    bres3_ctrl2_ = 0;
    relay_control_ = 0;
}

bool Hal2Audio::contains(u32 address) const {
    return address >= kBase && address < (kBase + kSize);
}

u32 Hal2Audio::read32(u32 address) const {
    if (!contains(address)) {
        return 0;
    }
    const u32 offset = address - kBase;
    switch (offset) {
        case kIsrOffset:
            return isr_;
        case kRevOffset:
            return kRevision;
        case kIarOffset:
            return iar_;
        case kIdr0Offset:
            return idr_[0];
        case kIdr1Offset:
            return idr_[1];
        case kIdr2Offset:
            return idr_[2];
        case kIdr3Offset:
            return idr_[3];
        default:
            return 0;
    }
}

void Hal2Audio::write32(u32 address, u32 value) {
    if (!contains(address)) {
        return;
    }
    const u32 offset = address - kBase;
    switch (offset) {
        case kIsrOffset:
            isr_ = value;
            // ISR bit 3 (GLOBAL_RESET_N) low = reset the chip
            if ((value & 0x8u) == 0) {
                reset();
            }
            break;
        case kIarOffset:
            iar_ = value;
            // Writing to IAR commits the indirect register operation
            handleIarWrite(value);
            break;
        case kIdr0Offset:
            idr_[0] = value;
            break;
        case kIdr1Offset:
            idr_[1] = value;
            break;
        case kIdr2Offset:
            idr_[2] = value;
            break;
        case kIdr3Offset:
            idr_[3] = value;
            break;
        default:
            break;
    }
}

void Hal2Audio::handleIarWrite(u32 iar_value) {
    // Bit 15: 1 = read, 0 = write
    const bool is_read = (iar_value & 0x8000u) != 0;
    if (is_read) {
        // Read operations are handled by loading IDR on the next IDR read.
        // For simplicity, we load the value into IDR0 here.
        idr_[0] = handleIarRead(iar_value);
        return;
    }

    // Write operation: commit IDR0 (and IDR1 for 2-word registers) to the target
    switch (iar_value) {
        case kDmaEnableW:
            dma_enable_ = idr_[0];
            break;
        case kDmaDriveW:
            dma_drive_ = idr_[0];
            break;
        case kDmaEndianW:
            dma_endian_ = idr_[0];
            break;
        case kCodecACtrl1W:
            codec_a_ctrl1_ = idr_[0];
            break;
        case kCodecACtrl2W:
            codec_a_ctrl2_ = idr_[0];
            break;
        case kCodecBCtrl1W:
            codec_b_ctrl1_ = idr_[0];
            break;
        case kCodecBCtrl2W:
            codec_b_ctrl2_ = idr_[0];
            break;
        case kAesTxCtrlW:
            aes_tx_ctrl_ = idr_[0];
            break;
        case kAesRxCtrlW:
            aes_rx_ctrl_ = idr_[0];
            break;
        case kBres1Ctrl1W:
            bres1_ctrl1_ = idr_[0];
            break;
        case kBres1Ctrl2W:
            bres1_ctrl2_ = idr_[0];
            break;
        case kBres2Ctrl1W:
            bres2_ctrl1_ = idr_[0];
            break;
        case kBres2Ctrl2W:
            bres2_ctrl2_ = idr_[0];
            break;
        case kBres3Ctrl1W:
            bres3_ctrl1_ = idr_[0];
            break;
        case kBres3Ctrl2W:
            bres3_ctrl2_ = idr_[0];
            break;
        default:
            break;
    }
}

u32 Hal2Audio::handleIarRead(u32 iar_value) const {
    switch (iar_value) {
        case kDmaEnableR:
            return dma_enable_;
        case kDmaDriveR:
            return dma_drive_;
        default:
            return 0;
    }
}

void Hal2Audio::triggerStartupTone() {
    if (!enabled_) {
        return;
    }
    std::cout << "[hal2] PROM startup tone triggered\n";
}

}  // namespace indyemu
