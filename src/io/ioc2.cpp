#include "io/ioc2.hpp"

namespace indyemu {

Ioc2Controller::Ioc2Controller() {
    reset();
}

void Ioc2Controller::reset() {
    l0_stat_ = 0;
    l0_mask_ = 0;
    l1_stat_ = 0;
    l1_mask_ = 0;
    map_stat_ = 0;
    map_mask0_ = 0;
    map_mask1_ = 0;
    map_pol_ = 0;
    ip2_active_ = false;
    ip3_active_ = false;
}

bool Ioc2Controller::contains(u32 address) const {
    return address >= kBase && address < (kBase + kSize);
}

u32 Ioc2Controller::read32(u32 address) const {
    if (!contains(address)) {
        return 0;
    }
    const u32 offset = address - kBase;
    // All IOC2 registers are 8-bit, but we return them as part of a 32-bit word
    // MIPS is big-endian, so byte offset 0 is bits 24-31
    u8 value = 0;

    switch (offset) {
        case kL0StatOffset:
            value = l0_stat_;
            break;
        case kL0MaskOffset:
            value = l0_mask_;
            break;
        case kL1StatOffset:
            value = l1_stat_;
            break;
        case kL1MaskOffset:
            value = l1_mask_;
            break;
        case kMapStatOffset:
            value = map_stat_;
            break;
        case kMapMask0Offset:
            value = map_mask0_;
            break;
        case kMapMask1Offset:
            value = map_mask1_;
            break;
        case kMapPolOffset:
            value = map_pol_;
            break;
        default:
            return 0;
    }
    
    // Return as 32-bit value (replicate 8-bit value across all bytes for big-endian)
    return static_cast<u32>(value) << 24;
}

void Ioc2Controller::write32(u32 address, u32 value) {
    if (!contains(address)) {
        return;
    }
    const u32 offset = address - kBase;
    // Extract the 8-bit value from the appropriate byte
    u8 byte_val = static_cast<u8>((value >> 24) & 0xFFu);

    switch (offset) {
        case kL0StatOffset:
            // Status registers are read-only, writing has no effect
            break;
        case kL0MaskOffset:
            l0_mask_ = byte_val;
            break;
        case kL1StatOffset:
            // Status registers are read-only
            break;
        case kL1MaskOffset:
            l1_mask_ = byte_val;
            break;
        case kMapStatOffset:
            // Status registers are read-only
            break;
        case kMapMask0Offset:
            map_mask0_ = byte_val;
            break;
        case kMapMask1Offset:
            map_mask1_ = byte_val;
            break;
        case kMapPolOffset:
            map_pol_ = byte_val;
            break;
        default:
            break;
    }
}

void Ioc2Controller::assertInterrupt(Local0Interrupt int_bit) {
    l0_stat_ |= static_cast<u8>(int_bit);
}

void Ioc2Controller::clearInterrupt(Local0Interrupt int_bit) {
    l0_stat_ &= ~static_cast<u8>(int_bit);
}

void Ioc2Controller::assertInterrupt(Local1Interrupt int_bit) {
    l1_stat_ |= static_cast<u8>(int_bit);
}

void Ioc2Controller::clearInterrupt(Local1Interrupt int_bit) {
    l1_stat_ &= ~static_cast<u8>(int_bit);
}

void Ioc2Controller::assertInterrupt(MapInterrupt int_bit) {
    map_stat_ |= static_cast<u8>(int_bit);
}

void Ioc2Controller::clearInterrupt(MapInterrupt int_bit) {
    map_stat_ &= ~static_cast<u8>(int_bit);
}

u8 Ioc2Controller::isEnabled(InterruptLine line) const {
    switch (line) {
        case InterruptLine::kIP2:
            // IP2 is active if either L0 has pending masked interrupt or MAP produces MAP_INT0
            if ((l0_stat_ & l0_mask_) != 0) {
                return l0_stat_ & l0_mask_;
            }
            if ((map_stat_ & map_mask0_) != 0) {
                return (static_cast<u8>(Local0Interrupt::kMapInt0));
            }
            return 0;
        case InterruptLine::kIP3:
            // IP3 is active if either L1 has pending masked interrupt or MAP produces MAP_INT1
            if ((l1_stat_ & l1_mask_) != 0) {
                return l1_stat_ & l1_mask_;
            }
            if ((map_stat_ & map_mask1_) != 0) {
                return (static_cast<u8>(Local1Interrupt::kGio2));
            }
            return 0;
        default:
            return 0;
    }
}

bool Ioc2Controller::hasPendingInterrupt(InterruptLine line) const {
    return isEnabled(line) != 0;
}

u32 Ioc2Controller::pendingInterruptLines() const {
    u32 lines = 0;
    // IP2 is driven by LOCAL0 (and MAP_INT0 via L0 bit 7)
    if (hasPendingInterrupt(InterruptLine::kIP2)) {
        lines |= (1u << static_cast<u32>(InterruptLine::kIP2));
    }
    // IP3 is driven by LOCAL1 (and MAP_INT1 via L1 bit 3)
    if (hasPendingInterrupt(InterruptLine::kIP3)) {
        lines |= (1u << static_cast<u32>(InterruptLine::kIP3));
    }
    return lines;
}

}  // namespace indyemu
