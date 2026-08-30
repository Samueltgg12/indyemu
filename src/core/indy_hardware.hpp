#pragma once

#include "core/common.hpp"

#include <array>
#include <cstddef>
#include <string>
#include <vector>

namespace indyemu {

struct MachineConfig {
    static constexpr u32 kRamSizeBytes = 128u * 1024u * 1024u;
    static constexpr u32 kDefaultPromSizeBytes = 512u * 1024u;
    static constexpr u32 kFramebufferWidth = 1024u;
    static constexpr u32 kFramebufferHeight = 768u;
    static constexpr u32 kFramebufferBitsPerPixel = 24u;

    std::string cpu_model = "MIPS R4400-class";
    std::string graphics_model = "24-bit XL framebuffer";
    std::string sound_model = "Indy audio pipeline";
    std::string boot_device = "PROM";

    u32 ram_bytes = kRamSizeBytes;
    u32 prom_size_bytes = kDefaultPromSizeBytes;
    u32 framebuffer_width = kFramebufferWidth;
    u32 framebuffer_height = kFramebufferHeight;
    u32 bits_per_pixel = kFramebufferBitsPerPixel;

    std::array<u8, 6> ethernet_mac = {0x08u, 0x00u, 0x69u, 0x12u, 0x34u, 0x56u};

    bool has_cdrom = true;
    bool has_efs = true;
    bool has_scsi = true;
    bool has_network = true;
    bool has_sound = true;

    bool has_prom = true;
    bool has_nvram = true;
};

class IndyHardware {
public:
    explicit IndyHardware(MachineConfig config = MachineConfig{});

    const MachineConfig& config() const { return config_; }

private:
    MachineConfig config_;
};

}  // namespace indyemu
