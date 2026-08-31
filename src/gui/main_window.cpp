// src/gui/main_window.cpp
#include "gui/main_window.hpp"

#include "gui/framebuffer_display.hpp"
#include "system/rex3.hpp"

#include <QApplication>
#include <QCursor>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QStatusBar>
#include <QVBoxLayout>

namespace {
QString styleIndigoMagic() {
    return R"(
        QMainWindow {
            background: #d7d9df;
            color: #1d2340;
        }
        QWidget {
            background: #d7d9df;
            color: #1d2340;
            font-family: "DejaVu Sans", sans-serif;
        }
        QStatusBar {
            background: #b7c0d0;
            color: #1d2340;
            border-top: 1px solid #7d8698;
        }
        QLabel {
            background: transparent;
            color: #1d2340;
        }
    )";
}
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , input_grabbed_(false) {
    setWindowTitle("IndyEmu - SGI Indy Emulation");
    resize(1024, 768);
    setStyleSheet(styleIndigoMagic());

    setupUI();

    // Status bar with grab-release hint
    statusBar()->showMessage("Click inside the window to grab input | Press Escape to release");
    statusBar()->setStyleSheet("QStatusBar { background: #b7c0d0; color: #1d2340; border-top: 1px solid #7d8698; }");
}

MainWindow::~MainWindow() {
    if (input_grabbed_) {
        releaseInput();
    }
}

void MainWindow::setupUI() {
    central_widget_ = new QWidget(this);
    auto* layout = new QVBoxLayout(central_widget_);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Framebuffer display as the central widget
    display_ = new indyemu::FramebufferDisplay(central_widget_);
    display_->setFocusPolicy(Qt::StrongFocus);
    display_->setMouseTracking(true);
    layout->addWidget(display_);

    setCentralWidget(central_widget_);

    // Set window icon from PROPERICONS
    QIcon icon(":/icons/indy.png");
    if (icon.isNull()) {
        // Try loading from filesystem
        icon = QIcon("samples/GUI References/PROPERICONS/Irix/256x256/indy.png");
    }
    if (!icon.isNull()) {
        setWindowIcon(icon);
    }
}

void MainWindow::setRex3(indyemu::Rex3* rex3) {
    if (display_) {
        display_->setRex3(rex3);
    }
}

void MainWindow::setEmulationTitle(const QString& title) {
    setWindowTitle(QString("IndyEmu - %1").arg(title));
}

void MainWindow::focusInEvent(QFocusEvent* event) {
    QMainWindow::focusInEvent(event);
    // Auto-grab input when window gains focus (optional - can be click-based instead)
    // grabInput();
}

void MainWindow::focusOutEvent(QFocusEvent* event) {
    QMainWindow::focusOutEvent(event);
    // Release input when window loses focus
    if (input_grabbed_) {
        releaseInput();
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    // Escape key releases input grab
    if (event->key() == Qt::Key_Escape && input_grabbed_) {
        releaseInput();
        event->accept();
        return;
    }
    
    // Forward key events to the display when input is grabbed
    if (input_grabbed_ && display_) {
        QApplication::sendEvent(display_, event);
        return;
    }
    
    QMainWindow::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    // Forward key release events to the display when input is grabbed
    if (input_grabbed_ && display_) {
        QApplication::sendEvent(display_, event);
        return;
    }
    
    QMainWindow::keyReleaseEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    // Click inside the window grabs input
    if (!input_grabbed_ && event->button() == Qt::LeftButton) {
        grabInput();
        event->accept();
        return;
    }
    
    // Forward mouse events to the display when input is grabbed
    if (input_grabbed_ && display_) {
        QApplication::sendEvent(display_, event);
        return;
    }
    
    QMainWindow::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
    // Forward mouse release events to the display when input is grabbed
    if (input_grabbed_ && display_) {
        QApplication::sendEvent(display_, event);
        return;
    }
    
    QMainWindow::mouseReleaseEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    // Forward mouse move events to the display when input is grabbed
    if (input_grabbed_ && display_) {
        QApplication::sendEvent(display_, event);
        return;
    }
    
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::grabInput() {
    if (input_grabbed_) return;
    
    input_grabbed_ = true;
    
    // Grab keyboard and mouse
    display_->grabKeyboard();
    display_->grabMouse();
    
    // Hide cursor and center it
    QCursor::setPos(mapToGlobal(display_->rect().center()));
    display_->setCursor(Qt::BlankCursor);
    
    // Update status bar
    statusBar()->showMessage("Input GRABBED - Press Escape to release");
    
    // Ensure display has focus
    display_->setFocus(Qt::MouseFocusReason);
    
    updateCursor();
}

void MainWindow::releaseInput() {
    if (!input_grabbed_) return;
    
    input_grabbed_ = false;
    
    // Release keyboard and mouse
    display_->releaseKeyboard();
    display_->releaseMouse();
    
    // Restore cursor
    display_->unsetCursor();
    
    // Update status bar
    statusBar()->showMessage("Input RELEASED - Click inside the window to grab input | Press Escape to release");
    
    updateCursor();
}

void MainWindow::updateCursor() {
    if (input_grabbed_) {
        display_->setCursor(Qt::BlankCursor);
    } else {
        display_->unsetCursor();
    }
}
