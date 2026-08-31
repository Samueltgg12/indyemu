// Test: MC memory sizing (MEMCFG), refresh counter, and watchdog timer.
// See hardware-docs/mc.md sections 5.3, 5.7, 5.8, 5.12.

#include <cassert>
#include <cstdint>
#include <iostream>

#include "system/memory_controller.hpp"

using namespace indyemu;

namespace {

uint32_t readReg(MemoryController& mc, uint32_t offset) {
    return mc.read32(MemoryController::kBase + offset);
}

void writeReg(MemoryController& mc, uint32_t offset, uint32_t value) {
    mc.write32(MemoryController::kBase + offset, value);
}

} // namespace

int main() {
    // --- MEMCFG sizing: 128MB = one bank of four 8Mx36 SIMMs ---
    {
        MemoryController mc;
        mc.configureMemory(128u * 1024 * 1024);
        const uint32_t memcfg0 = readReg(mc, MemoryController::MEMCFG0);
        // Bank 0 (high half): BASE=0, MSIZE=0x1F, VLD=1, BNK=1.
        const uint32_t bank0 = memcfg0 >> 16;
        assert((bank0 & 0xFFu) == 0u);                 // base
        assert(((bank0 >> 8) & 0x1Fu) == 0x1Fu);       // 8Mx36
        assert((bank0 & (1u << 13)) != 0u);            // valid
        assert((bank0 & (1u << 14)) != 0u);            // 2 subbanks
        assert((memcfg0 & 0xFFFFu) == 0u);             // bank 1 empty
        assert(readReg(mc, MemoryController::MEMCFG1) == 0u);
    }

    // --- MEMCFG sizing: 96MB = 64MB bank + 32MB bank ---
    {
        MemoryController mc;
        mc.configureMemory(96u * 1024 * 1024);
        const uint32_t memcfg0 = readReg(mc, MemoryController::MEMCFG0);
        const uint32_t bank0 = memcfg0 >> 16;
        const uint32_t bank1 = memcfg0 & 0xFFFFu;
        assert(((bank0 >> 8) & 0x1Fu) == 0x0Fu);       // 4Mx36 -> 64MB bank
        assert(((bank1 >> 8) & 0x1Fu) == 0x07u);       // 2Mx36 -> 32MB bank
        // Bank 1 base = 64MB >> 22 = 16.
        assert((bank1 & 0xFFu) == 16u);
    }

    // --- Refresh counter counts down and reloads from CTRLD ---
    {
        MemoryController mc;
        const uint32_t preload = readReg(mc, MemoryController::CTRLD) & 0xFFFFu;
        assert(preload == 0x0C35u);
        mc.tick(100);
        assert(readReg(mc, MemoryController::REF_CTR) == preload - 100);
        // Cross the reload boundary: total preload+100 cycles -> one reload,
        // counter ends at preload - 100 again.
        mc.tick(preload);
        assert(readReg(mc, MemoryController::REF_CTR) == preload - 100);
    }

    // --- Watchdog: counts refresh bursts when enabled, cleared by writes ---
    {
        MemoryController mc;
        // Enable the watchdog (CPUCTRL0 bit 8).
        writeReg(mc, MemoryController::CPUCTRL0, 1u << 8);
        const uint32_t preload = readReg(mc, MemoryController::CTRLD) & 0xFFFFu;
        mc.tick(preload * 5);  // 5 refresh bursts
        assert(readReg(mc, MemoryController::DOGC) == 5u);
        // Any register write clears the watchdog counter.
        writeReg(mc, MemoryController::GIO64_ARB, 0u);
        assert(readReg(mc, MemoryController::DOGC) == 0u);
        // Roll over the 20-bit counter -> watchdog expiry.
        mc.tick(static_cast<uint64_t>(preload) * 0x100000u);
        assert(mc.watchdogExpired());
    }

    std::cout << "memory_controller_test passed\n";
    return 0;
}
