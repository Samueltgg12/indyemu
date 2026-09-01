// src/core/framebuffer.hpp
#pragma once

#include "core/common.hpp"

#include <cstddef>
#include <vector>

namespace indyemu {

class Framebuffer {
public:
  static constexpr u32 kDefaultWidth = 1024u;
  static constexpr u32 kDefaultHeight = 768u;
  static constexpr u32 kDefaultBitsPerPixel = 24u;
  static constexpr u32 kDefaultBase = 0x1F000000u;

  Framebuffer(u32 width = kDefaultWidth, u32 height = kDefaultHeight,
              u32 bits_per_pixel = kDefaultBitsPerPixel,
              u32 base_address = kDefaultBase);

  void reset();
  void clear(u32 color = 0u);

  u32 width() const { return width_; }
  u32 height() const { return height_; }
  u32 bitsPerPixel() const { return bits_per_pixel_; }
  std::size_t stride() const { return stride_; }
  std::size_t byteSize() const { return pixels_.size(); }
  u32 baseAddress() const { return base_address_; }

  void setPixel(u32 x, u32 y, u32 color);
  u32 getPixel(u32 x, u32 y) const;

  u32 read32(u32 offset) const;
  void write32(u32 offset, u32 value);

  const std::vector<u8> &data() const { return pixels_; }

private:
  u32 width_;
  u32 height_;
  u32 bits_per_pixel_;
  u32 base_address_;
  std::size_t stride_;
  std::vector<u8> pixels_;

  std::size_t offsetFor(u32 x, u32 y) const;
  std::size_t addressToIndex(u32 offset) const;
};

} // namespace indyemu
