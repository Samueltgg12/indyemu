#include "config/indy_config.hpp"
#include "core/indy_system.hpp"
#include "gui/main_window.hpp"

#include <QApplication>
#include <QThread>
#include <QTimer>

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
    }

signals:
    void finished();

private:
    indyemu::IndySystem* system_;
    std::atomic<bool> running_;
};

}  // namespace

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    std::string prom_path;
    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg.rfind("--", 0) == 0) {
            std::cerr << "Warning: unknown option '" << arg << "'\n";
        } else if (prom_path.empty()) {
            prom_path = arg;
        } else {
            std::cerr << "Warning: ignoring extra argument '" << arg << "'\n";
        }
    }

    indyemu::ensureConfigLayout();
    indyemu::writeDefaultProfile("default");

    indyemu::MachineConfig config;
    const auto config_path = indyemu::defaultProfilePath("default");
    if (std::filesystem::exists(config_path)) {
        if (!indyemu::loadConfigFromToml(config_path.string(), config)) {
            std::cerr << "Warning: Failed to load config from " << config_path
                      << ", using defaults\n";
        }
    }

    auto system = std::make_unique<indyemu::IndySystem>(config);

    if (prom_path.empty()) {
        prom_path = resolvePromPath({});
    }
    if (!prom_path.empty()) {
        if (!system->loadProm(prom_path)) {
            std::cerr << "Failed to load PROM image: " << prom_path << "\n";
            return 1;
        }
        std::cout << "Loaded PROM image: " << prom_path << "\n";
    } else {
        std::cout << "No PROM image specified. Running with a blank RAM/PROM model.\n";
    }

    MainWindow window;
    window.setRex3(system->rex3());
    window.show();

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

    return app.exec();
}

#include "main.moc"
