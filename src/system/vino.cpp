#include "system/vino.hpp"

#include <iostream>

namespace indyemu {

Vino::Vino() {
    reset();
}

void Vino::reset() {
    regs_.fill(0);
    // Rev/ID register: VINO ID value B in bits 7:4, revision 0 in bits 3:0.
    regs_[REV_ID / 4u] = 0x000000B0u;
    std::cout << "[vino] VINO reset\n";
}

bool Vino::contains(uint32_t address) const {
    return address >= kBase && address < (kBase + kSize);
}

uint32_t Vino::read32(uint32_t address) const {
    if (!contains(address)) {
        return 0;
    }
    const uint32_t offset = address - kBase;
    const uint32_t index = offset / 4u;
    if (index >= regs_.size()) {
        return 0;
    }
    return regs_[index];
}

void Vino::write32(uint32_t address, uint32_t value) {
    if (!contains(address)) {
        return;
    }
    const uint32_t offset = address - kBase;
    const uint32_t index = offset / 4u;
    if (index >= regs_.size()) {
        return;
    }

    // Read-only registers ignore writes.
    switch (static_cast<Register>(offset & ~0x3u)) {
        case REV_ID:
        case CHA_FIELD_COUNTER:
        case CHA_FIFO_GIO_PTR:
        case CHA_FIFO_VIDEO_PTR:
        case CHB_FIELD_COUNTER:
        case CHB_FIFO_GIO_PTR:
        case CHB_FIFO_VIDEO_PTR:
            return;
        default:
            break;
    }

    regs_[index] = value;
}

std::string Vino::descriptionFor(uint32_t address) const {
    if (!contains(address)) {
        return "VINO (out of range)";
    }
    const uint32_t offset = address - kBase;
    switch (static_cast<Register>(offset & ~0x3u)) {
        case REV_ID:               return "VINO Rev/ID";
        case CONTROL:              return "VINO Control";
        case INTERRUPT_STATUS:     return "VINO Interrupt Status";
        case IC_CONTROL:           return "VINO IC Control";
        case IC_DATA:              return "VINO IC Data";
        case CHA_ALPHA:            return "VINO ChA Alpha";
        case CHA_CLIP_START:       return "VINO ChA Clipping Start";
        case CHA_CLIP_END:         return "VINO ChA Clipping End";
        case CHA_FRAME_RATE:       return "VINO ChA Frame Rate";
        case CHA_FIELD_COUNTER:    return "VINO ChA Field Counter";
        case CHA_LINE_SIZE:        return "VINO ChA Line Size";
        case CHA_LINE_COUNT:       return "VINO ChA Line Count";
        case CHA_PAGE_INDEX:       return "VINO ChA Page Index";
        case CHA_NEXT_DESCRIPTOR:  return "VINO ChA Next Descriptor";
        case CHA_START_DESCRIPTOR: return "VINO ChA Start Descriptor";
        case CHA_DESC0:            return "VINO ChA Descriptor 0";
        case CHA_DESC1:            return "VINO ChA Descriptor 1";
        case CHA_DESC2:            return "VINO ChA Descriptor 2";
        case CHA_DESC3:            return "VINO ChA Descriptor 3";
        case CHA_FIFO_THRESHOLD:   return "VINO ChA FIFO Threshold";
        case CHA_FIFO_GIO_PTR:     return "VINO ChA FIFO GIO Pointer";
        case CHA_FIFO_VIDEO_PTR:   return "VINO ChA FIFO Video Pointer";
        case CHB_ALPHA:            return "VINO ChB Alpha";
        case CHB_CLIP_START:       return "VINO ChB Clipping Start";
        case CHB_CLIP_END:         return "VINO ChB Clipping End";
        case CHB_FRAME_RATE:       return "VINO ChB Frame Rate";
        case CHB_FIELD_COUNTER:    return "VINO ChB Field Counter";
        case CHB_LINE_SIZE:        return "VINO ChB Line Size";
        case CHB_LINE_COUNT:       return "VINO ChB Line Count";
        case CHB_PAGE_INDEX:       return "VINO ChB Page Index";
        case CHB_NEXT_DESCRIPTOR:  return "VINO ChB Next Descriptor";
        case CHB_START_DESCRIPTOR: return "VINO ChB Start Descriptor";
        case CHB_DESC0:            return "VINO ChB Descriptor 0";
        case CHB_DESC1:            return "VINO ChB Descriptor 1";
        case CHB_DESC2:            return "VINO ChB Descriptor 2";
        case CHB_DESC3:            return "VINO ChB Descriptor 3";
        case CHB_FIFO_THRESHOLD:   return "VINO ChB FIFO Threshold";
        case CHB_FIFO_GIO_PTR:     return "VINO ChB FIFO GIO Pointer";
        case CHB_FIFO_VIDEO_PTR:   return "VINO ChB FIFO Video Pointer";
        default:                   return "VINO register";
    }
}

} // namespace indyemu