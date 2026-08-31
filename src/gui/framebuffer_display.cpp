#include "framebuffer_display.hpp"
#include "system/rex3.hpp"
#include <QPainter>
#include <QDebug>

namespace indyemu {

FramebufferDisplay::FramebufferDisplay(QWidget* parent)
    : QWidget(parent)
{
    setMinimumSize(640, 480);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // Set up timer to periodically update the display (60 FPS)
    update_timer_.setInterval(16); // ~60 FPS
    connect(&update_timer_, &QTimer::timeout, this, &FramebufferDisplay::updateFramebuffer);
    update_timer_.start();
}

FramebufferDisplay::~FramebufferDisplay() {
    update_timer_.stop();
}

void FramebufferDisplay::setRex3(Rex3* rex3) {
    rex3_ = rex3;
    if (rex3_) {
        updateImage();
    }
}

void FramebufferDisplay::updateFramebuffer() {
    if (rex3_) {
        updateImage();
        update(); // Trigger repaint
    }
}

void FramebufferDisplay::updateImage() {
    if (!rex3_) return;

    const uint32_t width = rex3_->framebufferWidth();
    const uint32_t height = rex3_->framebufferHeight();
    const uint32_t* fb_data = rex3_->framebufferData();

    if (!fb_data || width == 0 || height == 0) return;

    // Create QImage from framebuffer data
    // The framebuffer is stored as 32-bit values (24-bit RGB in lower 24 bits)
    // We need to convert to QImage format (ARGB32)
    if (framebuffer_image_.size() != QSize(width, height) ||
        framebuffer_image_.format() != QImage::Format_ARGB32) {
        framebuffer_image_ = QImage(width, height, QImage::Format_ARGB32);
    }

    // Convert framebuffer data to ARGB32
    // Framebuffer stores 24-bit RGB (0xRRGGBB), we need to convert to ARGB32 (0xAARRGGBB)
    // Note: The framebuffer is in big-endian format (SGI Indy is big-endian)
    // But the data is stored as uint32_t in host memory
    for (uint32_t y = 0; y < height; ++y) {
        uint32_t* scanline = reinterpret_cast<uint32_t*>(framebuffer_image_.scanLine(y));
        for (uint32_t x = 0; x < width; ++x) {
            uint32_t pixel = fb_data[y * width + x];
            // Convert 24-bit RGB to 32-bit ARGB (alpha = 0xFF)
            // The framebuffer stores RGB in the lower 24 bits
            scanline[x] = 0xFF000000 | pixel;
        }
    }

    needs_update_ = true;
}

void FramebufferDisplay::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);

    if (!framebuffer_image_.isNull()) {
        // Scale the image to fit the widget while maintaining aspect ratio
        QRect target_rect = rect();
        QSize scaled_size = framebuffer_image_.size();
        scaled_size.scale(target_rect.size(), Qt::KeepAspectRatio);

        QRect draw_rect;
        draw_rect.setSize(scaled_size);
        draw_rect.moveCenter(target_rect.center());

        painter.drawImage(draw_rect, framebuffer_image_);
    } else {
        // Draw placeholder when no framebuffer data
        painter.fillRect(rect(), QColor(30, 30, 40));
        painter.setPen(Qt::white);
        painter.drawText(rect(), Qt::AlignCenter, "No framebuffer data\nWaiting for emulation...");
    }
}

void FramebufferDisplay::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    // No need to recreate image, we scale in paintEvent
}

} // namespace indyemu