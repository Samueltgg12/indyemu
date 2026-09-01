// src/system/bt445_ramdac.cpp
#include "bt445_ramdac.hpp"

#include <algorithm>

namespace indyemu {

Bt445Ramdac::Bt445Ramdac() {
    reset();
}

void Bt445Ramdac::reset() {
    addr_reg_ = 0x00;
    color_cycle_ = 0;
    color_palette_.fill(0);
    overlay_palette_.fill(0);
    cursor_color_.fill(0);

    id_ = 0x3A;
    revision_ = 0xA0;
    read_enable_ = 0xFF;
    blink_enable_ = 0x00;
    command_reg0_ = 0x43;
    test_reg0_ = 0x00;

    red_msb_ = 0x07; red_width_ = 0x08; red_display_ = 0xFF; red_blink_ = 0x00;
    grn_msb_ = 0x07; grn_width_ = 0x08; grn_display_ = 0xFF; grn_blink_ = 0x00;
    blu_msb_ = 0x07; blu_width_ = 0x08; blu_display_ = 0xFF; blu_blink_ = 0x00;
    ovl_msb_ = 0x09; ovl_width_ = 0x02; ovl_display_ = 0x03; ovl_blink_ = 0x00;
    cur_msb_ = 0x00; cur_width_ = 0x02; cur_display_ = 0x03; cur_blink_ = 0x00;

    test_reg1_ = 0x00;
    command_reg1_ = 0x40;
    digital_out_ctrl_ = 0x00;
    vidclk_cycle_ = 0x03;
    pixel_pll_rate0_ = 0x19;
    pixel_pll_rate1_ = 0x04;
    pll_ctrl_ = 0x00;
    pixel_load_ctrl_ = 0x04;
    pixel_port_start_ = 0x28;
    pixel_format_ctrl_ = 0x08;
    mpx_rate_ = 0x03;
    pixel_depth_ = 0x0A;
    bypass_pos_ = 0x00;
    bypass_width_ = 0x01;
}

// ---------------------------------------------------------------------------
// DCB access
// ---------------------------------------------------------------------------

void Bt445Ramdac::dcbWrite(uint32_t crs, uint32_t data, uint32_t width) {
    const uint8_t byte = static_cast<uint8_t>(data & 0xFFu);
    switch (crs & 0x7u) {
        case kCsAddressRegister:
            // Loading the address register resets the modulo-3 color cycle.
            addr_reg_ = byte;
            color_cycle_ = 0;
            break;
        case kCsColorPalette: {
            // Modulo-3 R/G/B loading. On the blue write, the 3 bytes are
            // concatenated into a 24-bit word and written to the palette.
            const uint32_t index = addr_reg_;
            if (color_cycle_ == 0) {
                color_palette_[index] = (color_palette_[index] & 0x00FFFFu) | (static_cast<uint32_t>(byte) << 16);
            } else if (color_cycle_ == 1) {
                color_palette_[index] = (color_palette_[index] & 0xFF00FFu) | (static_cast<uint32_t>(byte) << 8);
            } else {
                color_palette_[index] = (color_palette_[index] & 0xFFFF00u) | byte;
                // Address register increments after the blue cycle.
                addr_reg_ = static_cast<uint8_t>(addr_reg_ + 1u);
            }
            color_cycle_ = static_cast<uint8_t>((color_cycle_ + 1u) % 3u);
            break;
        }
        case kCsControlRegs:
            writeControlReg(addr_reg_, byte);
            break;
        case kCsOverlayPalette: {
            const uint32_t index = addr_reg_ & 0xFu;
            if (color_cycle_ == 0) {
                overlay_palette_[index] = (overlay_palette_[index] & 0x00FFFFu) | (static_cast<uint32_t>(byte) << 16);
            } else if (color_cycle_ == 1) {
                overlay_palette_[index] = (overlay_palette_[index] & 0xFF00FFu) | (static_cast<uint32_t>(byte) << 8);
            } else {
                overlay_palette_[index] = (overlay_palette_[index] & 0xFFFF00u) | byte;
                addr_reg_ = static_cast<uint8_t>(addr_reg_ + 1u);
            }
            color_cycle_ = static_cast<uint8_t>((color_cycle_ + 1u) % 3u);
            break;
        }
        case kCsReserved4:
            break;
        case kCsFieldRegs:
            writeFieldReg(addr_reg_, byte);
            break;
        case kCsExtendedRegs:
            writeExtendedReg(addr_reg_, byte);
            break;
        case kCsCursorColor: {
            const uint32_t index = addr_reg_ & 0x3u;
            if (color_cycle_ == 0) {
                cursor_color_[index] = (cursor_color_[index] & 0x00FFFFu) | (static_cast<uint32_t>(byte) << 16);
            } else if (color_cycle_ == 1) {
                cursor_color_[index] = (cursor_color_[index] & 0xFF00FFu) | (static_cast<uint32_t>(byte) << 8);
            } else {
                cursor_color_[index] = (cursor_color_[index] & 0xFFFF00u) | byte;
                addr_reg_ = static_cast<uint8_t>(addr_reg_ + 1u);
            }
            color_cycle_ = static_cast<uint8_t>((color_cycle_ + 1u) % 3u);
            break;
        }
        default:
            break;
    }
}

uint32_t Bt445Ramdac::dcbRead(uint32_t crs, uint32_t width) const {
    uint8_t value = 0;
    switch (crs & 0x7u) {
        case kCsAddressRegister:
            value = addr_reg_;
            break;
        case kCsColorPalette: {
            const uint32_t index = addr_reg_;
            const uint32_t entry = color_palette_[index];
            if (color_cycle_ == 0) {
                value = static_cast<uint8_t>((entry >> 16) & 0xFFu);
            } else if (color_cycle_ == 1) {
                value = static_cast<uint8_t>((entry >> 8) & 0xFFu);
            } else {
                value = static_cast<uint8_t>(entry & 0xFFu);
            }
            break;
        }
        case kCsControlRegs:
            value = readControlReg(addr_reg_);
            break;
        case kCsOverlayPalette: {
            const uint32_t index = addr_reg_ & 0xFu;
            const uint32_t entry = overlay_palette_[index];
            if (color_cycle_ == 0) {
                value = static_cast<uint8_t>((entry >> 16) & 0xFFu);
            } else if (color_cycle_ == 1) {
                value = static_cast<uint8_t>((entry >> 8) & 0xFFu);
            } else {
                value = static_cast<uint8_t>(entry & 0xFFu);
            }
            break;
        }
        case kCsReserved4:
            break;
        case kCsFieldRegs:
            value = readFieldReg(addr_reg_);
            break;
        case kCsExtendedRegs:
            value = readExtendedReg(addr_reg_);
            break;
        case kCsCursorColor: {
            const uint32_t index = addr_reg_ & 0x3u;
            const uint32_t entry = cursor_color_[index];
            if (color_cycle_ == 0) {
                value = static_cast<uint8_t>((entry >> 16) & 0xFFu);
            } else if (color_cycle_ == 1) {
                value = static_cast<uint8_t>((entry >> 8) & 0xFFu);
            } else {
                value = static_cast<uint8_t>(entry & 0xFFu);
            }
            break;
        }
        default:
            break;
    }
    return value;
}

// ---------------------------------------------------------------------------
// Control register access
// ---------------------------------------------------------------------------

void Bt445Ramdac::writeControlReg(uint8_t addr, uint8_t data) {
    switch (addr) {
        case 0x00: // Address register (also accessible via C=000)
            addr_reg_ = data;
            color_cycle_ = 0;
            break;
        case 0x01: // Primary color palette RAM (also accessible via C=001)
            // Handled via the palette path; ignore here.
            break;
        case 0x04: // Read Enable register (writes R/G/B read enable simultaneously)
            read_enable_ = data;
            break;
        case 0x05: // Blink Enable register
            blink_enable_ = data;
            break;
        case 0x06: // Command Register 0
            command_reg0_ = data;
            break;
        case 0x07: // Test Register 0 (upper 4 bits ignored on write)
            test_reg0_ = data & 0x0Fu;
            break;
        default:
            break;
    }
}

uint8_t Bt445Ramdac::readControlReg(uint8_t addr) const {
    switch (addr) {
        case 0x00: return addr_reg_;
        case 0x01: return 0x00; // palette RAM read handled via C=001
        case 0x02: return 0x00; // reserved
        case 0x03: return 0x00; // reserved
        case 0x04: return read_enable_;
        case 0x05: return blink_enable_;
        case 0x06: return command_reg0_;
        case 0x07: return test_reg0_;
        case 0x3A: return id_;
        case 0xA0: return revision_;
        default: return 0x00;
    }
}

void Bt445Ramdac::writeFieldReg(uint8_t addr, uint8_t data) {
    switch (addr) {
        case 0x00: red_msb_ = data; break;
        case 0x01: red_width_ = data; break;
        case 0x02: red_display_ = data; break;
        case 0x03: red_blink_ = data; break;
        case 0x08: grn_msb_ = data; break;
        case 0x09: grn_width_ = data; break;
        case 0x0A: grn_display_ = data; break;
        case 0x0B: grn_blink_ = data; break;
        case 0x10: blu_msb_ = data; break;
        case 0x11: blu_width_ = data; break;
        case 0x12: blu_display_ = data; break;
        case 0x13: blu_blink_ = data; break;
        case 0x18: ovl_msb_ = data; break;
        case 0x19: ovl_width_ = data; break;
        case 0x1A: ovl_display_ = data; break;
        case 0x1B: ovl_blink_ = data; break;
        case 0x20: cur_msb_ = data; break;
        case 0x21: cur_width_ = data; break;
        case 0x22: cur_display_ = data; break;
        case 0x23: cur_blink_ = data; break;
        default: break;
    }
}

uint8_t Bt445Ramdac::readFieldReg(uint8_t addr) const {
    switch (addr) {
        case 0x00: return red_msb_;
        case 0x01: return red_width_;
        case 0x02: return red_display_;
        case 0x03: return red_blink_;
        case 0x08: return grn_msb_;
        case 0x09: return grn_width_;
        case 0x0A: return grn_display_;
        case 0x0B: return grn_blink_;
        case 0x10: return blu_msb_;
        case 0x11: return blu_width_;
        case 0x12: return blu_display_;
        case 0x13: return blu_blink_;
        case 0x18: return ovl_msb_;
        case 0x19: return ovl_width_;
        case 0x1A: return ovl_display_;
        case 0x1B: return ovl_blink_;
        case 0x20: return cur_msb_;
        case 0x21: return cur_width_;
        case 0x22: return cur_display_;
        case 0x23: return cur_blink_;
        default: return 0x00;
    }
}

void Bt445Ramdac::writeExtendedReg(uint8_t addr, uint8_t data) {
    switch (addr) {
        case 0x00: test_reg1_ = data; break;
        case 0x01: command_reg1_ = data; break;
        case 0x02: digital_out_ctrl_ = data; break;
        case 0x03: vidclk_cycle_ = data; break;
        case 0x05: pixel_pll_rate0_ = data; break;
        case 0x06: pixel_pll_rate1_ = data; break;
        case 0x07: pll_ctrl_ = data; break;
        case 0x08: pixel_load_ctrl_ = data; break;
        case 0x09: pixel_port_start_ = data; break;
        case 0x0A: pixel_format_ctrl_ = data; break;
        case 0x0B: mpx_rate_ = data; break;
        case 0x0D: pixel_depth_ = data; break;
        case 0x0E: bypass_pos_ = data; break;
        case 0x0F: bypass_width_ = data; break;
        default: break;
    }
}

uint8_t Bt445Ramdac::readExtendedReg(uint8_t addr) const {
    switch (addr) {
        case 0x00: return test_reg1_;
        case 0x01: return command_reg1_;
        case 0x02: return digital_out_ctrl_;
        case 0x03: return vidclk_cycle_;
        case 0x05: return pixel_pll_rate0_;
        case 0x06: return pixel_pll_rate1_;
        case 0x07: return pll_ctrl_;
        case 0x08: return pixel_load_ctrl_;
        case 0x09: return pixel_port_start_;
        case 0x0A: return pixel_format_ctrl_;
        case 0x0B: return mpx_rate_;
        case 0x0D: return pixel_depth_;
        case 0x0E: return bypass_pos_;
        case 0x0F: return bypass_width_;
        default: return 0x00;
    }
}

// ---------------------------------------------------------------------------
// Pixel pipeline
// ---------------------------------------------------------------------------

uint32_t Bt445Ramdac::extractField(uint32_t pixel, uint8_t msb, uint8_t width) {
    if (width == 0) {
        return 0;
    }
    // The field occupies bits [msb-width+1 .. msb] of the pixel.
    const int32_t low = static_cast<int32_t>(msb) - static_cast<int32_t>(width) + 1;
    if (low < 0) {
        return 0;
    }
    const uint32_t mask = (width >= 32) ? 0xFFFFFFFFu : ((1u << width) - 1u);
    return (pixel >> low) & mask;
}

uint8_t Bt445Ramdac::expandTo8(uint32_t field, uint8_t width) {
    if (width == 0) {
        return 0;
    }
    if (width >= 8) {
        return static_cast<uint8_t>(field & 0xFFu);
    }
    // Left-justify and replicate the MSBs into the low bits.
    uint8_t result = static_cast<uint8_t>(field & ((1u << width) - 1u));
    result = static_cast<uint8_t>(result << (8 - width));
    // Replicate the top `width` bits into the low `8-width` bits.
    uint8_t top = static_cast<uint8_t>(result >> (8 - width));
    uint8_t fill = 0;
    for (uint8_t i = 0; i < (8 - width); ++i) {
        fill = static_cast<uint8_t>((fill << 1) | ((top >> (width - 1)) & 1u));
    }
    return static_cast<uint8_t>(result | fill);
}

uint32_t Bt445Ramdac::processPixel(uint32_t pixel) const {
    // Extract the color fields from the pixel.
    const uint32_t red_field = extractField(pixel, red_msb_, red_width_);
    const uint32_t grn_field = extractField(pixel, grn_msb_, grn_width_);
    const uint32_t blu_field = extractField(pixel, blu_msb_, blu_width_);
    const uint32_t ovl_field = extractField(pixel, ovl_msb_, ovl_width_);
    const uint32_t cur_field = extractField(pixel, cur_msb_, cur_width_);
    const uint32_t bypass_field = extractField(pixel, bypass_pos_, bypass_width_);

    // Apply read masks (display enable) to the color fields.
    uint8_t r = static_cast<uint8_t>(red_field & red_display_);
    uint8_t g = static_cast<uint8_t>(grn_field & grn_display_);
    uint8_t b = static_cast<uint8_t>(blu_field & blu_display_);

    // Apply blink masks (a set bit forces the plane off).
    r = static_cast<uint8_t>(r & ~red_blink_);
    g = static_cast<uint8_t>(g & ~grn_blink_);
    b = static_cast<uint8_t>(b & ~blu_blink_);

    // Determine palette bypass.
    const uint8_t bypass_ctrl = pixel_format_ctrl_ & 0x3u;
    bool bypass = false;
    if (bypass_ctrl == 0x1u) {
        bypass = true; // always bypass
    } else if (bypass_ctrl == 0x2u) {
        bypass = (bypass_field != 0); // use input pixel field
    }

    // Overlay handling: if overlay enabled and overlay field nonzero, use the
    // overlay palette (which overrides the color palette).
    const bool overlay_enabled = (pixel_format_ctrl_ & 0x8u) != 0;
    const bool overlay_active = overlay_enabled && (ovl_field != 0);

    // Cursor handling: if cursor enabled and cursor field nonzero, use cursor color.
    const bool cursor_enabled = (pixel_format_ctrl_ & 0x20u) != 0;
    const bool cursor_active = cursor_enabled && (cur_field != 0);

    if (cursor_active) {
        return cursor_color_[cur_field & 0x3u];
    }

    if (overlay_active) {
        return overlay_palette_[ovl_field & 0xFu];
    }

    if (bypass) {
        // Palette bypass: expand the color fields to 8 bits and use directly.
        return (static_cast<uint32_t>(expandTo8(r, red_width_)) << 16) |
               (static_cast<uint32_t>(expandTo8(g, grn_width_)) << 8) |
               static_cast<uint32_t>(expandTo8(b, blu_width_));
    }

    // Palette lookup: use the (masked) color fields as palette indices.
    const uint32_t index = (static_cast<uint32_t>(r) << 16) |
                           (static_cast<uint32_t>(g) << 8) |
                           static_cast<uint32_t>(b);
    // In pseudo-color mode, R/G/B fields are the same, so use the red field
    // as the palette index.
    const uint32_t pal_index = red_field & 0xFFu;
    return color_palette_[pal_index & 0xFFu];
}

} // namespace indyemu