#pragma once

#include <array>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <system_error>

#include <toml++/toml.hpp>

#include "core/common.hpp"
#include "core/indy_hardware.hpp"

namespace indyemu {

inline std::filesystem::path configRoot() {
    if (const char* env = std::getenv("INDYEMU_CONFIG_DIR")) {
        return std::filesystem::path(env);
    }

#if defined(_WIN32)
    return std::filesystem::path("indyemu");
#elif defined(__APPLE__)
    return std::filesystem::path("indyemu");
#else
    return std::filesystem::path("config") / "indyemu";
#endif
}

inline std::filesystem::path defaultProfilePath(const std::string& profile_name = "default") {
    return configRoot() / (profile_name + ".toml");
}

inline std::filesystem::path embeddedPromPath() {
    const std::filesystem::path local_embedded = configRoot() / "prom_embedded.bin";
    if (std::filesystem::exists(local_embedded)) {
        return local_embedded;
    }

    const std::array<std::filesystem::path, 5> candidates = {
        std::filesystem::path("samples/ip24prom.070-9101-007.bin"),
        std::filesystem::path("./samples/ip24prom.070-9101-007.bin"),
        std::filesystem::path("ip24prom.070-9101-007.bin"),
        std::filesystem::path("samples/prom_embedded.bin"),
        std::filesystem::path("./samples/prom_embedded.bin"),
    };

    for (const auto& candidate : candidates) {
        if (std::filesystem::exists(candidate)) {
            std::filesystem::create_directories(local_embedded.parent_path());
            std::filesystem::copy_file(candidate, local_embedded, std::filesystem::copy_options::overwrite_existing);
            return local_embedded;
        }
    }

    return local_embedded;
}

inline std::string defaultProfileToml(const std::string& profile_name = "default") {
    std::string toml;
    toml += "title = \"" + profile_name + "\"\n\n";
    toml += "[platform]\n";
    toml += "name = \"SGI Indy\"\n";
    toml += "model = \"Indy / IRIS workstation\"\n";
    toml += "cpu = \"MIPS R4400-class\"\n";
    toml += "boot_device = \"PROM\"\n\n";

    toml += "[machine]\n";
    toml += "ram_bytes = 134217728\n";
    toml += "prom_image = \"prom_embedded.bin\"\n";
    toml += "graphics_model = \"24-bit XL framebuffer\"\n";
    toml += "sound_model = \"Indy audio pipeline\"\n";
    toml += "has_storage = false\n";
    toml += "has_network = true\n";
    toml += "has_sound = true\n\n";

    toml += "[memory]\n";
    toml += "ram_base = 0x80000000\n";
    toml += "prom_base = 0x1FC00000\n";
    toml += "io_base = 0x1F000000\n\n";

    toml += "[graphics]\n";
    toml += "width = 1024\n";
    toml += "height = 768\n";
    toml += "bits_per_pixel = 24\n\n";

    toml += "[storage]\n";
    toml += "raw_disk_dir = \"disks\"\n";
    toml += "boot_disk = \"disks/boot.raw\"\n";
    toml += "install_media = \"\"\n\n";

    toml += "[network]\n";
    toml += "mac = \"08:00:69:12:34:56\"\n";
    toml += "enabled = true\n\n";

    toml += "[prom]\n";
    toml += "embedded = \"prom_embedded.bin\"\n";
    toml += "reset_vector = \"0xBFC00000\"\n";
    return toml;
}

inline bool ensureConfigLayout() {
    const std::filesystem::path root = configRoot();
    std::error_code ec;
    std::filesystem::create_directories(root, ec);
    std::filesystem::create_directories(root / "disks", ec);
    if (ec) {
        return false;
    }

    const auto embedded = embeddedPromPath();
    if (!std::filesystem::exists(embedded) && std::filesystem::exists("samples/ip24prom.070-9101-007.bin")) {
        std::filesystem::copy_file("samples/ip24prom.070-9101-007.bin", embedded, std::filesystem::copy_options::overwrite_existing);
    }

    return true;
}

inline bool writeDefaultProfile(const std::string& profile_name = "default") {
    ensureConfigLayout();

    const std::filesystem::path profile_path = defaultProfilePath(profile_name);
    std::ofstream profile(profile_path, std::ios::binary | std::ios::trunc);
    if (!profile) {
        return false;
    }
    profile << defaultProfileToml(profile_name);
    profile.close();

    const std::filesystem::path boot_disk = configRoot() / "disks" / "boot.raw";
    if (!std::filesystem::exists(boot_disk)) {
        std::ofstream disk(boot_disk, std::ios::binary | std::ios::trunc);
        if (!disk) {
            return false;
        }
        disk.seekp(1024 * 1024 - 1, std::ios::beg);
        disk.write("\0", 1);
    }

    return true;
}

inline bool loadConfigFromToml(const std::string& path, MachineConfig& config) {
    try {
        auto toml_file = toml::parse_file(path);

        // Parse [machine] section
        if (auto machine = toml_file["machine"]; machine) {
            if (auto ram_bytes = machine["ram_bytes"]; ram_bytes) {
                config.ram_bytes = static_cast<u32>(ram_bytes.as_integer()->get());
            }
            if (auto prom_size = machine["prom_size_bytes"]; prom_size) {
                config.prom_size_bytes = static_cast<u32>(prom_size.as_integer()->get());
            }
            if (auto graphics = machine["graphics_model"]; graphics) {
                config.graphics_model = graphics.as_string()->get();
            }
            if (auto sound = machine["sound_model"]; sound) {
                config.sound_model = sound.as_string()->get();
            }
            if (auto cpu = machine["cpu_model"]; cpu) {
                config.cpu_model = cpu.as_string()->get();
            }
            if (auto boot = machine["boot_device"]; boot) {
                config.boot_device = boot.as_string()->get();
            }
        }

        // Parse [graphics] section
        if (auto graphics = toml_file["graphics"]; graphics) {
            if (auto width = graphics["width"]; width) {
                config.framebuffer_width = static_cast<u32>(width.as_integer()->get());
            }
            if (auto height = graphics["height"]; height) {
                config.framebuffer_height = static_cast<u32>(height.as_integer()->get());
            }
            if (auto bpp = graphics["bits_per_pixel"]; bpp) {
                config.bits_per_pixel = static_cast<u32>(bpp.as_integer()->get());
            }
        }

        // Parse [network] section
        if (auto network = toml_file["network"]; network) {
            if (auto mac = network["mac"]; mac) {
                std::string mac_str = mac.as_string()->get();
                // Parse MAC address in format "08:00:69:12:34:56"
                int parts[6];
                if (std::sscanf(mac_str.c_str(), "%02x:%02x:%02x:%02x:%02x:%02x",
                               &parts[0], &parts[1], &parts[2],
                               &parts[3], &parts[4], &parts[5]) == 6) {
                    for (int i = 0; i < 6; ++i) {
                        config.ethernet_mac[i] = static_cast<u8>(parts[i]);
                    }
                }
            }
            if (auto enabled = network["enabled"]; enabled) {
                config.has_network = enabled.as_boolean()->get();
            }
        }

        // Parse [storage] section
        if (auto storage = toml_file["storage"]; storage) {
            if (auto has_scsi = storage["has_scsi"]; has_scsi) {
                config.has_scsi = has_scsi.as_boolean()->get();
            }
            if (auto has_efs = storage["has_efs"]; has_efs) {
                config.has_efs = has_efs.as_boolean()->get();
            }
        }

        // Parse [audio] section
        if (auto audio = toml_file["audio"]; audio) {
            if (auto enabled = audio["enabled"]; enabled) {
                config.has_sound = enabled.as_boolean()->get();
            }
        }

        // Parse [prom] section
        if (auto prom = toml_file["prom"]; prom) {
            if (auto enabled = prom["enabled"]; enabled) {
                config.has_prom = enabled.as_boolean()->get();
            }
        }

        return true;
    } catch (const toml::parse_error& err) {
        std::cerr << "Failed to parse TOML config at " << path << ": " << err.what() << "\n";
        return false;
    } catch (const std::exception& err) {
        std::cerr << "Error loading config from " << path << ": " << err.what() << "\n";
        return false;
    }
}

}  // namespace indyemu
