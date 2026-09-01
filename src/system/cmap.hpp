// src/system/cmap.hpp
#ifndef INDYEMU_CMAP_HPP
#define INDYEMU_CMAP_HPP

#include <array>
#include <cstdint>
#include <string>

#include "../core/common.hpp"
#include "gio64_bus.hpp"

namespace indyemu {

// CMAP (MS622424) - Color Map Chipset
// The most critical XL graphics chip - sends color data and index to the RAMDAC
// for display output. 8K x 24 CMOS color palette with an MPU interface via
// CONFIGSEL[2:0] and a 64x37 write FIFO.
//
// Reference: hardware-docs/cmap_MS622424.md
class Cmap : public IODevice {
public:
  // CONFIGSEL[2:0] access modes (latched on falling edge of CEB)
  enum ConfigSel : u32 {
    kConfigAddrLow = 0x0,         // 000: Address Register low (R/W)
    kConfigAddrHigh = 0x1,        // 001: Address Register high (R/W)
    kConfigColorPalette = 0x2,    // 010: Color Palette Buffer (R/W)
    kConfigCommand = 0x3,         // 011: Command Register (R/W)
    kConfigStatus = 0x4,          // 100: Status Register (read only)
    kConfigColorBuffer = 0x5,     // 101: Color Buffer Register (read only)
    kConfigRevision = 0x6,        // 110: Revision Register (read only)
    kConfigPaletteReadInit = 0x7, // 111: Palette Read Init/Terminate (R/W)
  };

  // Command Register bits (CB0-CB7)
  enum CommandBits : u32 {
    kCmdPipeIn0Reset = 0x01, // CB0: ANDed with PIPE.IN0
    kCmdPipeIn1Reset = 0x02, // CB1: ANDed with PIPE.IN1
    kCmdPipeIn2Set = 0x04,   // CB2: ORed with PIPE.IN2
    kCmdPipeIn3Set = 0x08,   // CB3: ORed with PIPE.IN3
    kCmdHfbAfb = 0x10,       // CB4: programs AFB flag indicator
  };

  // Status Register bits (SB0-SB7)
  enum StatusBits : u32 {
    kStatusRgb0 = 0x01, // SB0: LSB of RGB counter (read only)
    kStatusRgb1 = 0x02, // SB1: MSB of RGB counter (read only)
    kStatusEfb = 0x04,  // SB2: Empty Flag (Write FIFO empty when low)
    kStatusHfb = 0x08,  // SB3: Half/Almost-Full Flag (active low)
    kStatusFfb = 0x10,  // SB4: Full Flag (Write FIFO full when low)
  };

  // PIX.RGB[1:0] mode selection
  enum PixRgbMode : u32 {
    kPixColorIndex = 0x0, // 00: Color Index Mode (PIXIN0-12)
    kPixRgb11101 = 0x1,   // 01: RGB Mode, 11101 + 8-bit address
    kPixRgb11110 = 0x2,   // 10: RGB Mode, 11110 + 8-bit address
    kPixRgb11111 = 0x3,   // 11: RGB Mode, 11111 + 8-bit address
  };

  // CMAP constants
  static constexpr u32 kBase = 0x1F000000u; // GIO64 slot 0 base
  static constexpr u32 kSize = 0x20000u;    // 128KB register space
  static constexpr u32 kPaletteSize = 8192; // 8K entries
  static constexpr u32 kFifoDepth = 64;     // Write FIFO depth (64 x 37)
  static constexpr u32 kRevision = 0x01;    // Revision ID

  Cmap();
  ~Cmap() override = default;

  // IODevice interface
  bool contains(u32 address) const override;
  u32 read32(u32 address) const override;
  void write32(u32 address, u32 value) override;
  std::string descriptionFor(u32 address) const override;

  // CMAP-specific methods
  void reset();

  // MPU interface (CONFIGSEL latched from address bits [4:2])
  u8 mpuRead(u32 config_sel) const;
  void mpuWrite(u32 config_sel, u8 data);

  // Display pipeline (PIXIN -> palette lookup -> POUT 24-bit RGB)
  u32 processPixel(u32 pixin, u32 pix_rgb) const;

  // Palette access
  u32 readPalette(u32 index) const;
  void writePalette(u32 index, u32 rgb24);

  // Write FIFO
  bool fifoEmpty() const { return fifo_count_ == 0; }
  bool fifoFull() const { return fifo_count_ == kFifoDepth; }
  u32 fifoCount() const { return fifo_count_; }
  bool fifoPop(u32 &addr, u32 &color);

private:
  // 8K x 24 color palette RAM
  std::array<u32, kPaletteSize> palette_;

  // Write FIFO (64 x 37 bits: 13-bit addr + 24-bit color)
  struct FifoEntry {
    u32 address;
    u32 color;
  };
  std::array<FifoEntry, kFifoDepth> write_fifo_;
  u32 fifo_head_ = 0;
  u32 fifo_tail_ = 0;
  u32 fifo_count_ = 0;

  // Address register (13 bits for 8K palette). Mutable because palette reads
  // increment it (read32 is const).
  mutable u32 addr_reg_ = 0;

  // RGB counter (modulo-3: 0=Red, 1=Green, 2=Blue). Mutable because palette
  // reads increment it.
  mutable u32 rgb_counter_ = 0;

  // Color buffer register (readback of last palette read). Mutable because
  // palette reads update it.
  mutable u32 color_buffer_ = 0;

  // Command register
  u32 command_reg_ = 0;

  // Board revision inputs (BD.REV0-3)
  u32 board_rev_ = 0;

  // Helper methods
  void fifoPush(u32 addr, u32 color);
  u32 getStatusReg() const;
  u32 getRevisionReg() const;
  void incrementAddress() const;
};

} // namespace indyemu

#endif // INDYEMU_CMAP_HPP