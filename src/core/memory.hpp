// src/core/memory.hpp
#pragma once

#include "core/common.hpp"
#include "system/gio64_bus.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <memory>
#include <vector>

namespace indyemu {

class Memory {
public:
  enum class Region {
    kUnknown,
    kRam,
    kProm,
    kIo,
  };

  static constexpr std::size_t kDefaultRamSize = 64 * 1024 * 1024;
  static constexpr std::size_t kPromSize = 2 * 1024 * 1024;
  static constexpr std::size_t kTLBEntries = 64; // Typical for MIPS R4000

  // TLB entry structure
  struct TLBEntry {
    u32 entry_lo0; // PFN0, C0, D0, V0, G
    u32 entry_lo1; // PFN1, C1, D1, V1, G
    u32 entry_hi;  // VPN2, ASID
    u32 page_mask; // PageMask
  };

  explicit Memory(std::size_t ram_size = kDefaultRamSize);
  ~Memory() = default;

  bool loadProm(const std::string &path);
  void reset();

  Region regionForAddress(u32 address) const;
  const char *regionName(u32 address) const;
  u8 read8(u32 address) const;
  u16 read16(u32 address) const;
  u32 read32(u32 address) const;

  void write8(u32 address, u8 value);
  void write16(u32 address, u16 value);
  void write32(u32 address, u32 value);

  void dumpRange(u32 start, std::size_t length) const;

  // TLB operations
  void tlb_write(u32 index);
  void tlb_read(u32 index);
  void tlb_probe(u32 vaddr);
  u32 tlb_translate(u32 vaddr, bool &found, bool &invalid) const;

  // TLB register access
  u32 read_tlb_register(u32 reg) const;
  void write_tlb_register(u32 reg, u32 value);

  // TLB exception tracking
public:
  enum class TLBExceptionType { kNone, kRefill, kInvalid, kModified };

  void addIoDevice(IODevice *device, uint32_t base_addr, uint32_t size);

private:
  std::size_t ram_size_;
  std::unique_ptr<u8[]> ram_;
  std::unique_ptr<u8[]> prom_;
  GIO64Bus io_bus_;
  bool prom_loaded_ = false;

  // TLB registers
  std::array<TLBEntry, kTLBEntries> tlb_entries_;
  u32 tlb_index_ = 0;
  u32 tlb_random_ = 0;
  u32 tlb_wired_ = 0;
  u32 tlb_pagemask_ = 0;
  u32 tlb_entryhi_ = 0;
  u32 tlb_entrylo0_ = 0;
  u32 tlb_entrylo1_ = 0;

  // TLB exception handling
public:
  bool checkAndClearTLBException(u32 &vaddr, bool &is_store,
                                 TLBExceptionType &type);

  // TLB exception tracking
private:
  static u32 tlb_exception_vaddr_;
  static bool tlb_exception_occurred_;
  static TLBExceptionType tlb_exception_type_;
  static bool tlb_exception_is_store_;

  u32 translateAddress(u32 address) const;
  bool isPromAddress(u32 address) const;
  bool isRamAddress(u32 address) const;
  bool isIoPhysicalAddress(u32 paddr) const;
};

} // namespace indyemu
