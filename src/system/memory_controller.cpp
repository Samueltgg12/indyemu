// src/system/memory_controller.cpp
#include "system/memory_controller.hpp"

#include <iostream>

#include "io/eeprom_93c56.hpp"

namespace indyemu {

MemoryController::MemoryController() {
    reset();
}

void MemoryController::reset() {
    regs_.fill(0);
    // SYSID: CHIP_REV = 1 (Revision B), EISA present = 1.
    regs_[SYSID / 4u] = 0x00000011u;
    // CTRLD: refresh counter preload for 62.5us at 50MHz = 3125 (0x0C35).
    regs_[CTRLD / 4u] = 0x00000C35u;
    // RPSS_DIVIDER: DIV=4, INC=1 (50MHz processor).
    regs_[RPSS_DIVIDER / 4u] = 0x00000104u;
    refreshCounter_ = regs_[CTRLD / 4u] & 0xFFFFu;
    watchdogCounter_ = 0;
    watchdogExpired_ = false;
    std::cout << "[mc] Memory controller reset\n";
}

void MemoryController::configureMemory(uint32_t ramBytes) {
    // SIMM geometries supported by the MC (hardware-docs/mc.md section 5.12).
    // A bank is four identical SIMMs; capacity below is per bank.
    struct Simm { uint32_t bankBytes; uint32_t msize; uint32_t subbanks; };
    static constexpr Simm kSimms[] = {
        {128u * 1024 * 1024, 0x1F, 1},  // 8M x 36, 2 subbanks
        { 64u * 1024 * 1024, 0x0F, 0},  // 4M x 36
        { 32u * 1024 * 1024, 0x07, 1},  // 2M x 36, 2 subbanks
        { 16u * 1024 * 1024, 0x03, 0},  // 1M x 36
        {  8u * 1024 * 1024, 0x01, 1},  // 512K x 36, 2 subbanks
        {  4u * 1024 * 1024, 0x00, 0},  // 256K x 36
    };

    uint32_t memcfg[2] = {0u, 0u};
    uint32_t remaining = ramBytes;
    uint32_t base = 0;  // in units compared against address bits 29:22
    for (uint32_t bank = 0; bank < 4 && remaining > 0; ++bank) {
        for (const Simm& simm : kSimms) {
            if (simm.bankBytes <= remaining) {
                // Base field holds address bits 29:22 of the bank start.
                const uint32_t baseField = (base >> 22) & 0xFFu;
                uint32_t field = baseField | (simm.msize << 8) |
                                 (1u << 13) | (simm.subbanks << 14);
                // Banks 0/2 occupy the high half, banks 1/3 the low half.
                if ((bank & 1u) == 0) {
                    field <<= 16;
                }
                memcfg[bank / 2] |= field;
                base += simm.bankBytes;
                remaining -= simm.bankBytes;
                break;
            }
        }
    }
    regs_[MEMCFG0 / 4u] = memcfg[0];
    regs_[MEMCFG1 / 4u] = memcfg[1];
}

void MemoryController::tick(uint32_t cycles) {
    // Refresh counter counts down at CPU frequency and reloads from CTRLD.
    while (cycles >= refreshCounter_) {
        cycles -= refreshCounter_;
        refreshCounter_ = regs_[CTRLD / 4u] & 0xFFFFu;
        if (refreshCounter_ == 0) {
            refreshCounter_ = 1;  // avoid a zero-length reload loop
        }
        // A refresh burst occurred: the 20-bit watchdog counts these when
        // enabled via the DOG bit (CPUCTRL0 bit 8). See mc.md section 5.3.
        if (regs_[CPUCTRL0 / 4u] & (1u << 8)) {
            watchdogCounter_ = (watchdogCounter_ + 1) & 0xFFFFFu;
            if (watchdogCounter_ == 0) {
                watchdogExpired_ = true;
            }
        }
    }
    refreshCounter_ -= cycles;
    regs_[REF_CTR / 4u] = refreshCounter_ & 0xFFFFu;
}

bool MemoryController::contains(uint32_t address) const {
    return address >= kBase && address < (kBase + kSize);
}

uint32_t MemoryController::read32(uint32_t address) const {
    if (!contains(address)) {
        return 0u;
    }
    const uint32_t offset = address - kBase;
    const std::size_t index = offset / 4u;
    if (index >= regs_.size()) {
        return 0u;
    }
    uint32_t value = regs_[index];
    if (offset == DOGC) {
        // DOGC reads back the live 20-bit watchdog counter.
        value = watchdogCounter_ & 0xFFFFFu;
    } else if (offset == EEROM) {
        // SI bit reflects the EEPROM DO pin; it cannot be written.
        value &= ~kEepromSi;
        if (eeprom_ != nullptr && eeprom_->dataOut()) {
            value |= kEepromSi;
        }
    }
    return value;
}

void MemoryController::write32(uint32_t address, uint32_t value) {
    if (!contains(address)) {
        return;
    }
    const uint32_t offset = address - kBase;
    const std::size_t index = offset / 4u;
    if (index >= regs_.size()) {
        return;
    }

    // Writing any MC register resets the watchdog counter (mc.md section 5.3).
    watchdogCounter_ = 0;

    // Read-only registers ignore writes.
    switch (static_cast<Register>(offset)) {
        case DOGC:            // write = watchdog clear
        case SYSID:
        case REF_CTR:
        case CPU_ERROR_ADDR:
        case CPU_ERROR_STAT:  // write = clear error status
        case GIO_ERROR_ADDR:
        case GIO_ERROR_STAT:  // write = clear error status
        case RPSS_CTR:
            return;
        default:
            break;
    }

    if (offset == EEROM) {
        // Drive the EEPROM pins from the CS/SCK/SO bits. The SI bit is
        // read-only and never stored.
        if (eeprom_ != nullptr) {
            eeprom_->setDataIn((value & kEepromSo) != 0);
            eeprom_->setChipSelect((value & kEepromCs) != 0);
            eeprom_->setClock((value & kEepromSck) != 0);
        }
        value &= ~kEepromSi;
    }

    regs_[index] = value;
}

std::string MemoryController::descriptionFor(uint32_t address) const {
    if (!contains(address)) {
        return "unknown address";
    }
    const uint32_t offset = address - kBase;
    switch (static_cast<Register>(offset)) {
        case CPUCTRL0:       return "CPUCTRL0";
        case CPUCTRL1:       return "CPUCTRL1";
        case DOGC:           return "DOGC/DOGR";
        case SYSID:          return "SYSID";
        case RPSS_DIVIDER:   return "RPSS_DIVIDER";
        case EEROM:          return "EEROM";
        case CTRLD:          return "CTRLD";
        case REF_CTR:        return "REF_CTR";
        case GIO64_ARB:      return "GIO64_ARB";
        case CPU_TIME:       return "CPU_TIME";
        case LB_TIME:        return "LB_TIME";
        case MEMCFG0:        return "MEMCFG0";
        case MEMCFG1:        return "MEMCFG1";
        case CPU_MEMACC:     return "CPU_MEMACC";
        case GIO_MEMACC:     return "GIO_MEMACC";
        case CPU_ERROR_ADDR: return "CPU_ERROR_ADDR";
        case CPU_ERROR_STAT: return "CPU_ERROR_STAT";
        case GIO_ERROR_ADDR: return "GIO_ERROR_ADDR";
        case GIO_ERROR_STAT: return "GIO_ERROR_STAT";
        case SYS_SEMAPHORE:  return "SYS_SEMAPHORE";
        case LOCK_MEMORY:    return "LOCK_MEMORY";
        case EISA_LOCK:      return "EISA_LOCK";
        case DMA_GIO_MASK:   return "DMA_GIO_MASK";
        case DMA_GIO_SUB:    return "DMA_GIO_SUB";
        case DMA_CAUSE:      return "DMA_CAUSE";
        case DMA_CTL:        return "DMA_CTL";
        case DMA_TLB_HI_0:   return "DMA_TLB_HI_0";
        case DMA_TLB_LO_0:   return "DMA_TLB_LO_0";
        case DMA_TLB_HI_1:   return "DMA_TLB_HI_1";
        case DMA_TLB_LO_1:   return "DMA_TLB_LO_1";
        case DMA_TLB_HI_2:   return "DMA_TLB_HI_2";
        case DMA_TLB_LO_2:   return "DMA_TLB_LO_2";
        case DMA_TLB_HI_3:   return "DMA_TLB_HI_3";
        case DMA_TLB_LO_3:   return "DMA_TLB_LO_3";
        case RPSS_CTR:       return "RPSS_CTR";
        case DMA_MEMADR:     return "DMA_MEMADR";
        default:             return "MC register";
    }
}

} // namespace indyemu