// src/core/framebuffer.cpp
#include "core/framebuffer.hpp"

#include <cstring>

namespace indyemu {

Framebuffer::Framebuffer(u32 width, u32 height, u32 bits_per_pixel,
                         u32 base_address)
    : width_(width), height_(height), bits_per_pixel_(bits_per_pixel),
      base_address_(base_address) {
  stride_ = width_ * (bits_per_pixel_ / 8u);
  pixels_.assign(stride_ * height_, 0);
}

void Framebuffer::reset() { std::fill(pixels_.begin(), pixels_.end(), 0); }

void Framebuffer::clear(u32 color) {
  const u8 r = static_cast<u8>((color >> 16) & 0xFFu);
  const u8 g = static_cast<u8>((color >> 8) & 0xFFu);
  const u8 b = static_cast<u8>(color & 0xFFu);

  for (size_t i = 0; i < pixels_.size(); i += 3) {
    pixels_[i] = b;
    pixels_[i + 1] = g;
    pixels_[i + 2] = r;
  }
}

std::size_t Framebuffer::offsetFor(u32 x, u32 y) const {
  if (x >= width_ || y >= height_) {
    return 0;
  }
  return static_cast<std::size_t>(y * stride_ + x * (bits_per_pixel_ / 8u));
}

std::size_t Framebuffer::addressToIndex(u32 offset) const {
  const u32 relative = offset - base_address_;
  if (relative >= pixels_.size()) {
    return 0;
  }
  return static_cast<std::size_t>(relative);
}

void Framebuffer::setPixel(u32 x, u32 y, u32 color) {
  const std::size_t idx = offsetFor(x, y);
  if (idx + 2 >= pixels_.size()) {
    return;
  }

  pixels_[idx] = static_cast<u8>(color & 0xFFu);
  pixels_[idx + 1] = static_cast<u8>((color >> 8) & 0xFFu);
  pixels_[idx + 2] = static_cast<u8>((color >> 16) & 0xFFu);
}

u32 Framebuffer::getPixel(u32 x, u32 y) const {
  const std::size_t idx = offsetFor(x, y);
  if (idx + 2 >= pixels_.size()) {
    return 0;
  }

  return static_cast<u32>(pixels_[idx]) |
         (static_cast<u32>(pixels_[idx + 1]) << 8) |
         (static_cast<u32>(pixels_[idx + 2]) << 16);
}

u32 Framebuffer::read32(u32 offset) const {
  const std::size_t idx = addressToIndex(offset);
  if (idx + 4 > pixels_.size()) {
    return 0;
  }

  return static_cast<u32>(pixels_[idx]) |
         (static_cast<u32>(pixels_[idx + 1]) << 8) |
         (static_cast<u32>(pixels_[idx + 2]) << 16) |
         (static_cast<u32>(pixels_[idx + 3]) << 24);
}

void Framebuffer::write32(u32 offset, u32 value) {
  const std::size_t idx = addressToIndex(offset);
  if (idx + 4 > pixels_.size()) {
    return;
  }

  pixels_[idx] = static_cast<u8>(value & 0xFFu);
  pixels_[idx + 1] = static_cast<u8>((value >> 8) & 0xFFu);
  pixels_[idx + 2] = static_cast<u8>((value >> 16) & 0xFFu);
  pixels_[idx + 3] = static_cast<u8>((value >> 24) & 0xFFu);
}

} // namespace indyemu
