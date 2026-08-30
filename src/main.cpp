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

    indyemu::ensureConfigLayout();
    indyemu::writeDefaultProfile("default");

    indyemu::MachineConfig config;
    config.ram_bytes = 128u * 1024u * 1024u;
    config.boot_device = "PROM";
    config.prom_size_bytes = 512u * 1024u;

    indyemu::IndySystem system(config);

    std::string prom_path;
    if (argc > 1) {
        prom_path = argv[1];
    } else {
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

    system.run(20);
    system.dumpState();
    return 0;
}
