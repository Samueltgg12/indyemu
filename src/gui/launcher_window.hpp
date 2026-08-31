// src/gui/launcher_window.hpp
#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QFileDialog>
#include <QSettings>
#include <QIcon>
#include <QPixmap>
#include <QScreen>
#include <QApplication>

namespace indyemu {

class LauncherWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit LauncherWindow(QWidget* parent = nullptr);
    ~LauncherWindow() override = default;

    // Get the selected configuration
    struct Config {
        QString promPath;
        size_t ramSizeMB = 128;
        bool enableAudio = true;
        bool enableNetwork = false;
        bool fullscreen = false;
        int videoWidth = 1280;
        int videoHeight = 1024;
    };

    Config getConfig() const;

signals:
    void launchRequested(const Config& config);
    void quitRequested();

private slots:
    void onBrowseProm();
    void onLaunch();
    void onQuit();
    void onFullscreenToggled(bool checked);
    void loadSettings();
    void saveSettings();

private:
    void setupUI();
    void applyIndigoMagicStyle();
    void centerOnScreen();

    // UI elements
    QWidget* centralWidget_ = nullptr;
    QVBoxLayout* mainLayout_ = nullptr;

    // PROM selection
    QGroupBox* promGroup_ = nullptr;
    QFormLayout* promLayout_ = nullptr;
    QLineEdit* promPathEdit_ = nullptr;
    QPushButton* browsePromBtn_ = nullptr;

    // System configuration
    QGroupBox* systemGroup_ = nullptr;
    QFormLayout* systemLayout_ = nullptr;
    QSpinBox* ramSizeSpin_ = nullptr;
    QCheckBox* audioCheck_ = nullptr;
    QCheckBox* networkCheck_ = nullptr;

    // Display configuration
    QGroupBox* displayGroup_ = nullptr;
    QFormLayout* displayLayout_ = nullptr;
    QCheckBox* fullscreenCheck_ = nullptr;
    QSpinBox* widthSpin_ = nullptr;
    QSpinBox* heightSpin_ = nullptr;

    // Buttons
    QHBoxLayout* buttonLayout_ = nullptr;
    QPushButton* launchBtn_ = nullptr;
    QPushButton* quitBtn_ = nullptr;

    Config config_;
};

} // namespace indyemu