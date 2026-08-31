#ifndef INDYEMU_GIO64_BUS_HPP
#define INDYEMU_GIO64_BUS_HPP

#include <cstdint>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

namespace indyemu {

class IODevice {
public:
    virtual ~IODevice() = default;
    virtual bool contains(uint32_t address) const = 0;
    virtual uint32_t read32(uint32_t address) const = 0;
    virtual void write32(uint32_t address, uint32_t value) = 0;
    virtual std::string descriptionFor(uint32_t address) const { return "IO device"; }
};

class GIO64Bus {
public:
    GIO64Bus() = default;
    ~GIO64Bus() = default;

    void addDevice(IODevice* device, uint32_t base_addr, uint32_t size);
    bool contains(uint32_t address) const;
    uint32_t read32(uint32_t address) const;
    void write32(uint32_t address, uint32_t value);
    std::string descriptionFor(uint32_t address) const;
    void reset();

private:
    struct DeviceEntry {
        IODevice* device;
        uint32_t base_addr;
        uint32_t size; // size in bytes
    };

    std::vector<DeviceEntry> devices_;
    // Fallback storage for IO addresses not claimed by any registered device.
    // Keeps the bus permissive for unimplemented registers (reads return last
    // written value, or 0 if never written).
    mutable std::unordered_map<uint32_t, uint32_t> fallback_regs_;
};

} // namespace indyemu

#endif // INDYEMU_GIO64_BUS_HPP