// src/gui/main_window.hpp
#pragma once

#include <QMainWindow>
#include <QWidget>

namespace indyemu {
class Rex3;
class FramebufferDisplay;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    // Attach the emulated graphics engine so the display can render it.
    void setRex3(indyemu::Rex3* rex3);

    // Set the window title with emulation status
    void setEmulationTitle(const QString& title);

protected:
    // Handle focus events for grab-release input
    void focusInEvent(QFocusEvent* event) override;
    void focusOutEvent(QFocusEvent* event) override;
    
    // Handle key events for grab-release (Escape to release)
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    
    // Handle mouse events for grab-release
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    void setupUI();
    void grabInput();
    void releaseInput();
    void updateCursor();

    indyemu::FramebufferDisplay* display_ = nullptr;
    QWidget* central_widget_ = nullptr;
    bool input_grabbed_ = false;
    QPoint last_mouse_pos_;
};
