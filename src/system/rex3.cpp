// src/system/rex3.cpp
#include "rex3.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

namespace indyemu {

Rex3::Rex3() {
    reset();
}

void Rex3::reset() {
    regs_.fill(0);
    framebuffer_.fill(0);
    enabled_ = true;
    go_pending_ = false;
    std::cout << "[rex3] REX3 reset\n";
}

bool Rex3::contains(uint32_t address) const {
    return address >= kBase && address < (kBase + kSize);
}

uint32_t Rex3::read32(uint32_t address) const {
    if (!contains(address)) {
        return 0u;
    }
    const uint32_t offset = address - kBase;
    if (offset < 0x2000u) {
        // Register range (first 8KB)
        const std::size_t index = offset / 4u;
        if (index >= regs_.size()) {
            return 0u;
        }
        // Debug: print register reads
        if (offset < 0x1000) {  // Only first 4KB of registers
            std::cout << "[rex3] READ32: offset 0x" << std::hex << offset
                      << " -> 0x" << regs_[index] << std::dec << "\n";
        }
        return regs_[index];
    } else {
        // Framebuffer range (starting at offset 0x2000)
        const uint32_t fb_offset = offset - 0x2000u;
        const std::size_t index = fb_offset / 4u;
        if (index >= framebuffer_.size()) {
            return 0u;
        }
        // Debug: print framebuffer reads occasionally
        if ((fb_offset & 0xFFFF) == 0) {  // Every 64KB in framebuffer
            std::cout << "[rex3] FB READ32: offset 0x" << std::hex << offset
                      << " -> 0x" << framebuffer_[index] << std::dec << "\n";
        }
        return framebuffer_[index];
    }
}

void Rex3::write32(uint32_t address, uint32_t value) {
    if (!contains(address)) {
        return;
    }
    const uint32_t offset = address - kBase;

    if (offset < 0x2000u) {
        // Register range (first 8KB: 0x0000-0x1FFF)
        // Check for implicit GO trigger: writing to offset + 0x800 triggers GO on the register at offset
        bool go_triggered = false;
        uint32_t reg_offset = offset;

        if (offset >= 0x800u && offset < 0x1000u) {
            // This write is in the GO trigger range (0x0800-0x0FFF)
            // The actual register being written to is at offset - 0x800
            reg_offset = offset - 0x800u;
            go_triggered = true;
        }

        // Validate register offset is within our register space (first 2KB: 0x0000-0x07FF)
        if (reg_offset < 0x0800u) {
            const std::size_t index = reg_offset / 4u;
            if (index < regs_.size()) {
                regs_[index] = value;

                // Handle specific register side effects
                switch (static_cast<Register>(reg_offset)) {
                    case DRAWMODE0:
                    case DRAWMODE1:
                        // Handle enabling/disabling
                        if (reg_offset == DRAWMODE1) {
                            enabled_ = (value != 0u);
                        }
                        break;
                    default:
                        break;
                }

                // If this write triggered an implicit GO, then we set the go_pending_ flag.
                // In a real implementation, we would start executing the graphics command here.
                if (go_triggered) {
                    go_pending_ = true;
                    std::cout << "[rex3] Implicit GO command triggered at offset 0x"
                              << std::hex << reg_offset << ", value=0x" << std::hex << value << std::dec << "\n";
                    // TODO: Actually execute the command based on the current register state.
                }
            }
        }
        // Note: Writes to registers beyond 0x07FF are ignored (reserved/unimplemented space)
    } else {
        // Framebuffer range (starting at offset 0x2000)
        const uint32_t fb_offset = offset - 0x2000u;
        const std::size_t index = fb_offset / 4u;
        if (index < framebuffer_.size()) {
            framebuffer_[index] = value;
            // Debug output for framebuffer writes
            if (offset % 0x1000 == 0) {  // Every 4KB
                std::cout << "[rex3] Framebuffer write at offset 0x" << std::hex << offset
                          << ", value=0x" << value << std::dec << "\n";
            }
        }
        // Note: Writes beyond framebuffer size are ignored
    }
}

std::string Rex3::descriptionFor(uint32_t address) const {
    if (!contains(address)) {
        return "unknown address";
    }
    const uint32_t offset = address - kBase;
    // We could map known register offsets to names, but for now return generic.
    return "REX3 register";
}

// Fixed-point conversion helpers
int32_t Rex3::from16_4_7(uint32_t value) {
    // Extract bits 7-26: 4 fractional bits (bits 7-10) and 16 integer bits (bits 11-26)
    // The value is sign-extended from bit 26.
    int32_t signed_val = static_cast<int32_t>(value << 6); // Shift left by 6 to move bit 26 to sign bit
    signed_val >>= 6; // Arithmetic right shift to sign-extend
    // Now we have the integer part in the upper 16 bits and fractional in lower 4? Actually we want:
    // Bits 7-10: fractional, bits 11-26: integer (16 bits)
    // So we can do:
    int32_t fraction = (value >> 7) & 0xF; // bits 7-10
    int32_t integer = (static_cast<int32_t>(value >> 11)) & 0xFFFF; // bits 11-26
    // Sign extend the integer from 16 bits
    if (integer & 0x8000) {
        integer |= 0xFFFF0000;
    }
    return (integer << 4) | fraction;
}

uint32_t Rex3::to16_4_7(int32_t value) {
    // We need to pack: integer (16 bits) in bits 11-26, fraction (4 bits) in bits 7-10, bits 0-6 zero.
    // First, extract integer and fraction from the fixed-point value.
    // The input value is in 16.4 format (16 integer, 4 fraction) but we store it shifted by 7? Actually our storage is:
    // bits 0-6: unused (0)
    // bits 7-10: fraction
    // bits 11-26: integer (16 bits, sign extended)
    // So we take the integer part (value >> 4) and fraction part (value & 0xF)
    int32_t integer = value >> 4;
    int32_t fraction = value & 0xF;
    // Clamp integer to 16 bits
    if (integer > 0x7FFF) integer = 0x7FFF;
    if (integer < -0x8000) integer = -0x8000;
    uint32_t result = 0;
    result |= (static_cast<uint32_t>(integer & 0xFFFF) << 11);
    result |= (static_cast<uint32_t>(fraction & 0xF) << 7);
    return result;
}

int32_t Rex3::from12_4_7(uint32_t value) {
    // Similar to 16.4_7 but integer part is 12 bits (bits 7-18) and fraction 4 bits (bits 3-6?) Wait, the spec says:
    // For the float/GL mapping views: force-zero the 4 most significant integer bits.
    // So the format is still 16.4(7) but the top 4 bits of the integer are zeroed.
    // We'll reuse the same as 16.4_7 but then clear the top 4 bits of the integer part.
    int32_t val = from16_4_7(value);
    // Clear bits 15-12 (the top 4 bits of the 16-bit integer) -> actually we want to zero the 4 most significant of the 16 bits?
    // The 16-bit integer is in bits 4-19 of the 32-bit value? Let's think: we have 16 integer bits and 4 fractional.
    // In our representation, the integer is stored in bits 4-19 (with bit 19 being the sign?).
    // Actually, we stored the 16-bit integer in the lower 16 bits of the 32-bit integer (after shifting) and then sign extended.
    // So to zero the top 4 bits of the 16-bit integer, we do:
    val &= 0x0FFF; // Keep lower 12 bits
    // Sign extend from 12 bits
    if (val & 0x0800) {
        val |= 0xF000;
    }
    return val;
}

uint32_t Rex3::to12_4_7(int32_t value) {
    // First convert to 16.4_7 then zero the top 4 bits of the integer part.
    uint32_t res = to16_4_7(value);
    // Now we need to zero the top 4 bits of the integer part in the stored format.
    // In the stored format, the integer part is in bits 11-26. We want to zero bits 23-26 (the top 4 of the 16 bits).
    res &= 0x00FFFFFF; // Clear bits 24-31? Actually we want to clear bits 23-26 (which are in the upper part of the integer field).
    // Let's break down: bits 11-26 are the integer (16 bits). We want to zero the highest 4 bits of these 16 bits, i.e., bits 23-26.
    // So we clear bits 23-26.
    res &= ~(0xF << 23);
    return res;
}

} // namespace indyemu