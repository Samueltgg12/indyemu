// src/core/graphics.hpp
#pragma once

#include "core/framebuffer.hpp"

#include <array>
#include <string>

namespace indyemu {

struct GraphicsConfig {
  u32 width = Framebuffer::kDefaultWidth;
  u32 height = Framebuffer::kDefaultHeight;
  u32 bits_per_pixel = Framebuffer::kDefaultBitsPerPixel;
  u32 base_address = Framebuffer::kDefaultBase;
  std::string name = "SGI Indy XL framebuffer";
};

class GraphicsController {
public:
  explicit GraphicsController(GraphicsConfig config = GraphicsConfig{});

  void reset();
  void setMode(u32 width, u32 height, u32 bits_per_pixel);
  void clear(u32 color = 0x000000u);

  const Framebuffer &framebuffer() const { return framebuffer_; }
  Framebuffer &framebuffer() { return framebuffer_; }

  u32 width() const { return framebuffer_.width(); }
  u32 height() const { return framebuffer_.height(); }

private:
  GraphicsConfig config_;
  Framebuffer framebuffer_;
};

} // namespace indyemu
