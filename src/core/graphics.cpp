#include "core/graphics.hpp"

namespace indyemu {

GraphicsController::GraphicsController(GraphicsConfig config)
    : config_(std::move(config)), framebuffer_(config_.width, config_.height, config_.bits_per_pixel, config_.base_address) {
}

void GraphicsController::reset() {
    framebuffer_.reset();
}

void GraphicsController::setMode(u32 width, u32 height, u32 bits_per_pixel) {
    config_.width = width;
    config_.height = height;
    config_.bits_per_pixel = bits_per_pixel;
    framebuffer_ = Framebuffer(width, height, bits_per_pixel, config_.base_address);
}

void GraphicsController::clear(u32 color) {
    framebuffer_.clear(color);
}

}  // namespace indyemu
