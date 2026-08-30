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
    registers_ = RegisterMap{};
}

Memory::Region Memory::regionForAddress(u32 address) const {
    const u32 translated = translateAddress(address);
    if (isPromAddress(translated)) {
        return Region::kProm;
    }
    if (isRamAddress(translated)) {
        return Region::kRam;
    }
    if (isIoRegisterAddress(translated)) {
        return Region::kIo;
    }
    return Region::kUnknown;
}

const char* Memory::regionName(u32 address) const {
    switch (regionForAddress(address)) {
        case Region::kRam:
            return "RAM";
        case Region::kProm:
            return "PROM";
        case Region::kIo:
            return "I/O";
        case Region::kUnknown:
        default:
            return "unknown";
    }
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

bool Memory::isIoRegisterAddress(u32 address) const {
    const u32 translated = translateAddress(address);
    return translated >= kIoBase && translated < (kIoBase + 0x01000000u) && !isPromAddress(translated);
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
    if (isIoRegisterAddress(translated)) {
        const u32 aligned = translated & ~3u;
        const u32 reg = registers_.read32(aligned);
        const u32 byte_index = (translated & 3u);
        return static_cast<u8>((reg >> (byte_index * 8u)) & 0xFFu);
    }
    return 0;
}

u16 Memory::read16(u32 address) const {
    const u32 translated = translateAddress(address);
    if (isIoRegisterAddress(translated)) {
        const u32 aligned = translated & ~1u;
        const u32 reg = registers_.read32(aligned);
        if ((translated & 1u) == 0u) {
            return static_cast<u16>(reg & 0xFFFFu);
        }
        return static_cast<u16>((reg >> 8u) & 0xFFFFu);
    }
    const u32 value = (static_cast<u32>(read8(address)) |
                       (static_cast<u32>(read8(address + 1)) << 8));
    return static_cast<u16>(value);
}

u32 Memory::read32(u32 address) const {
    const u32 translated = translateAddress(address);
    if (isIoRegisterAddress(translated)) {
        return registers_.read32(translated);
    }
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
        return;
    }
    if (isIoRegisterAddress(translated)) {
        const u32 aligned = translated & ~3u;
        const u32 shift = (translated & 3u) * 8u;
        const u32 mask = 0xFFu << shift;
        const u32 current = registers_.read32(aligned);
        registers_.write32(aligned, (current & ~mask) | (static_cast<u32>(value) << shift));
    }
}

void Memory::write16(u32 address, u16 value) {
    const u32 translated = translateAddress(address);
    if (isIoRegisterAddress(translated)) {
        const u32 aligned = translated & ~1u;
        if ((translated & 1u) == 0u) {
            registers_.write32(aligned, (registers_.read32(aligned) & 0xFFFF0000u) | value);
            return;
        }
        registers_.write32(aligned, (registers_.read32(aligned) & 0x0000FFFFu) | (static_cast<u32>(value) << 8u));
        return;
    }
    write8(address, static_cast<u8>(value & 0xFFu));
    write8(address + 1, static_cast<u8>((value >> 8) & 0xFFu));
}

void Memory::write32(u32 address, u32 value) {
    const u32 translated = translateAddress(address);
    if (isIoRegisterAddress(translated)) {
        registers_.write32(translated, value);
        return;
    }
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
