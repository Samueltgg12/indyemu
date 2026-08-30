#include "core/indy_system.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace {

std::filesystem::path findPromPath() {
    const std::vector<std::filesystem::path> candidates = {
        std::filesystem::path("config/indyemu/prom_embedded.bin"),
        std::filesystem::path("../config/indyemu/prom_embedded.bin"),
        std::filesystem::path("../../config/indyemu/prom_embedded.bin"),
        std::filesystem::path("../../../config/indyemu/prom_embedded.bin"),
    };

    for (const auto& candidate : candidates) {
        if (std::filesystem::exists(candidate)) {
            return candidate;
        }
    }

    auto cwd = std::filesystem::current_path();
    for (auto probe = cwd; !probe.empty(); probe = probe.parent_path()) {
        const auto candidate = probe / "config" / "indyemu" / "prom_embedded.bin";
        if (std::filesystem::exists(candidate)) {
            return candidate;
        }
    }

    return {};
}

}  // namespace

int main() {
    const auto prom_path = findPromPath();
    if (prom_path.empty()) {
        std::cerr << "missing embedded PROM in current workspace\n";
        return 2;
    }

    indyemu::MachineConfig config;
    config.ram_bytes = 128u * 1024u * 1024u;
    config.prom_size_bytes = 512u * 1024u;

    indyemu::IndySystem system(config);
    if (!system.loadProm(prom_path.string())) {
        std::cerr << "failed to load PROM image\n";
        return 3;
    }

    const auto& cpu = system.cpu();
    const auto& memory = system.memory();

    if (cpu.registers().pc != 0xBFC00000u) {
        std::cerr << "reset vector mismatch: got 0x" << std::hex << cpu.registers().pc << " expected 0xBFC00000\n";
        return 1;
    }

    if (memory.regionForAddress(0xBFC00000u) != indyemu::Memory::Region::kProm) {
        std::cerr << "reset vector should map to PROM\n";
        return 4;
    }

    const auto first_word = memory.read32(0xBFC00000u);
    if (first_word != 0x0BF000F0u) {
        std::cerr << "unexpected first PROM word: 0x" << std::hex << first_word << "\n";
        return 5;
    }

    system.cpu().step();
    if (cpu.registers().pc != 0xBFC00004u) {
        std::cerr << "instruction advance mismatch after one step: got 0x" << std::hex << cpu.registers().pc << " expected 0xBFC00004\n";
        return 6;
    }

    return 0;
}
