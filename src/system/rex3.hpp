#ifndef INDYEMU_REX3_HPP
#define INDYEMU_REX3_HPP

#include <cstdint>
#include <array>
#include <string>
#include "system/gio64_bus.hpp"

namespace indyemu {

class Rex3 : public IODevice {
public:
    static constexpr uint32_t kBase = 0x1F000000u;
    static constexpr uint32_t kSize = 0x00400000u; // GIO64 slot 0: 4MB range

    // Register offsets
    enum Register : uint32_t {
        // Command & Mode Registers
        DRAWMODE1 = 0x0000,
        DRAWMODE0 = 0x0004,

        // Relative Coordinates & Screen Masks
        XYMOVE = 0x0114,
        XYWIN = 0x1324,
        SMASK0X = 0x0028,
        SMASK0Y = 0x002C,
        // SMASK1X-SMASK4Y: 0x1300-0x131C

        // Bresenham Parameter Registers
        BRESD = 0x0118,
        BRESS1 = 0x011C,
        BRESS2 = 0x012C,
        BRESOCTINC1 = 0x0120,
        BRESRNDINC2 = 0x0124,
        BRESE1 = 0x0128,

        // Color & Shading Registers
        COLORRED = 0x0200,
        COLORALPHA = 0x0204,
        COLORGRN = 0x0208,
        COLORBLUE = 0x020C,
        COLORI = 0x0224,
        COLORX = 0x0228,
        COLORBACK = 0x0018,
        COLORVRAM = 0x001C,
        SLOPERED = 0x0210,
        SLOPEALPHA = 0x0214,
        SLOPEGRN = 0x0218,
        SLOPEBLUE = 0x021C,

        // Stipple, Pattern, & Host Data Registers
        LSMODE = 0x0008,
        LSPATTERN = 0x000C,
        ZPATTERN = 0x0014,
        LSSAVE = 0x003C,
        LSRESTORE = 0x0038,
        AWEIGHT0 = 0x0130,
        AWEIGHT1 = 0x0134,
        HOSTRW0 = 0x0230,
        HOSTRW1 = 0x0234,
        WRMASK = 0x0220,

        // Configuration, Command Triggers, and Status
        CONFIG = 0x1330,
        STATUS = 0x1338,
        USER_STATUS = 0x133C,
        STALL0 = 0x0024,
        STALL1 = 0x132C,
        SETUP = 0x0030,
        STEPZ = 0x0034,

        // Display Control Bus (DCB) Registers
        DCBMODE = 0x0238,
        DCBDATA0 = 0x0240,
        DCBDATA1 = 0x0244,
        DCBRESET = 0x1340,

        // Iterator & Coordinate Registers (Full State Views)
        XSTART = 0x0100,
        YSTART = 0x0104,
        XEND = 0x0108,
        YEND = 0x010C,

        // Integer-Only Views (16-bit)
        XSTARTI = 0x0148,
        XSAVE = 0x0110,

        // Float/GL Mapping Views (12.4(7))
        XSTARTF = 0x0138,
        YSTARTF = 0x013C,
        XENDF = 0x0140,
        YENDF = 0x0144,

        // Packed Integer Views (16,16)
        XYSTARTI = 0x0150,
        XYENDI = 0x0154,
        XSTARTENDI = 0x0158
    };

    Rex3();
    ~Rex3() = default;

    void reset();
    bool contains(uint32_t address) const;
    uint32_t read32(uint32_t address) const;
    void write32(uint32_t address, uint32_t value);
    std::string descriptionFor(uint32_t address) const;

private:
    // Helper methods for fixed-point conversion
    static int32_t from16_4_7(uint32_t value);
    static uint32_t to16_4_7(int32_t value);
    static int32_t from12_4_7(uint32_t value);
    static uint32_t to12_4_7(int32_t value);

    // Register storage - 2048 registers (8KB) to cover the REX3 register space
    std::array<uint32_t, 2048> regs_;

    // Framebuffer - simplified for now
    static constexpr uint32_t kFramebufferWidth = 1280;
    static constexpr uint32_t kFramebufferHeight = 1024;
    static constexpr uint32_t kFramebufferDepth = 24; // bits per pixel
    std::array<uint32_t, kFramebufferWidth * kFramebufferHeight> framebuffer_;

    // Internal state
    bool enabled_ = true;
    bool go_pending_ = false; // Tracks if GO command is pending

public:
    // Access to framebuffer data for display
    const uint32_t* framebufferData() const { return framebuffer_.data(); }
    uint32_t framebufferWidth() const { return kFramebufferWidth; }
    uint32_t framebufferHeight() const { return kFramebufferHeight; }
};

} // namespace indyemu

#endif // INDYEMU_REX3_HPP