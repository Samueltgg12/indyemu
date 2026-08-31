#include "config/indy_config.hpp"
#include "core/indy_system.hpp"

#include <filesystem>
#include <iostream>
#include <string>

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

}  // namespace

int main(int argc, char** argv) {
    std::cout << "IndyEmu v0.1\n";
    std::cout << "SGI Indy bootstrap emulator for MIPS R4400-class system emulation\n\n";

    bool trace = false;
    std::size_t steps = 20;
    std::string prom_path;

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--trace") {
            trace = true;
        } else if (arg == "--steps" && i + 1 < argc) {
            steps = static_cast<std::size_t>(std::stoul(argv[++i]));
        } else if (arg == "--steps") {
            std::cerr << "Warning: --steps requires a value\n";
        } else if (arg.rfind("--", 0) == 0) {
            std::cerr << "Warning: unknown option '" << arg << "'\n";
        } else if (prom_path.empty()) {
            // Any non-flag argument is the PROM image path, regardless of position.
            prom_path = arg;
        } else {
            std::cerr << "Warning: ignoring extra argument '" << arg << "'\n";
        }
    }

    indyemu::ensureConfigLayout();
    indyemu::writeDefaultProfile("default");

    indyemu::MachineConfig config;
    // Load from TOML config file
    const auto config_path = indyemu::defaultProfilePath("default");
    if (std::filesystem::exists(config_path)) {
        if (!indyemu::loadConfigFromToml(config_path.string(), config)) {
            std::cerr << "Warning: Failed to load config from " << config_path << ", using defaults\n";
        }
    }

    indyemu::IndySystem system(config);
    system.setTraceEnabled(trace);

    if (prom_path.empty()) {
        prom_path = resolvePromPath({});
    }

    if (!prom_path.empty()) {
        if (!system.loadProm(prom_path)) {
            std::cerr << "Failed to load PROM image: " << prom_path << "\n";
            return 1;
        }
        std::cout << "Loaded PROM image: " << prom_path << "\n";
        std::cout << "Config root: " << indyemu::configRoot() << "\n";
    } else {
        std::cout << "No PROM image specified. Running with a blank RAM/PROM model.\n";
    }

    system.run(steps);
    system.dumpState();
    return 0;
}
