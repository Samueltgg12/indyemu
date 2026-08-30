#include "core/memory.hpp"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace indyemu {

Memory::Memory() : ram_(new u8[kRamSize]{}), prom_(new u8[kPromSize]{}) {
    reset();
}

u32 Memory::translateAddress(u32 address) {
    if (address >= 0xA0000000u && address < 0xC0000000u) {
        return address & 0x1FFFFFFFu;
    }
    if (address >= 0xBFC00000u && address < 0xC0000000u) {
        return address & 0x1FFFFFFFu;
    }
    return address;
}

void Memory::reset() {
    if (ram_) {
        std::fill_n(ram_.get(), kRamSize, 0);
    }
    if (prom_) {
        std::fill_n(prom_.get(), kPromSize, 0);
    }
    prom_loaded_ = false;
}

bool Memory::loadProm(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        return false;
    }

    file.read(reinterpret_cast<char*>(prom_.get()), kPromSize);
    prom_loaded_ = true;
    return file.good() || file.eof();
}

bool Memory::isPromAddress(u32 address) const {
    const u32 translated = translateAddress(address);
    return translated >= kPromBase && translated < (kPromBase + kPromSize);
}

bool Memory::isRamAddress(u32 address) const {
    const u32 translated = translateAddress(address);
    return translated >= kRamBase && translated < (kRamBase + kRamSize);
}

u8 Memory::read8(u32 address) const {
    const u32 translated = translateAddress(address);
    if (isPromAddress(translated)) {
        const u32 offset = translated - kPromBase;
        return prom_[offset % kPromSize];
    }
    if (isRamAddress(translated)) {
        const u32 offset = translated - kRamBase;
        return ram_[offset % kRamSize];
    }
    return 0;
}

u16 Memory::read16(u32 address) const {
    const u32 value = (static_cast<u32>(read8(address)) |
                       (static_cast<u32>(read8(address + 1)) << 8));
    return static_cast<u16>(value);
}

u32 Memory::read32(u32 address) const {
    const u32 value = (static_cast<u32>(read8(address)) << 24) |
                       (static_cast<u32>(read8(address + 1)) << 16) |
                       (static_cast<u32>(read8(address + 2)) << 8) |
                       (static_cast<u32>(read8(address + 3)));
    return value;
}

void Memory::write8(u32 address, u8 value) {
    const u32 translated = translateAddress(address);
    if (isRamAddress(translated)) {
        const u32 offset = translated - kRamBase;
        ram_[offset % kRamSize] = value;
    }
}

void Memory::write16(u32 address, u16 value) {
    write8(address, static_cast<u8>(value & 0xFFu));
    write8(address + 1, static_cast<u8>((value >> 8) & 0xFFu));
}

void Memory::write32(u32 address, u32 value) {
    write8(address, static_cast<u8>((value >> 24) & 0xFFu));
    write8(address + 1, static_cast<u8>((value >> 16) & 0xFFu));
    write8(address + 2, static_cast<u8>((value >> 8) & 0xFFu));
    write8(address + 3, static_cast<u8>(value & 0xFFu));
}

void Memory::dumpRange(u32 start, std::size_t length) const {
    std::cout << "Memory dump from 0x" << std::hex << std::setfill('0') << std::setw(8)
              << start << ":\n";

    for (std::size_t i = 0; i < length; ++i) {
        if ((i % 16) == 0) {
            std::cout << "\n0x" << std::setw(8) << std::hex << (start + static_cast<u32>(i)) << ": ";
        }
        std::cout << std::setw(2) << std::hex << static_cast<int>(read8(start + static_cast<u32>(i))) << ' ';
    }
    std::cout << std::dec << "\n";
}

}  // namespace indyemu
