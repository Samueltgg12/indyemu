// src/gui/main.cpp
#include "config/indy_config.hpp"
#include "core/common.hpp"
#include "core/indy_system.hpp"
#include "gui/launcher_window.hpp"
#include "gui/main_window.hpp"

#include <QApplication>
#include <QSoundEffect>
#include <QThread>
#include <QTimer>
#include <QUrl>

#include <atomic>
#include <filesystem>
#include <iostream>
#include <memory>

namespace {

std::string resolvePromPath(const std::string& requested) {
    if (!requested.empty()) {
        return requested;
    }

    const auto embedded = indyemu::embeddedPromPath();
    if (!embedded.empty() && std::filesystem::exists(embedded)) {
        return embedded.string();
    }

    return {};
}

class EmulationWorker : public QObject {
    Q_OBJECT
public:
    explicit EmulationWorker(indyemu::IndySystem* system)
        : system_(system), running_(true) {}

    void stop() { running_ = false; }

public slots:
    void runEmulation() {
        while (running_) {
            system_->run(1000);
            QThread::msleep(1); // Yield to avoid 100% CPU
        }
        emit finished();
    }

signals:
    void finished();

private:
    indyemu::IndySystem* system_;
    std::atomic<bool> running_;
};

}  // namespace

namespace {

// Plays the SGI "launch" startup sound if the file is present.
void playLaunchSound() {
    const std::filesystem::path launch_wav =
        "samples/GUI References/GUI Sounds/launch.wav";
    if (!std::filesystem::exists(launch_wav)) {
        return;
    }
    QSoundEffect* effect = new QSoundEffect;
    effect->setSource(QUrl::fromLocalFile(
        QString::fromStdString(launch_wav.string())));
    effect->setVolume(0.8f);
    effect->play();
    // The effect is parented to nothing; keep it alive until it finishes.
    QObject::connect(effect, &QSoundEffect::playingChanged, effect, [effect]() {
        if (!effect->isPlaying()) {
            effect->deleteLater();
        }
    });
}

}  // namespace

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    std::string cli_prom_path;
    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg.rfind("--", 0) == 0) {
            std::cerr << "Warning: unknown option '" << arg << "'\n";
        } else if (cli_prom_path.empty()) {
            cli_prom_path = arg;
        } else {
            std::cerr << "Warning: ignoring extra argument '" << arg << "'\n";
        }
    }

    indyemu::ensureConfigLayout();
    indyemu::writeDefaultProfile("default");

    // Play the SGI launch sound when the launcher appears.
    playLaunchSound();

    // Show the launcher first; emulation starts only after the user clicks
    // "Launch". The launcher hides itself (not closes) on launch so it stays
    // alive for the lifetime of the app.
    indyemu::LauncherWindow launcher;
    launcher.show();

    QObject::connect(&launcher, &indyemu::LauncherWindow::quitRequested,
                     &app, &QApplication::quit);

    QObject::connect(&launcher, &indyemu::LauncherWindow::launchRequested,
                     &app, [&](const indyemu::LauncherWindow::Config& cfg) {
        // Build the machine configuration from the launcher selections.
        indyemu::MachineConfig machine;
        machine.ram_bytes = static_cast<indyemu::u32>(cfg.ramSizeMB) * 1024u * 1024u;
        machine.has_sound = cfg.enableAudio;
        machine.has_network = cfg.enableNetwork;
        machine.framebuffer_width = static_cast<indyemu::u32>(cfg.videoWidth);
        machine.framebuffer_height = static_cast<indyemu::u32>(cfg.videoHeight);

        auto system = std::make_unique<indyemu::IndySystem>(machine);

        std::string prom_path = cfg.promPath.toStdString();
        if (prom_path.empty()) {
            prom_path = resolvePromPath(cli_prom_path);
        }
        if (!prom_path.empty()) {
            if (!system->loadProm(prom_path)) {
                std::cerr << "Failed to load PROM image: " << prom_path << "\n";
                return;
            }
            std::cout << "Loaded PROM image: " << prom_path << "\n";
        } else {
            std::cout << "No PROM image specified. Running with a blank RAM/PROM model.\n";
        }

        MainWindow* window = new MainWindow;
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->setRex3(system->rex3());
        if (cfg.fullscreen) {
            window->showFullScreen();
        } else {
            window->resize(cfg.videoWidth, cfg.videoHeight);
            window->show();
        }

        // Run emulation in a separate thread so the GUI stays responsive.
        QThread* emu_thread = new QThread;
        EmulationWorker* worker = new EmulationWorker(system.get());
        worker->moveToThread(emu_thread);

        QObject::connect(emu_thread, &QThread::started, worker, &EmulationWorker::runEmulation);
        QObject::connect(&app, &QApplication::aboutToQuit, worker, &EmulationWorker::stop);
        QObject::connect(worker, &EmulationWorker::finished, emu_thread, &QThread::quit);
        QObject::connect(emu_thread, &QThread::finished, emu_thread, &QThread::deleteLater);
        QObject::connect(emu_thread, &QThread::finished, worker, &QObject::deleteLater);

        emu_thread->start();

        // Keep the system alive for the lifetime of the emulation thread.
        QObject::connect(emu_thread, &QThread::finished, &app,
                         [system = std::move(system)]() mutable {
                             system.reset();
                         });
    });

    const int ret = app.exec();

    return ret;
}

#include "main.moc"
