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
// The most critical XL graphics chip - sends color data and index to RAMDAC for
// display output 8K x 24 CMOS color palette with MPU interface via
// CONFIGSEL[2:0]
class Cmap : public IODevice {
public:
  // CMAP register offsets (MPU interface via CONFIGSEL[2:0])
  enum Register : u32 {
    // CONFIGSEL = 000: Address Register Low (8 bits)
    kAddrRegLow = 0x00,
    // CONFIGSEL = 001: Address Register High (5 bits for 8K = 13 bits total)
    kAddrRegHigh = 0x04,
    // CONFIGSEL = 010: Color Palette Buffer (24 bits: 8R, 8G, 8B)
    kColorPaletteBuffer = 0x08,
    // CONFIGSEL = 011: Command Register
    kCommandReg = 0x0C,
    // CONFIGSEL = 100: Status Register
    kStatusReg = 0x10,
    // CONFIGSEL = 101: Color Buffer Register (readback)
    kColorBufferReg = 0x14,
    // CONFIGSEL = 110: Revision Register
    kRevisionReg = 0x18,
    // CONFIGSEL = 111: Palette Read Initialize/Terminate
    kPaletteReadInitTerm = 0x1C,
  };

  // Command Register bits
  enum CommandBits : u32 {
    kCmdPaletteWrite = 0x01,  // Write to palette
    kCmdPaletteRead = 0x02,   // Read from palette
    kCmdAutoIncrement = 0x04, // Auto-increment address after read/write
    kCmdRgbMode = 0x08,       // RGB mode (vs Color Index mode)
    kCmdSyncReset = 0x10,     // Pipeline sync reset
    kCmdTestMode = 0x20,      // Test mode
  };

  // Status Register bits
  enum StatusBits : u32 {
    kStatusFifoEmpty = 0x01,   // Write FIFO empty
    kStatusFifoFull = 0x02,    // Write FIFO full
    kStatusPipeBusy = 0x04,    // Pipeline busy
    kStatusPaletteBusy = 0x08, // Palette access busy
  };

  // CONFIGSEL modes (3 bits)
  enum ConfigSel : u32 {
    kConfigAddrLow = 0x0,         // 000: Address Register Low
    kConfigAddrHigh = 0x1,        // 001: Address Register High
    kConfigColorPalette = 0x2,    // 010: Color Palette Buffer
    kConfigCommand = 0x3,         // 011: Command Register
    kConfigStatus = 0x4,          // 100: Status Register
    kConfigColorBuffer = 0x5,     // 101: Color Buffer Register
    kConfigRevision = 0x6,        // 110: Revision Register
    kConfigPaletteReadInit = 0x7, // 111: Palette Read Initialize/Terminate
  };

  // CMAP constants
  static constexpr u32 kBase = 0x1F000000u; // GIO64 slot 0 base (same as REX3)
  static constexpr u32 kSize = 0x20000u;    // 128KB register space
  static constexpr u32 kPaletteSize = 8192; // 8K entries
  static constexpr u32 kFifoDepth = 64;     // Write FIFO depth
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
  void setConfigSel(u32 config_sel); // Set CONFIGSEL[2:0] pins
  u32 getConfigSel() const { return config_sel_; }

  // Palette access
  u32 readPalette(u32 index) const;
  void writePalette(u32 index, u32 rgb24);

  // Pipeline sync (PIPE.IN/PIPE.OUT)
  void pipelineSyncIn();
  void pipelineSyncOut();
  bool isPipelineSynced() const { return pipe_synced_; }

private:
  // Register storage
  std::array<u32, 32> regs_; // MPU registers

  // 8K x 24 color palette RAM
  std::array<u32, kPaletteSize> palette_;

  // Write FIFO (64 x 37 bits: 13-bit addr + 24-bit color)
  struct FifoEntry {
    u32 address;
    u32 color;
    bool valid;
  };
  std::array<FifoEntry, kFifoDepth> write_fifo_;
  u32 fifo_head_ = 0;
  u32 fifo_tail_ = 0;
  u32 fifo_count_ = 0;

  // Address register (13 bits for 8K palette)
  u32 addr_reg_low_ = 0;  // 8 bits
  u32 addr_reg_high_ = 0; // 5 bits
  u32 current_address() const { return (addr_reg_high_ << 8) | addr_reg_low_; }

  // CONFIGSEL[2:0] - selects which register is accessed via MPU interface
  u32 config_sel_ = 0;

  // Command register state
  u32 command_reg_ = 0;

  // Pipeline sync state
  bool pipe_synced_ = false;
  bool pipe_in_asserted_ = false;

  // Auto-increment state
  bool auto_increment_ = false;

  // Helper methods
  bool fifoEmpty() const { return fifo_count_ == 0; }
  bool fifoFull() const { return fifo_count_ == kFifoDepth; }
  void fifoPush(u32 addr, u32 color);
  bool fifoPop(u32 &addr, u32 &color);
  void updateStatusReg();
  u32 getFullAddress() const;
  void incrementAddress();
};

} // namespace indyemu

#endif // INDYEMU_CMAP_HPP