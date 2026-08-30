#pragma once

#include <array>
#include <filesystem>
#include <fstream>
#include <string>
#include <system_error>

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

}  // namespace indyemu
