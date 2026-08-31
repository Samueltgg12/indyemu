#include "gui/main_window.hpp"

#include "config/indy_config.hpp"
#include "gui/framebuffer_display.hpp"
#include "system/rex3.hpp"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <Qt>
#include <QVBoxLayout>
#include <QWidget>

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
        QTabWidget::pane {
            border: 1px solid #8a8e99;
            background: #dfe3ed;
        }
        QTabBar::tab {
            background: #bfc8d8;
            border: 1px solid #7c8599;
            border-bottom: none;
            padding: 8px 18px;
            color: #1d2340;
            min-width: 90px;
        }
        QTabBar::tab:selected {
            background: #dfe3ed;
            border-bottom: 1px solid #dfe3ed;
        }
        QGroupBox {
            background: #eaf0f8;
            border: 1px solid #8a8e99;
            border-radius: 3px;
            margin-top: 10px;
            padding-top: 12px;
            font-weight: 600;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            left: 10px;
            padding: 0 6px;
            color: #2a2d47;
        }
        QLabel {
            background: transparent;
        }
        QTextEdit, QListWidget {
            background: #f5f7fb;
            border: 1px solid #8a8e99;
            color: #1f2a44;
        }
        QPushButton {
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                       stop:0 #e7edf9, stop:1 #bec9d9);
            border: 1px solid #7c8599;
            padding: 7px 12px;
            color: #1d2340;
        }
        QPushButton:hover {
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                       stop:0 #f2f7ff, stop:1 #d1d9ea);
        }
        QStatusBar {
            background: #b7c0d0;
            color: #1d2340;
            border-top: 1px solid #7d8698;
        }
    )";
}
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    indyemu::ensureConfigLayout();
    indyemu::writeDefaultProfile("default");

    setWindowTitle("IndyEmu - SGI Indy Hardware Overview");
    resize(1200, 820);
    setStyleSheet(styleIndigoMagic());

    tabs_ = new QTabWidget(this);
    setCentralWidget(tabs_);

    setupSystemTab();
    setupStorageTab();
    setupMemoryTab();
    setupDisplayTab();
    setupNetworkTab();
    setupDiagnosticsTab();

    statusBar()->showMessage(QString("Config root: %1").arg(QString::fromStdString(indyemu::configRoot().string())));
}

void MainWindow::setupSystemTab() {
    auto* page = new QWidget(this);
    auto* layout = new QVBoxLayout(page);

    auto* systemBox = new QGroupBox("System overview", page);
    auto* systemLayout = new QVBoxLayout(systemBox);

    auto* title = new QLabel("SGI Indy / IRIS workstation architecture", systemBox);
    QFont titleFont = title->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    title->setFont(titleFont);
    systemLayout->addWidget(title);

    auto* summary = new QLabel(
        "Planned target: MIPS R4400-class host, SGI Indy PROM bootstrap, 24-bit XL framebuffer, audio, storage, CD/ISO support, EFS, and network attached devices.",
        systemBox);
    summary->setWordWrap(true);
    summary->setStyleSheet("font-size: 12px; color: #1d2340;");
    systemLayout->addWidget(summary);

    auto* details = new QTextEdit(systemBox);
    details->setReadOnly(true);
    details->setPlainText(
        "Core plan:\n"
        "- CPU: R4400-class MIPS, PROM reset vector at BFC00000\n"
        "- PROM: embedded ROM image with SGI startup menu and diagnostics\n"
        "- NVRAM: pre-generated contents with Ethernet address 08:00:69:12:34:56\n"
        "- Memory: RAM + PROM window + I/O map\n"
        "- Graphics: 24-bit XL framebuffer, early startup screen and color modes\n"
        "- Audio: PROM/startup sounds and later Indigo/XL sound pipeline\n"
        "- Storage: EFS, SCSI, ISO/CD, and later disk images\n"
        "- Networking: Ethernet, boot protocols, and NIC emulation\n");
    systemLayout->addWidget(details);

    layout->addWidget(systemBox);
    tabs_->addTab(page, "System");
}

void MainWindow::setupStorageTab() {
    auto* page = new QWidget(this);
    auto* layout = new QVBoxLayout(page);

    auto* storageBox = new QGroupBox("Storage devices", page);
    auto* storageLayout = new QVBoxLayout(storageBox);

    auto* list = new QListWidget(storageBox);
    list->addItem("SCSI host adapter");
    list->addItem("Boot disk image support");
    list->addItem("CD-ROM / ISO mounting");
    list->addItem("SGI EFS / filesystem support");
    list->addItem("Disk geometry planning");
    list->addItem("Install media support");
    storageLayout->addWidget(list);

    auto* buttons = new QWidget(storageBox);
    auto* buttonLayout = new QHBoxLayout(buttons);
    buttonLayout->addWidget(new QPushButton("Attach ISO"));
    buttonLayout->addWidget(new QPushButton("Mount Disk"));
    buttonLayout->addWidget(new QPushButton("Create Empty EFS"));
    storageLayout->addWidget(buttons);

    layout->addWidget(storageBox);
    tabs_->addTab(page, "Storage");
}

void MainWindow::setupMemoryTab() {
    auto* page = new QWidget(this);
    auto* layout = new QVBoxLayout(page);

    auto* memoryBox = new QGroupBox("PROM, RAM, and NVRAM", page);
    auto* memoryLayout = new QVBoxLayout(memoryBox);

    auto* prom = new QLabel("Embedded PROM: boot menu, diagnostics, configuration loader");
    memoryLayout->addWidget(prom);

    auto* nvram = new QLabel("NVRAM: default Ethernet MAC 08:00:69:12:34:56");
    memoryLayout->addWidget(nvram);

    auto* ranges = new QTextEdit(memoryBox);
    ranges->setReadOnly(true);
    ranges->setPlainText(
        "Memory map goals:\n"
        "- PROM window: 0x1FC00000\n"
        "- RAM window: 0x80000000\n"
        "- I/O window: 0x1F000000\n"
        "- Early boot vector handling at BFC00000\n");
    memoryLayout->addWidget(ranges);

    layout->addWidget(memoryBox);
    tabs_->addTab(page, "Memory");
}

void MainWindow::setupDisplayTab() {
    auto* page = new QWidget(this);
    auto* layout = new QVBoxLayout(page);

    auto* displayBox = new QGroupBox("Graphics / framebuffer", page);
    auto* displayLayout = new QVBoxLayout(displayBox);

    // Live view of the emulated REX3 framebuffer.
    display_ = new indyemu::FramebufferDisplay(displayBox);
    displayLayout->addWidget(display_);

    auto* text = new QTextEdit(displayBox);
    text->setReadOnly(true);
    text->setPlainText(
        "Graphics path:\n"
        "- 24-bit XL framebuffer emulation (REX3 / Newport)\n"
        "- live display of the emulated framebuffer\n"
        "- color LUT / display control\n"
        "- later IRIX desktop rendering\n");
    displayLayout->addWidget(text);

    layout->addWidget(displayBox);
    tabs_->addTab(page, "Display");
}

void MainWindow::setRex3(indyemu::Rex3* rex3) {
    if (display_) {
        display_->setRex3(rex3);
    }
}

void MainWindow::setupNetworkTab() {
    auto* page = new QWidget(this);
    auto* layout = new QVBoxLayout(page);

    auto* netBox = new QGroupBox("Networking", page);
    auto* netLayout = new QVBoxLayout(netBox);

    auto* nic = new QLabel("Ethernet device planned with MAC 08:00:69:12:34:56");
    netLayout->addWidget(nic);

    auto* netText = new QTextEdit(netBox);
    netText->setReadOnly(true);
    netText->setPlainText(
        "Planned network support:\n"
        "- NIC emulation with pre-generated NVRAM\n"
        "- Ethernet boot / net boot paths\n"
        "- packet I/O and driver integration\n"
        "- later IRIX TCP/IP support\n");
    netLayout->addWidget(netText);

    layout->addWidget(netBox);
    tabs_->addTab(page, "Network");
}

void MainWindow::setupDiagnosticsTab() {
    auto* page = new QWidget(this);
    auto* layout = new QVBoxLayout(page);

    auto* diagBox = new QGroupBox("Diagnostics and boots", page);
    auto* diagLayout = new QVBoxLayout(diagBox);

    auto* diagText = new QTextEdit(diagBox);
    diagText->setReadOnly(true);
    diagText->setPlainText(
        "Current status:\n"
        "- PROM boot path and reset-vector handling are under development\n"
        "- early CPU and memory model are working\n"
        "- graphics and sound will be introduced once the PROM path is stable\n"
        "- storage, network, and filesystem support are planned next\n");
    diagLayout->addWidget(diagText);

    layout->addWidget(diagBox);
    tabs_->addTab(page, "Diagnostics");
}
