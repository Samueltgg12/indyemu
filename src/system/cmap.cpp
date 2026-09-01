// src/system/cmap.cpp
#include "cmap.hpp"
#include <algorithm>
#include <cstdio>

namespace indyemu {

Cmap::Cmap() { reset(); }

void Cmap::reset() {
  regs_.fill(0);
  palette_.fill(0);
  write_fifo_.fill({0, 0, false});
  fifo_head_ = 0;
  fifo_tail_ = 0;
  fifo_count_ = 0;
  addr_reg_low_ = 0;
  addr_reg_high_ = 0;
  config_sel_ = 0;
  command_reg_ = 0;
  pipe_synced_ = false;
  pipe_in_asserted_ = false;
  auto_increment_ = false;

  // Set revision register
  regs_[kRevisionReg / 4] = kRevision;

  // Initialize status register
  updateStatusReg();
}

bool Cmap::contains(u32 address) const {
  return address >= kBase && address < kBase + kSize;
}

u32 Cmap::read32(u32 address) const {
  if (!contains(address)) {
    return 0;
  }

  u32 offset = address - kBase;
  u32 reg_index = offset / 4;

  // The MPU interface uses CONFIGSEL[2:0] to select which register is accessed
  // The actual register mapping depends on CONFIGSEL
  switch (config_sel_) {
  case kConfigAddrLow:
    return addr_reg_low_;
  case kConfigAddrHigh:
    return addr_reg_high_;
  case kConfigColorPalette:
    return readPalette(current_address());
  case kConfigCommand:
    return command_reg_;
  case kConfigStatus:
    return regs_[kStatusReg / 4];
  case kConfigColorBuffer:
    return regs_[kColorBufferReg / 4];
  case kConfigRevision:
    return kRevision;
  case kConfigPaletteReadInit:
    // Reading this register initializes/terminates palette read sequence
    return 0;
  default:
    return 0;
  }
}

void Cmap::write32(u32 address, u32 value) {
  if (!contains(address)) {
    return;
  }

  u32 offset = address - kBase;
  u32 reg_index = offset / 4;

  // The MPU interface uses CONFIGSEL[2:0] to select which register is written
  switch (config_sel_) {
  case kConfigAddrLow:
    addr_reg_low_ = value & 0xFF;
    break;
  case kConfigAddrHigh:
    addr_reg_high_ = value & 0x1F; // 5 bits for 8K (13 bits total)
    break;
  case kConfigColorPalette:
    writePalette(current_address(), value & 0xFFFFFF);
    if (auto_increment_) {
      incrementAddress();
    }
    break;
  case kConfigCommand:
    command_reg_ = value;
    auto_increment_ = (value & kCmdAutoIncrement) != 0;
    if (value & kCmdSyncReset) {
      pipe_synced_ = false;
      pipe_in_asserted_ = false;
    }
    break;
  case kConfigColorBuffer:
    // Color buffer is read-only (readback of palette)
    break;
  case kConfigPaletteReadInit:
    // Writing to this register initializes/terminates palette read
    break;
  default:
    break;
  }

  updateStatusReg();
}

std::string Cmap::descriptionFor(u32 address) const {
  if (!contains(address)) {
    return "CMAP: out of range";
  }

  switch (config_sel_) {
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
    return "CMAP: Palette Read Initialize/Terminate";
  default:
    return "CMAP: Unknown register";
  }
}

void Cmap::setConfigSel(u32 config_sel) {
  config_sel_ = config_sel & 0x7; // 3 bits
}

u32 Cmap::readPalette(u32 index) const {
  if (index < kPaletteSize) {
    return palette_[index];
  }
  return 0;
}

void Cmap::writePalette(u32 index, u32 rgb24) {
  if (index < kPaletteSize) {
    palette_[index] = rgb24 & 0xFFFFFF; // 24-bit color (8R, 8G, 8B)
    // Also update color buffer register for readback
    regs_[kColorBufferReg / 4] = rgb24 & 0xFFFFFF;
  }
}

void Cmap::pipelineSyncIn() {
  pipe_in_asserted_ = true;
  // PIPE.IN asserted - pipeline input sync
}

void Cmap::pipelineSyncOut() {
  if (pipe_in_asserted_) {
    pipe_synced_ = true;
  }
  // PIPE.OUT asserted - pipeline output sync
}

void Cmap::fifoPush(u32 addr, u32 color) {
  if (!fifoFull()) {
    write_fifo_[fifo_head_] = {addr, color, true};
    fifo_head_ = (fifo_head_ + 1) % kFifoDepth;
    fifo_count_++;
  }
}

bool Cmap::fifoPop(u32 &addr, u32 &color) {
  if (!fifoEmpty()) {
    addr = write_fifo_[fifo_tail_].address;
    color = write_fifo_[fifo_tail_].color;
    write_fifo_[fifo_tail_].valid = false;
    fifo_tail_ = (fifo_tail_ + 1) % kFifoDepth;
    fifo_count_--;
    return true;
  }
  return false;
}

void Cmap::updateStatusReg() {
  u32 status = 0;
  if (fifoEmpty())
    status |= kStatusFifoEmpty;
  if (fifoFull())
    status |= kStatusFifoFull;
  // Pipeline and palette busy would be set during actual operations
  regs_[kStatusReg / 4] = status;
}

u32 Cmap::getFullAddress() const { return current_address(); }

void Cmap::incrementAddress() {
  u32 addr = current_address();
  addr = (addr + 1) & 0x1FFF; // 13-bit wrap for 8K
  addr_reg_low_ = addr & 0xFF;
  addr_reg_high_ = (addr >> 8) & 0x1F;
}

} // namespace indyemu