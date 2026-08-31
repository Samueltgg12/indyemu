#ifndef INDYEMU_FRAMEBUFFER_DISPLAY_HPP
#define INDYEMU_FRAMEBUFFER_DISPLAY_HPP

#include <QWidget>
#include <QImage>
#include <QTimer>
#include <memory>

namespace indyemu {

class Rex3;

class FramebufferDisplay : public QWidget {
    Q_OBJECT

public:
    explicit FramebufferDisplay(QWidget* parent = nullptr);
    ~FramebufferDisplay() override;

    void setRex3(Rex3* rex3);

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void updateFramebuffer();

private:
    void updateImage();

    Rex3* rex3_ = nullptr;
    QImage framebuffer_image_;
    QTimer update_timer_;
    bool needs_update_ = false;
};

} // namespace indyemu

#endif // INDYEMU_FRAMEBUFFER_DISPLAY_HPP