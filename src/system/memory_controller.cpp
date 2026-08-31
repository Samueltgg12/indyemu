#include "system/memory_controller.hpp"

#include <iostream>

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
    std::cout << "[mc] Memory controller reset\n";
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
    return regs_[index];
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