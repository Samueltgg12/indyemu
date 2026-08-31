#ifndef INDYEMU_VINO_HPP
#define INDYEMU_VINO_HPP

#include <cstdint>
#include <array>
#include <string>
#include "system/gio64_bus.hpp"

namespace indyemu {

// VINO (Video Input, No Output) ASIC. Captures video input (Philips or D1
// interface) and DMAs it into memory. See hardware-docs/vino/vino.md.
// Mapped in the low EISA I/O space at physical 0x00080000-0x0009FFFF
// (see MAME indy_indigo2.cpp ip24_map).
class Vino : public IODevice {
public:
    static constexpr uint32_t kBase = 0x00080000u;
    static constexpr uint32_t kSize = 0x00020000u; // 128KB EISA I/O region

    // Register offsets (relative to kBase). All on 64-bit doubleword
    // boundaries; 32-bit access uses the 4/8 ending address.
    enum Register : uint32_t {
        REV_ID              = 0x0000, // Read
        CONTROL             = 0x0008, // Read/Write
        INTERRUPT_STATUS    = 0x0010, // Read/Write
        IC_CONTROL          = 0x0018, // Read/Write
        IC_DATA             = 0x0020, // Read/Write

        CHA_ALPHA           = 0x0028, // Read/Write
        CHA_CLIP_START      = 0x0030, // Read/Write
        CHA_CLIP_END        = 0x0038, // Read/Write
        CHA_FRAME_RATE      = 0x0040, // Read/Write
        CHA_FIELD_COUNTER   = 0x0048, // Read
        CHA_LINE_SIZE       = 0x0050, // Read/Write
        CHA_LINE_COUNT      = 0x0058, // Read/Write
        CHA_PAGE_INDEX      = 0x0060, // Read/Write
        CHA_NEXT_DESCRIPTOR = 0x0068, // Read/Write
        CHA_START_DESCRIPTOR= 0x0070, // Read/Write
        CHA_DESC0           = 0x0078, // Read/Write
        CHA_DESC1           = 0x0080, // Read/Write
        CHA_DESC2           = 0x0088, // Read/Write
        CHA_DESC3           = 0x0090, // Read/Write
        CHA_FIFO_THRESHOLD  = 0x0098, // Read/Write
        CHA_FIFO_GIO_PTR    = 0x00A0, // Read
        CHA_FIFO_VIDEO_PTR  = 0x00A8, // Read

        CHB_ALPHA           = 0x00B0, // Read/Write
        CHB_CLIP_START      = 0x00B8, // Read/Write
        CHB_CLIP_END        = 0x00C0, // Read/Write
        CHB_FRAME_RATE      = 0x00C8, // Read/Write
        CHB_FIELD_COUNTER   = 0x00D0, // Read
        CHB_LINE_SIZE       = 0x00D8, // Read/Write
        CHB_LINE_COUNT      = 0x00E0, // Read/Write
        CHB_PAGE_INDEX      = 0x00E8, // Read/Write
        CHB_NEXT_DESCRIPTOR = 0x00F0, // Read/Write
        CHB_START_DESCRIPTOR= 0x00F8, // Read/Write
        CHB_DESC0           = 0x0100, // Read/Write
        CHB_DESC1           = 0x0108, // Read/Write
        CHB_DESC2           = 0x0110, // Read/Write
        CHB_DESC3           = 0x0118, // Read/Write
        CHB_FIFO_THRESHOLD  = 0x0120, // Read/Write
        CHB_FIFO_GIO_PTR    = 0x0128, // Read
        CHB_FIFO_VIDEO_PTR  = 0x0130, // Read
    };

    Vino();

    bool contains(uint32_t address) const override;
    uint32_t read32(uint32_t address) const override;
    void write32(uint32_t address, uint32_t value) override;
    std::string descriptionFor(uint32_t address) const override;

    void reset();

private:
    // Storage for read/write registers. Indexed by (offset / 4).
    std::array<uint32_t, kSize / 4u> regs_;
};

} // namespace indyemu

#endif // INDYEMU_VINO_HPP