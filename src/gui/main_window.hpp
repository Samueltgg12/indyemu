// src/gui/main_window.hpp
#pragma once

#include <QMainWindow>
#include <QTabWidget>

namespace indyemu {
class Rex3;
class FramebufferDisplay;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    // Attach the emulated graphics engine so the display tab can render it.
    void setRex3(indyemu::Rex3* rex3);

private:
    void setupSystemTab();
    void setupStorageTab();
    void setupMemoryTab();
    void setupDisplayTab();
    void setupNetworkTab();
    void setupDiagnosticsTab();

    QTabWidget* tabs_ = nullptr;
    indyemu::FramebufferDisplay* display_ = nullptr;
};
