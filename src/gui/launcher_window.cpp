// src/gui/launcher_window.cpp
#include "launcher_window.hpp"
#include <QFileDialog>
#include <QSettings>
#include <QMessageBox>
#include <QIcon>
#include <QPixmap>
#include <QScreen>
#include <QApplication>
#include <QStyle>
#include <QDir>

namespace indyemu {

LauncherWindow::LauncherWindow(QWidget* parent)
    : QMainWindow(parent) {
    setWindowTitle("IndyEmu - SGI Indy Emulator Launcher");
    setFixedSize(520, 580);
    setupUI();
    applyIndigoMagicStyle();
    loadSettings();
    centerOnScreen();
}

LauncherWindow::Config LauncherWindow::getConfig() const {
    return config_;
}

void LauncherWindow::setupUI() {
    centralWidget_ = new QWidget(this);
    setCentralWidget(centralWidget_);

    mainLayout_ = new QVBoxLayout(centralWidget_);
    mainLayout_->setSpacing(12);
    mainLayout_->setContentsMargins(16, 16, 16, 16);

    // Title label with SGI logo/icon
    QLabel* titleLabel = new QLabel("SGI Indy Emulator", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #1d2340; margin-bottom: 8px;");
    mainLayout_->addWidget(titleLabel);

    QLabel* subtitleLabel = new QLabel("IndigoMagic Desktop Launcher", this);
    subtitleLabel->setAlignment(Qt::AlignCenter);
    subtitleLabel->setStyleSheet("font-size: 12px; color: #5a5e66; margin-bottom: 16px;");
    mainLayout_->addWidget(subtitleLabel);

    // PROM Selection Group
    promGroup_ = new QGroupBox("PROM Image", this);
    promLayout_ = new QFormLayout(promGroup_);
    promLayout_->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    promLayout_->setLabelAlignment(Qt::AlignRight);

    promPathEdit_ = new QLineEdit(this);
    promPathEdit_->setPlaceholderText("Select PROM image file (.bin)...");
    promPathEdit_->setReadOnly(true);

    browsePromBtn_ = new QPushButton("Browse...", this);
    browsePromBtn_->setIcon(style()->standardIcon(QStyle::SP_DirOpenIcon));

    QHBoxLayout* promPathLayout = new QHBoxLayout();
    promPathLayout->addWidget(promPathEdit_);
    promPathLayout->addWidget(browsePromBtn_);
    promLayout_->addRow("PROM File:", promPathLayout);

    connect(browsePromBtn_, &QPushButton::clicked, this, &LauncherWindow::onBrowseProm);

    mainLayout_->addWidget(promGroup_);

    // System Configuration Group
    systemGroup_ = new QGroupBox("System Configuration", this);
    systemLayout_ = new QFormLayout(systemGroup_);
    systemLayout_->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    systemLayout_->setLabelAlignment(Qt::AlignRight);

    ramSizeSpin_ = new QSpinBox(this);
    ramSizeSpin_->setRange(16, 1024);
    ramSizeSpin_->setSuffix(" MB");
    ramSizeSpin_->setSingleStep(16);
    ramSizeSpin_->setValue(128);
    systemLayout_->addRow("RAM Size:", ramSizeSpin_);

    audioCheck_ = new QCheckBox("Enable Audio (HAL2)", this);
    audioCheck_->setChecked(true);
    systemLayout_->addRow("", audioCheck_);

    networkCheck_ = new QCheckBox("Enable Network (SEEQ 80C03)", this);
    networkCheck_->setChecked(false);
    systemLayout_->addRow("", networkCheck_);

    mainLayout_->addWidget(systemGroup_);

    // Display Configuration Group
    displayGroup_ = new QGroupBox("Display Configuration", this);
    displayLayout_ = new QFormLayout(displayGroup_);
    displayLayout_->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    displayLayout_->setLabelAlignment(Qt::AlignRight);

    fullscreenCheck_ = new QCheckBox("Fullscreen Mode", this);
    fullscreenCheck_->setChecked(false);
    displayLayout_->addRow("", fullscreenCheck_);

    widthSpin_ = new QSpinBox(this);
    widthSpin_->setRange(640, 3840);
    widthSpin_->setSingleStep(1);
    widthSpin_->setValue(1280);
    displayLayout_->addRow("Width:", widthSpin_);

    heightSpin_ = new QSpinBox(this);
    heightSpin_->setRange(480, 2160);
    heightSpin_->setSingleStep(1);
    heightSpin_->setValue(1024);
    displayLayout_->addRow("Height:", heightSpin_);

    connect(fullscreenCheck_, &QCheckBox::toggled, this, &LauncherWindow::onFullscreenToggled);

    mainLayout_->addWidget(displayGroup_);

    mainLayout_->addStretch();

    // Buttons
    buttonLayout_ = new QHBoxLayout();
    buttonLayout_->setSpacing(12);

    launchBtn_ = new QPushButton("Launch Emulation", this);
    launchBtn_->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    launchBtn_->setMinimumHeight(40);
    launchBtn_->setDefault(true);
    launchBtn_->setStyleSheet("font-weight: bold; font-size: 13px;");

    quitBtn_ = new QPushButton("Quit", this);
    quitBtn_->setIcon(style()->standardIcon(QStyle::SP_DialogCloseButton));
    quitBtn_->setMinimumHeight(40);

    buttonLayout_->addStretch();
    buttonLayout_->addWidget(launchBtn_);
    buttonLayout_->addWidget(quitBtn_);

    mainLayout_->addLayout(buttonLayout_);

    connect(launchBtn_, &QPushButton::clicked, this, &LauncherWindow::onLaunch);
    connect(quitBtn_, &QPushButton::clicked, this, &LauncherWindow::onQuit);
}

void LauncherWindow::applyIndigoMagicStyle() {
    // IndigoMagic color scheme from sgi-enhanced theme
    // active = #a59f80, inactive = #808080
    // Background: #d7d9df, Text: #1d2340, Borders: #8a8e99
    setStyleSheet(R"(
        QMainWindow {
            background-color: #d7d9df;
            color: #1d2340;
        }
        QGroupBox {
            background-color: #dfe3ed;
            border: 1px solid #8a8e99;
            border-radius: 4px;
            margin-top: 12px;
            padding-top: 8px;
            font-weight: bold;
            color: #1d2340;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top left;
            padding: 0 6px;
            left: 8px;
            color: #1d2340;
        }
        QLabel {
            color: #1d2340;
        }
        QLineEdit {
            background-color: #ffffff;
            border: 1px solid #8a8e99;
            border-radius: 3px;
            padding: 4px 8px;
            color: #1d2340;
            selection-background-color: #a59f80;
        }
        QLineEdit:focus {
            border: 2px solid #a59f80;
        }
        QSpinBox {
            background-color: #ffffff;
            border: 1px solid #8a8e99;
            border-radius: 3px;
            padding: 4px 8px;
            color: #1d2340;
        }
        QSpinBox:focus {
            border: 2px solid #a59f80;
        }
        QSpinBox::up-button, QSpinBox::down-button {
            background-color: #dfe3ed;
            border: 1px solid #8a8e99;
            width: 16px;
        }
        QSpinBox::up-button:hover, QSpinBox::down-button:hover {
            background-color: #a59f80;
        }
        QCheckBox {
            color: #1d2340;
            spacing: 6px;
        }
        QCheckBox::indicator {
            width: 16px;
            height: 16px;
            border: 1px solid #8a8e99;
            border-radius: 2px;
            background-color: #ffffff;
        }
        QCheckBox::indicator:checked {
            background-color: #a59f80;
            border: 1px solid #8a8e99;
            image: url(:/icons/check.svg);
        }
        QPushButton {
            background-color: #dfe3ed;
            border: 1px solid #8a8e99;
            border-radius: 3px;
            padding: 8px 16px;
            color: #1d2340;
            min-width: 80px;
        }
        QPushButton:hover {
            background-color: #e8ebef;
            border: 1px solid #a59f80;
        }
        QPushButton:pressed {
            background-color: #a59f80;
            border: 1px solid #8a8e99;
        }
        QPushButton:default {
            border: 2px solid #a59f80;
            font-weight: bold;
        }
        QPushButton:disabled {
            background-color: #d7d9df;
            color: #8a8e99;
            border: 1px solid #8a8e99;
        }
    )");

    // Try to set window icon from PROPERICONS
    QIcon windowIcon;
    // Try to load from the PROPERICONS directory
    QString iconPath = QDir::currentPath() + "/samples/GUI References/PROPERICONS/Irix/256X256/apps/app-toolchest.png";
    if (QFile::exists(iconPath)) {
        windowIcon = QIcon(iconPath);
    } else {
        // Fallback to scalable SVG
        iconPath = QDir::currentPath() + "/samples/GUI References/PROPERICONS/Irix/scalable/apps/app-toolchest.svg";
        if (QFile::exists(iconPath)) {
            windowIcon = QIcon(iconPath);
        }
    }
    if (!windowIcon.isNull()) {
        setWindowIcon(windowIcon);
    }
}

void LauncherWindow::centerOnScreen() {
    if (QScreen* screen = QApplication::primaryScreen()) {
        QRect screenGeometry = screen->availableGeometry();
        int x = (screenGeometry.width() - width()) / 2;
        int y = (screenGeometry.height() - height()) / 2;
        move(x, y);
    }
}

void LauncherWindow::onBrowseProm() {
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Select PROM Image",
        QDir::homePath(),
        "PROM Images (*.bin *.rom);;All Files (*)"
    );

    if (!filePath.isEmpty()) {
        promPathEdit_->setText(filePath);
        config_.promPath = filePath;
    }
}

void LauncherWindow::onLaunch() {
    if (config_.promPath.isEmpty()) {
        QMessageBox::warning(this, "Missing PROM", "Please select a PROM image file before launching.");
        return;
    }

    config_.ramSizeMB = static_cast<size_t>(ramSizeSpin_->value());
    config_.enableAudio = audioCheck_->isChecked();
    config_.enableNetwork = networkCheck_->isChecked();
    config_.fullscreen = fullscreenCheck_->isChecked();
    config_.videoWidth = widthSpin_->value();
    config_.videoHeight = heightSpin_->value();

    saveSettings();
    emit launchRequested(config_);
    hide(); // Hide launcher, don't close - emulation window will show
}

void LauncherWindow::onQuit() {
    saveSettings();
    emit quitRequested();
    close();
}

void LauncherWindow::onFullscreenToggled(bool checked) {
    widthSpin_->setEnabled(!checked);
    heightSpin_->setEnabled(!checked);
    if (checked) {
        // In fullscreen, use screen resolution
        if (QScreen* screen = QApplication::primaryScreen()) {
            QRect geom = screen->geometry();
            widthSpin_->setValue(geom.width());
            heightSpin_->setValue(geom.height());
        }
    }
}

void LauncherWindow::loadSettings() {
    QSettings settings("IndyEmu", "Launcher");
    config_.promPath = settings.value("promPath", "").toString();
    config_.ramSizeMB = static_cast<size_t>(settings.value("ramSizeMB", 128).toInt());
    config_.enableAudio = settings.value("enableAudio", true).toBool();
    config_.enableNetwork = settings.value("enableNetwork", false).toBool();
    config_.fullscreen = settings.value("fullscreen", false).toBool();
    config_.videoWidth = settings.value("videoWidth", 1280).toInt();
    config_.videoHeight = settings.value("videoHeight", 1024).toInt();

    promPathEdit_->setText(config_.promPath);
    ramSizeSpin_->setValue(static_cast<int>(config_.ramSizeMB));
    audioCheck_->setChecked(config_.enableAudio);
    networkCheck_->setChecked(config_.enableNetwork);
    fullscreenCheck_->setChecked(config_.fullscreen);
    widthSpin_->setValue(config_.videoWidth);
    heightSpin_->setValue(config_.videoHeight);
    onFullscreenToggled(config_.fullscreen);
}

void LauncherWindow::saveSettings() {
    QSettings settings("IndyEmu", "Launcher");
    settings.setValue("promPath", config_.promPath);
    settings.setValue("ramSizeMB", static_cast<int>(config_.ramSizeMB));
    settings.setValue("enableAudio", config_.enableAudio);
    settings.setValue("enableNetwork", config_.enableNetwork);
    settings.setValue("fullscreen", config_.fullscreen);
    settings.setValue("videoWidth", config_.videoWidth);
    settings.setValue("videoHeight", config_.videoHeight);
}

} // namespace indyemu