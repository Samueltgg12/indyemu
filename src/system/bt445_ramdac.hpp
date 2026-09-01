// src/system/bt445_ramdac.hpp
//
// Bt445 150 MHz Monolithic CMOS Triple 256x8 RAMDAC.
// Faithful implementation of the Brooktree Bt445 used on the SGI Indy
// (Newport graphics). See hardware-docs/bt445_ramdac.pdf.
//
// The Bt445 is a DCB slave on the Newport Display Control Bus. REX3 is the
// DCB master and addresses this device via DCBADDR = 0111. The DCB's
// DCBCRS[2:0] and data width map onto the RAMDAC's MPU interface
// (C(2-0) control inputs + 8-bit ADDR register + 8-bit data bus).
//
// The MPU interface uses C(2-0) to select the register bank and an internal
// 8-bit ADDR register to select the register/palette entry within the bank.
// Color palette RAMs are loaded modulo-3 (R, G, B) and the address register
// auto-increments after the blue cycle.

#ifndef INDYEMU_BT445_RAMDAC_HPP
#define INDYEMU_BT445_RAMDAC_HPP

#include <array>
#include <cstdint>

namespace indyemu {

class Bt445Ramdac {
public:
    // MPU control select values (C(2-0)).
    enum ControlSelect : uint32_t {
        kCsAddressRegister = 0x0,   // C=000: load ADDR register
        kCsColorPalette    = 0x1,   // C=001: primary color palette RAM (256x24)
        kCsControlRegs     = 0x2,   // C=010: Bt458-compatible control registers
        kCsOverlayPalette  = 0x3,   // C=011: overlay color palette RAM (16 entries)
        kCsReserved4       = 0x4,   // C=100: reserved
        kCsFieldRegs       = 0x5,   // C=101: R/G/B/overlay/cursor field position+width regs
        kCsExtendedRegs    = 0x6,   // C=110: extended Bt445 registers
        kCsCursorColor     = 0x7,   // C=111: cursor color registers 0-3
    };

    Bt445Ramdac();
    ~Bt445Ramdac() = default;

    void reset();

    // DCB access. The REX3 DCB master calls these with the DCBCRS value
    // (which selects the MPU control bank) and the data width in bytes.
    // `crs` is the DCBCRS[2:0] field = the C(2-0) control select.
    void dcbWrite(uint32_t crs, uint32_t data, uint32_t width);
    uint32_t dcbRead(uint32_t crs, uint32_t width) const;

    // Pixel pipeline: given a raw pixel word (up to 32 bits) and the current
    // register state, produce the 24-bit RGB value that would be sent to the
    // DACs. Used by the display path to render the framebuffer.
    uint32_t processPixel(uint32_t pixel) const;

    // Accessors for the display path.
    uint32_t pixelDepth() const { return pixel_depth_; }
    uint32_t mpxRate() const { return mpx_rate_; }
    uint32_t pixelPortStart() const { return pixel_port_start_; }
    bool lsbUnpacking() const { return (pixel_format_ctrl_ & 0x80u) != 0; }

    // Palette access for tests / display.
    uint32_t paletteEntry(uint32_t index) const { return color_palette_[index & 0xFFu]; }
    uint32_t overlayEntry(uint32_t index) const { return overlay_palette_[index & 0xFu]; }
    uint32_t cursorColor(uint32_t index) const { return cursor_color_[index & 0x3u]; }

private:
    // --- MPU interface state ---
    uint8_t addr_reg_ = 0x00;      // ADDR(7-0)
    uint8_t color_cycle_ = 0;      // modulo-3 R/G/B cycle counter

    // --- Color palette RAMs ---
    // Stored as 24-bit RGB (R<<16 | G<<8 | B).
    std::array<uint32_t, 256> color_palette_{};
    std::array<uint32_t, 16> overlay_palette_{};
    std::array<uint32_t, 4> cursor_color_{};

    // --- Bt458-compatible control registers (C=010) ---
    uint8_t id_ = 0x3A;            // ID register
    uint8_t revision_ = 0xA0;      // Revision register
    uint8_t read_enable_ = 0xFF;   // Read Enable register (R/G/B)
    uint8_t blink_enable_ = 0x00;  // Blink Enable register (R/G/B)
    uint8_t command_reg0_ = 0x43;  // Command Register 0
    uint8_t test_reg0_ = 0x00;     // Test Register 0

    // --- Field position/width registers (C=101) ---
    // Each color has: MSB position, width, display enable, blink enable.
    uint8_t red_msb_ = 0x07, red_width_ = 0x08, red_display_ = 0xFF, red_blink_ = 0x00;
    uint8_t grn_msb_ = 0x07, grn_width_ = 0x08, grn_display_ = 0xFF, grn_blink_ = 0x00;
    uint8_t blu_msb_ = 0x07, blu_width_ = 0x08, blu_display_ = 0xFF, blu_blink_ = 0x00;
    uint8_t ovl_msb_ = 0x09, ovl_width_ = 0x02, ovl_display_ = 0x03, ovl_blink_ = 0x00;
    uint8_t cur_msb_ = 0x00, cur_width_ = 0x02, cur_display_ = 0x03, cur_blink_ = 0x00;

    // --- Extended registers (C=110) ---
    uint8_t test_reg1_ = 0x00;             // Test Register 1
    uint8_t command_reg1_ = 0x40;          // Command Register 1
    uint8_t digital_out_ctrl_ = 0x00;      // Digital Output Control
    uint8_t vidclk_cycle_ = 0x03;          // VIDCLK* Cycle Control
    uint8_t pixel_pll_rate0_ = 0x19;       // Pixel PLL Rate Register 0
    uint8_t pixel_pll_rate1_ = 0x04;       // Pixel PLL Rate Register 1
    uint8_t pll_ctrl_ = 0x00;              // PLL Control Register
    uint8_t pixel_load_ctrl_ = 0x04;       // Pixel Load Control
    uint8_t pixel_port_start_ = 0x28;      // Pixel Port Start Position
    uint8_t pixel_format_ctrl_ = 0x08;     // Pixel Format Control
    uint8_t mpx_rate_ = 0x03;              // MPX Rate Register
    uint8_t pixel_depth_ = 0x0A;           // Pixel Depth Control
    uint8_t bypass_pos_ = 0x00;            // Palette Bypass Position
    uint8_t bypass_width_ = 0x01;          // Palette Bypass Width

    // --- Helpers ---
    void writeControlReg(uint8_t addr, uint8_t data);
    uint8_t readControlReg(uint8_t addr) const;
    void writeFieldReg(uint8_t addr, uint8_t data);
    uint8_t readFieldReg(uint8_t addr) const;
    void writeExtendedReg(uint8_t addr, uint8_t data);
    uint8_t readExtendedReg(uint8_t addr) const;

    // Extract a bit field from a pixel: `msb` is the MSB position, `width`
    // the number of bits. Returns the field right-justified.
    static uint32_t extractField(uint32_t pixel, uint8_t msb, uint8_t width);

    // Expand a <8-bit color field to 8 bits by left-justify + MSB replication.
    static uint8_t expandTo8(uint32_t field, uint8_t width);
};

} // namespace indyemu

#endif // INDYEMU_BT445_RAMDAC_HPP