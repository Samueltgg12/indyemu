// src/system/gio64_bus.cpp
#include "gio64_bus.hpp"
#include <algorithm>
#include <stdexcept>

namespace indyemu {

void GIO64Bus::addDevice(IODevice* device, uint32_t base_addr, uint32_t size) {
    // Check for overlapping address ranges (optional, but good for debugging)
    for (const auto& entry : devices_) {
        if (!(base_addr + size <= entry.base_addr || base_addr >= entry.base_addr + entry.size)) {
            throw std::runtime_error("Overlapping address ranges in GIO64Bus");
        }
    }
    devices_.push_back({device, base_addr, size});
}

bool GIO64Bus::contains(uint32_t address) const {
    return std::any_of(devices_.begin(), devices_.end(),
                       [address](const DeviceEntry& entry) {
                           return address >= entry.base_addr && address < (entry.base_addr + entry.size);
                       });
}

uint32_t GIO64Bus::read32(uint32_t address) const {
    for (const auto& entry : devices_) {
        if (address >= entry.base_addr && address < (entry.base_addr + entry.size)) {
            return entry.device->read32(address);
        }
    }
    // Fallback: return last written value for unclaimed addresses, else 0.
    const auto it = fallback_regs_.find(address);
    return (it != fallback_regs_.end()) ? it->second : 0u;
}

void GIO64Bus::write32(uint32_t address, uint32_t value) {
    for (auto& entry : devices_) {
        if (address >= entry.base_addr && address < (entry.base_addr + entry.size)) {
            entry.device->write32(address, value);
            return;
        }
    }
    // Fallback: store value for unclaimed addresses.
    fallback_regs_[address] = value;
}

std::string GIO64Bus::descriptionFor(uint32_t address) const {
    for (const auto& entry : devices_) {
        if (address >= entry.base_addr && address < (entry.base_addr + entry.size)) {
            return entry.device->descriptionFor(address);
        }
    }
    return "unknown GIO64 device";
}

} // namespace indyemu