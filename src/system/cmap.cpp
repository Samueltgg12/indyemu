// src/system/cmap.cpp
#include "cmap.hpp"
#include <algorithm>

namespace indyemu {

Cmap::Cmap() { reset(); }

void Cmap::reset() {
  palette_.fill(0);
  write_fifo_.fill({0, 0});
  fifo_head_ = 0;
  fifo_tail_ = 0;
  fifo_count_ = 0;
  addr_reg_ = 0;
  rgb_counter_ = 0;
  color_buffer_ = 0;
  command_reg_ = 0;
  board_rev_ = 0;
}

bool Cmap::contains(u32 address) const {
  return address >= kBase && address < kBase + kSize;
}

u32 Cmap::read32(u32 address) const {
  if (!contains(address)) {
    return 0;
  }
  u32 offset = address - kBase;
  u32 config_sel = (offset >> 2) & 0x7;
  return mpuRead(config_sel);
}

void Cmap::write32(u32 address, u32 value) {
  if (!contains(address)) {
    return;
  }
  u32 offset = address - kBase;
  u32 config_sel = (offset >> 2) & 0x7;
  mpuWrite(config_sel, static_cast<u8>(value & 0xFF));
}

std::string Cmap::descriptionFor(u32 address) const {
  if (!contains(address)) {
    return "CMAP: out of range";
  }
  u32 offset = address - kBase;
  u32 config_sel = (offset >> 2) & 0x7;
  switch (config_sel) {
  case kConfigAddrLow:
    return "CMAP: Address Register Low";
  case kConfigAddrHigh:
    return "CMAP: Address Register High";
  case kConfigColorPalette:
    return "CMAP: Color Palette Buffer";
  case kConfigCommand:
    return "CMAP: Command Register";
  case kConfigStatus:
    return "CMAP: Status Register";
  case kConfigColorBuffer:
    return "CMAP: Color Buffer Register";
  case kConfigRevision:
    return "CMAP: Revision Register";
  case kConfigPaletteReadInit:
    return "CMAP: Palette Read Init/Terminate";
  default:
    return "CMAP: Unknown register";
  }
}

// ---------------------------------------------------------------------------
// MPU read cycle. CONFIGSEL selects the access mode; the RGB counter
// determines which color byte is accessed for palette/buffer operations.
// Reference: cmap_MS622424.md truth table.
// ---------------------------------------------------------------------------
u8 Cmap::mpuRead(u32 config_sel) const {
  switch (config_sel & 0x7) {
  case kConfigAddrLow:
    return static_cast<u8>(addr_reg_ & 0xFF);
  case kConfigAddrHigh:
    // Only CONFIGBUS0-4 recognized; upper three bits output "0".
    return static_cast<u8>((addr_reg_ >> 8) & 0x1F);
  case kConfigColorPalette: {
    // RGB=00: Read Red, increment; RGB=01: Read Green, increment;
    // RGB=10: Read Blue, reset RGB counter, increment Address Register.
    const u32 entry = palette_[addr_reg_ & 0x1FFF];
    u8 value = 0;
    if (rgb_counter_ == 0) {
      value = static_cast<u8>((entry >> 16) & 0xFF);
      rgb_counter_ = 1;
    } else if (rgb_counter_ == 1) {
      value = static_cast<u8>((entry >> 8) & 0xFF);
      rgb_counter_ = 2;
    } else {
      value = static_cast<u8>(entry & 0xFF);
      rgb_counter_ = 0;
      incrementAddress();
    }
    // Reading the palette updates the color buffer register.
    color_buffer_ = entry;
    return value;
  }
  case kConfigCommand:
    return static_cast<u8>(command_reg_ & 0xFF);
  case kConfigStatus:
    return static_cast<u8>(getStatusReg() & 0xFF);
  case kConfigColorBuffer: {
    // RGB=00: Read Red Color Buffer, increment; RGB=01: Read Green;
    // RGB=10: Invalid.
    u8 value = 0;
    if (rgb_counter_ == 0) {
      value = static_cast<u8>((color_buffer_ >> 16) & 0xFF);
      rgb_counter_ = 1;
    } else if (rgb_counter_ == 1) {
      value = static_cast<u8>((color_buffer_ >> 8) & 0xFF);
      rgb_counter_ = 2;
    }
    return value;
  }
  case kConfigRevision:
    return static_cast<u8>(getRevisionReg() & 0xFF);
  case kConfigPaletteReadInit:
    // Terminate color palette read.
    return 0;
  default:
    return 0;
  }
}

// ---------------------------------------------------------------------------
// MPU write cycle.
// Reference: cmap_MS622424.md truth table.
// ---------------------------------------------------------------------------
void Cmap::mpuWrite(u32 config_sel, u8 data) {
  switch (config_sel & 0x7) {
  case kConfigAddrLow:
    addr_reg_ = (addr_reg_ & 0x1F00) | (data & 0xFF);
    rgb_counter_ = 0; // reset RGB counter
    break;
  case kConfigAddrHigh:
    // Only CONFIGBUS0-4 recognized.
    addr_reg_ = (addr_reg_ & 0xFF) | ((data & 0x1F) << 8);
    rgb_counter_ = 0; // reset RGB counter
    break;
  case kConfigColorPalette: {
    // RGB=00: Write Red, increment; RGB=01: Write Green, increment;
    // RGB=10: Write Blue to Write FIFO, transfer register contents to FIFO,
    //         reset RGB counter, increment Address Register.
    const u32 index = addr_reg_ & 0x1FFF;
    if (rgb_counter_ == 0) {
      palette_[index] =
          (palette_[index] & 0x00FFFFu) | (static_cast<u32>(data) << 16);
      rgb_counter_ = 1;
    } else if (rgb_counter_ == 1) {
      palette_[index] =
          (palette_[index] & 0xFF00FFu) | (static_cast<u32>(data) << 8);
      rgb_counter_ = 2;
    } else {
      palette_[index] = (palette_[index] & 0xFFFF00u) | data;
      // Transfer register contents to Write FIFO.
      fifoPush(index, palette_[index]);
      rgb_counter_ = 0;
      incrementAddress();
    }
    break;
  }
  case kConfigCommand:
    command_reg_ = data & 0x1F; // CB0-CB4
    break;
  case kConfigStatus:
  case kConfigColorBuffer:
  case kConfigRevision:
    // Read only - invalid write.
    break;
  case kConfigPaletteReadInit:
    // Initialize color palette read.
    break;
  default:
    break;
  }
}

u32 Cmap::getStatusReg() const {
  u32 status = 0;
  status |= (rgb_counter_ & 0x1) ? kStatusRgb0 : 0;
  status |= (rgb_counter_ & 0x2) ? kStatusRgb1 : 0;
  if (fifoEmpty())
    status |= kStatusEfb; // EFB low = empty
  if (fifoFull())
    status |= kStatusFfb; // FFB low = full
  // HFB/AFB: half or almost-full (active low). CB4 selects threshold.
  const u32 threshold =
      (command_reg_ & kCmdHfbAfb) ? (kFifoDepth - 8) : (kFifoDepth / 2);
  if (fifo_count_ >= threshold)
    status |= kStatusHfb;
  return status;
}

u32 Cmap::getRevisionReg() const {
  // RVB0-2 = REV0-2, RVB3 reserved, RVB4-7 = BD.REV0-3.
  return (kRevision & 0x7) | ((board_rev_ & 0xF) << 4);
}

void Cmap::incrementAddress() const {
  addr_reg_ = (addr_reg_ + 1) & 0x1FFF; // 13-bit wrap for 8K
}

u32 Cmap::readPalette(u32 index) const {
  if (index < kPaletteSize) {
    return palette_[index];
  }
  return 0;
}

void Cmap::writePalette(u32 index, u32 rgb24) {
  if (index < kPaletteSize) {
    palette_[index] = rgb24 & 0xFFFFFF;
  }
}

void Cmap::fifoPush(u32 addr, u32 color) {
  if (!fifoFull()) {
    write_fifo_[fifo_head_] = {addr, color};
    fifo_head_ = (fifo_head_ + 1) % kFifoDepth;
    fifo_count_++;
  }
}

bool Cmap::fifoPop(u32 &addr, u32 &color) {
  if (!fifoEmpty()) {
    addr = write_fifo_[fifo_tail_].address;
    color = write_fifo_[fifo_tail_].color;
    fifo_tail_ = (fifo_tail_ + 1) % kFifoDepth;
    fifo_count_--;
    return true;
  }
  return false;
}

// ---------------------------------------------------------------------------
// Display pipeline: PIXIN -> palette lookup -> POUT (24-bit RGB).
// pix_rgb selects Color Index or RGB mode.
// Reference: cmap_MS622424.md PIX.RGB0-1 pin description.
// ---------------------------------------------------------------------------
u32 Cmap::processPixel(u32 pixin, u32 pix_rgb) const {
  switch (pix_rgb & 0x3) {
  case kPixColorIndex: {
    // Color Index Mode: PIXIN0-12 used to look up the 8K palette.
    const u32 index = pixin & 0x1FFF;
    return palette_[index];
  }
  case kPixRgb11101:
  case kPixRgb11110:
  case kPixRgb11111: {
    // RGB Mode: 5 higher-order bits appended to 8-bit addresses.
    // 11101=0x1D, 11110=0x1E, 11111=0x1F.
    const u32 base = 0x1Cu + (pix_rgb & 0x3);
    const u32 r_addr = (base << 8) | ((pixin >> 16) & 0xFF);
    const u32 g_addr = (base << 8) | ((pixin >> 8) & 0xFF);
    const u32 b_addr = (base << 8) | (pixin & 0xFF);
    const u32 r = palette_[r_addr & 0x1FFF] & 0xFF;
    const u32 g = palette_[g_addr & 0x1FFF] & 0xFF;
    const u32 b = palette_[b_addr & 0x1FFF] & 0xFF;
    return (r << 16) | (g << 8) | b;
  }
  default:
    return 0;
  }
}

} // namespace indyemu