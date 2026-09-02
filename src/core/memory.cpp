// src/core/memory.cpp
#include "core/memory.hpp"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace indyemu {

Memory::Memory(std::size_t ram_size)
    : ram_size_(ram_size), ram_(new u8[ram_size]{}),
      prom_(new u8[kPromSize]{}) {
  reset();
}

u32 Memory::translateAddress(u32 address) const {
  // MIPS III/IV address translation
  // kuseg: 0x00000000-0x7FFFFFFF -> TLB mapped (user mode)
  // kseg0: 0x80000000-0x9FFFFFFF -> Direct mapped (kernel mode, cached)
  // kseg1: 0xA0000000-0xBFFFFFFF -> Direct mapped (kernel mode, uncached)
  // kseg2: 0xC0000000-0xDFFFFFFF -> TLB mapped (kernel/supervisor mode)
  // kseg3: 0xE0000000-0xFFFFFFFF -> TLB mapped (kernel mode)

  // The GIO64 IO window is a fixed physical region; never TLB-translate it.
  // Exception: 0x1FC00000-0x1FDFFFFF is the kuseg PROM alias, which must
  // still go through the TLB to reach the PROM at physical 0x3FC00000.
  if (isIoPhysicalAddress(address) &&
      !(address >= 0x1FC00000u && address < 0x1FC00000u + kPromSize)) {
    return address;
  }

  if (address < 0x80000000u) {
    // kuseg or user mode - use TLB translation
    bool found, invalid;
    u32 paddr = tlb_translate(address, found, invalid);

    // TLB miss or invalid - trigger TLB exception
    if (!found) {
      tlb_exception_vaddr_ = address;
      tlb_exception_occurred_ = true;
      tlb_exception_type_ = TLBExceptionType::kRefill;
      tlb_exception_is_store_ = false;
    } else if (invalid) {
      tlb_exception_vaddr_ = address;
      tlb_exception_occurred_ = true;
      tlb_exception_type_ = TLBExceptionType::kInvalid;
      tlb_exception_is_store_ = false;
    }
    return paddr;
  } else if (address < 0xA0000000u) {
    // kseg0 - try TLB translation first, then direct mapped (cached)
    bool found, invalid;
    u32 paddr = tlb_translate(address, found, invalid);
    if (found && !invalid) {
      return paddr;
    }
    // Fallback to direct mapping
    return address & 0x1FFFFFFFu;
  } else if (address < 0xC0000000u) {
    // kseg1 - try TLB translation first, then direct mapped (uncached)
    bool found, invalid;
    u32 paddr = tlb_translate(address, found, invalid);
    if (found && !invalid) {
      return paddr;
    }
    // Fallback to direct mapping
    return address & 0x1FFFFFFFu;
  } else {
    // kseg2/kseg3 - use TLB translation
    bool found, invalid;
    u32 paddr = tlb_translate(address, found, invalid);

    // TLB miss or invalid - trigger TLB exception
    if (!found) {
      tlb_exception_vaddr_ = address;
      tlb_exception_occurred_ = true;
      tlb_exception_type_ = TLBExceptionType::kRefill;
      tlb_exception_is_store_ = false;
    } else if (invalid) {
      tlb_exception_vaddr_ = address;
      tlb_exception_occurred_ = true;
      tlb_exception_type_ = TLBExceptionType::kInvalid;
      tlb_exception_is_store_ = false;
    }
    return paddr;
  }
}

void Memory::reset() {
  if (ram_) {
    std::fill_n(ram_.get(), ram_size_, 0);
  }
  if (prom_) {
    std::fill_n(prom_.get(), kPromSize, 0);
  }
  prom_loaded_ = false;

  // Initialize TLB to known state
  tlb_index_ = 0;
  tlb_random_ = 0;
  tlb_wired_ = 0;
  tlb_pagemask_ = 0;
  tlb_entryhi_ = 0;
  tlb_entrylo0_ = 0;
  tlb_entrylo1_ = 0;
  tlb_exception_vaddr_ = 0;
  tlb_exception_occurred_ = false;
  tlb_exception_type_ = TLBExceptionType::kNone;
  tlb_exception_is_store_ = false;
  for (auto &entry : tlb_entries_) {
    entry.entry_lo0 = 0;
    entry.entry_lo1 = 0;
    entry.entry_hi = 0;
    entry.page_mask = 0;
  }

  // Page mask for 4MB pages
  const u32 pagemask_4mb = 0x3FC00000u; // This gives a 4MB page
  // EntryLo values for valid, global, uncached mapping
  const u32 entrylo_valid =
      (0 << 3) | (0 << 2) | (1 << 1) | (1 << 0); // C=0, D=0, V=1, G=1

  // Helper to set up a TLB entry
  auto setup_tlb_entry = [this, &pagemask_4mb,
                          &entrylo_valid](u32 vaddr, u32 paddr, u32 index) {
    tlb_index_ = index;
    tlb_entryhi_ = (vaddr >> 13) << 13; // VPN2 << 13, ASID=0
    u32 pfn = paddr >> 12;              // Page frame number
    tlb_entrylo0_ = (pfn << 6) | entrylo_valid;
    tlb_entrylo1_ = tlb_entrylo0_; // Duplicate for second page in the 4MB page
    tlb_pagemask_ = pagemask_4mb;
    this->tlb_write(tlb_index_);
  };

  // Map RAM region in kuseg: virtual 0x00000000-0x[ram_size) -> physical
  // 0x00000000-0x[ram_size) Using 4MB pages, we need ram_size / 4MB TLB entries
  const u32 ram_base = 0x00000000u;
  const u32 num_ram_entries = ram_size_ / 0x400000u;
  for (u32 i = 0; i < num_ram_entries; ++i) {
    u32 vaddr = ram_base + i * 0x400000u;
    u32 paddr = vaddr; // Identity mapping for RAM
    setup_tlb_entry(vaddr, paddr, i);
  }

  // Map PROM region in kuseg: virtual 0x1FC00000-0x1FDFFFFF -> physical
  // 0x3FC00000-0x3FDFFFFF Map PROM region in kseg0: virtual
  // 0x9FC00000-0x9FDFFFFF -> physical 0x3FC00000-0x3FDFFFFF Map PROM region in
  // kseg1: virtual 0xBFC00000-0xBFDFFFFF -> physical 0x3FC00000-0x3FDFFFFF
  // Using one 4MB page TLB entry for each (covers 4MB, so enough for 2MB)
  const u32 pbase_prom = kPromBase; // 0x3FC00000
  const u32 vbase_kuseg_prom = 0x1FC00000u;
  const u32 vbase_kseg0_prom = 0x80000000u | vbase_kuseg_prom; // 0x9FC00000
  const u32 vbase_kseg1_prom = 0xA0000000u | vbase_kuseg_prom; // 0xBFC00000
  setup_tlb_entry(vbase_kuseg_prom, pbase_prom,
                  num_ram_entries); // index: RAM entries
  setup_tlb_entry(vbase_kseg0_prom, pbase_prom,
                  num_ram_entries + 1); // index: RAM entries + 1
  setup_tlb_entry(vbase_kseg1_prom, pbase_prom,
                  num_ram_entries + 2); // index: RAM entries + 2

  // Clear the rest of the TLB entries
  for (u32 i = num_ram_entries + 3; i < kTLBEntries; ++i) {
    tlb_index_ = i;
    tlb_entryhi_ = 0;
    tlb_entrylo0_ = 0;
    tlb_entrylo1_ = 0;
    tlb_pagemask_ = 0;
    this->tlb_write(tlb_index_);
  }

  // Clear TLB exception tracking
  tlb_exception_vaddr_ = 0;
  tlb_exception_occurred_ = false;
  tlb_exception_type_ = TLBExceptionType::kNone;
  tlb_exception_is_store_ = false;

  // Debug: print first few TLB entries
  std::cerr << "TLB entries after reset:\n";
  for (u32 i = 0; i < 20; ++i) {
    std::cerr << "  [" << i << "] entry_lo0=0x" << std::hex << std::setw(8)
              << std::setfill('0') << tlb_entries_[i].entry_lo0
              << ", entry_lo1=0x" << std::hex << std::setw(8)
              << tlb_entries_[i].entry_lo1 << ", entry_hi=0x" << std::hex
              << std::setw(8) << tlb_entries_[i].entry_hi << ", page_mask=0x"
              << std::hex << std::setw(8) << tlb_entries_[i].page_mask
              << std::dec << std::endl;
  }
}

Memory::Region Memory::regionForAddress(u32 address) const {
  // Classify well-known fixed regions by their (possibly virtual) address
  // first: kseg1 PROM alias, kseg0 RAM base, and the GIO64 IO window.
  if (address >= 0xBFC00000u && address < 0xBFC00000u + kPromSize) {
    return Region::kProm;
  }
  if (address >= kIoBase && address < (kIoBase + 0x01000000u)) {
    return Region::kIo;
  }
  if (address >= kRamBase && address < (kRamBase + ram_size_)) {
    return Region::kRam;
  }
  const u32 translated = translateAddress(address);
  if (isPromAddress(translated)) {
    return Region::kProm;
  }
  if (isRamAddress(translated)) {
    return Region::kRam;
  }
  if (isIoPhysicalAddress(translated)) {
    return Region::kIo;
  }
  return Region::kUnknown;
}

const char *Memory::regionName(u32 address) const {
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

bool Memory::loadProm(const std::string &path) {
  std::ifstream file(path, std::ios::binary);
  if (!file) {
    return false;
  }

  file.read(reinterpret_cast<char *>(prom_.get()), kPromSize);
  prom_loaded_ = true;
  return file.good() || file.eof();
}

bool Memory::isPromAddress(u32 address) const {
  return address >= kPromBase && address < (kPromBase + kPromSize);
}

bool Memory::isRamAddress(u32 address) const {
  // Physical RAM lives at 0x00000000..ram_size (kseg0/kseg1 direct-mapped
  // addresses translate here via & 0x1FFFFFFF). Also accept the kseg0
  // virtual base form (0x80000000+) for callers that pass untranslated
  // addresses.
  // The low EISA I/O region (VINO) is carved out of the RAM alias space.
  if (address >= kEisaIoBase && address < (kEisaIoBase + kEisaIoSize)) {
    return false;
  }
  if (address < ram_size_) {
    return true;
  }
  return address >= kRamBase && address < (kRamBase + ram_size_);
}

bool Memory::isIoPhysicalAddress(u32 paddr) const {
  // GIO64 window plus the low EISA I/O region (VINO).
  if (paddr >= kEisaIoBase && paddr < (kEisaIoBase + kEisaIoSize)) {
    return true;
  }
  return paddr >= kIoBase && paddr < (kIoBase + 0x01000000u);
}

u8 Memory::read8(u32 address) const {
  const u32 paddr = translateAddress(address);
  if (isPromAddress(paddr)) {
    const u32 offset = paddr - kPromBase;
    return prom_[offset % kPromSize];
  }
  if (isRamAddress(paddr)) {
    const u32 offset = (paddr >= kRamBase) ? (paddr - kRamBase) : paddr;
    return ram_[offset % ram_size_];
  }
  if (isIoPhysicalAddress(paddr)) {
    const u32 aligned = paddr & ~3u;
    const u32 reg = io_bus_.read32(aligned);
    const u32 byte_index = (paddr & 3u);
    // DEBUG: limit IO debug output to first 10 accesses in GIO64 range
    static int debug_count = 0;
    if (debug_count < 10 && paddr >= kIoBase && paddr < kIoBase + 0x01000000u) {
      std::cout << "[mem] IO READ8: address=0x" << std::hex << address
                << ", paddr=0x" << paddr << ", aligned=0x" << aligned
                << ", value=0x" << std::hex << (unsigned)reg << std::dec
                << "\n";
      debug_count++;
    }
    return static_cast<u8>((reg >> (byte_index * 8u)) & 0xFFu);
  }
  return 0;
}

u16 Memory::read16(u32 address) const {
  const u32 paddr = translateAddress(address);
  if (isIoPhysicalAddress(paddr)) {
    const u32 aligned = paddr & ~1u;
    const u32 reg = io_bus_.read32(aligned);
    if ((paddr & 1u) == 0u) {
      return static_cast<u16>(reg & 0xFFFFu);
    }
    return static_cast<u16>((reg >> 8u) & 0xFFFFu);
  }
  const u32 value = (static_cast<u32>(read8(address)) |
                     (static_cast<u32>(read8(address + 1)) << 8));
  return static_cast<u16>(value);
}

u32 Memory::read32(u32 address) const {
  const u32 paddr = translateAddress(address);
  if (isIoPhysicalAddress(paddr)) {
    // Debug: print every IO read32 in GIO64 range
    if (paddr >= kIoBase && paddr < kIoBase + 0x01000000u) {
      std::cout << "[mem] IO READ32: address=0x" << std::hex << address
                << ", paddr=0x" << paddr << std::dec << "\n";
    }
    return io_bus_.read32(paddr);
  }
  const u32 value = (static_cast<u32>(read8(address)) << 24) |
                    (static_cast<u32>(read8(address + 1)) << 16) |
                    (static_cast<u32>(read8(address + 2)) << 8) |
                    (static_cast<u32>(read8(address + 3)));
  return value;
}

u64 Memory::read64(u32 address) const {
  const u32 paddr = translateAddress(address);
  if (isIoPhysicalAddress(paddr)) {
    // IO devices expose 32-bit registers; a 64-bit read is two aligned
    // 32-bit reads (big-endian: high word first).
    return (static_cast<u64>(io_bus_.read32(paddr)) << 32) |
           static_cast<u64>(io_bus_.read32(paddr + 4));
  }
  const u64 value = (static_cast<u64>(read8(address)) << 56) |
                    (static_cast<u64>(read8(address + 1)) << 48) |
                    (static_cast<u64>(read8(address + 2)) << 40) |
                    (static_cast<u64>(read8(address + 3)) << 32) |
                    (static_cast<u64>(read8(address + 4)) << 24) |
                    (static_cast<u64>(read8(address + 5)) << 16) |
                    (static_cast<u64>(read8(address + 6)) << 8) |
                    static_cast<u64>(read8(address + 7));
  return value;
}
return;
}
if (isIoPhysicalAddress(paddr)) {
  const u32 aligned = paddr & ~3u;
  const u32 shift = (paddr & 3u) * 8u;
  const u32 mask = 0xFFu << shift;
  const u32 current = io_bus_.read32(aligned);
  io_bus_.write32(aligned,
                  (current & ~mask) | (static_cast<u32>(value) << shift));
}
}

void Memory::write16(u32 address, u16 value) {
  const u32 paddr = translateAddress(address);
  if (isIoPhysicalAddress(paddr)) {
    const u32 aligned = paddr & ~1u;
    if ((paddr & 1u) == 0u) {
      io_bus_.write32(aligned, (io_bus_.read32(aligned) & 0xFFFF0000u) | value);
      return;
    }
    io_bus_.write32(aligned, (io_bus_.read32(aligned) & 0x0000FFFFu) |
                                 (static_cast<u32>(value) << 8u));
    return;
  }
  write8(address, static_cast<u8>(value & 0xFFu));
  write8(address + 1, static_cast<u8>((value >> 8) & 0xFFu));
}

void Memory::write32(u32 address, u32 value) {
  const u32 paddr = translateAddress(address);
  if (isIoPhysicalAddress(paddr)) {
    io_bus_.write32(paddr, value);
    return;
  }
  write8(address, static_cast<u8>((value >> 24) & 0xFFu));
  write8(address + 1, static_cast<u8>((value >> 16) & 0xFFu));
  write8(address + 2, static_cast<u8>((value >> 8) & 0xFFu));
  write8(address + 3, static_cast<u8>(value & 0xFFu));
}

void Memory::write64(u32 address, u64 value) {
  const u32 paddr = translateAddress(address);
  if (isIoPhysicalAddress(paddr)) {
    // IO devices expose 32-bit registers; a 64-bit write is two aligned
    // 32-bit writes (big-endian: high word first).
    io_bus_.write32(paddr, static_cast<u32>(value >> 32));
    io_bus_.write32(paddr + 4, static_cast<u32>(value & 0xFFFFFFFFu));
    return;
  }
  write8(address, static_cast<u8>((value >> 56) & 0xFFu));
  write8(address + 1, static_cast<u8>((value >> 48) & 0xFFu));
  write8(address + 2, static_cast<u8>((value >> 40) & 0xFFu));
  write8(address + 3, static_cast<u8>((value >> 32) & 0xFFu));
  write8(address + 4, static_cast<u8>((value >> 24) & 0xFFu));
  write8(address + 5, static_cast<u8>((value >> 16) & 0xFFu));
  write8(address + 6, static_cast<u8>((value >> 8) & 0xFFu));
  write8(address + 7, static_cast<u8>(value & 0xFFu));
}
for (std::size_t i = 0; i < length; ++i) {
  if ((i % 16) == 0) {
    std::cout << "\n0x" << std::setw(8) << std::hex
              << (start + static_cast<u32>(i)) << ": ";
  }
  std::cout << std::setw(2) << std::hex
            << static_cast<int>(read8(start + static_cast<u32>(i))) << ' ';
}
std::cout << std::dec << "\n";
}

// TLB operations
void Memory::tlb_write(u32 index) {
  if (index >= kTLBEntries) {
    return;
  }

  tlb_entries_[index].entry_lo0 = tlb_entrylo0_;
  tlb_entries_[index].entry_lo1 = tlb_entrylo1_;
  tlb_entries_[index].entry_hi = tlb_entryhi_;
  tlb_entries_[index].page_mask = tlb_pagemask_;
}

void Memory::tlb_read(u32 index) {
  if (index >= kTLBEntries) {
    return;
  }

  tlb_entrylo0_ = tlb_entries_[index].entry_lo0;
  tlb_entrylo1_ = tlb_entries_[index].entry_lo1;
  tlb_entryhi_ = tlb_entries_[index].entry_hi;
  tlb_pagemask_ = tlb_entries_[index].page_mask;
}

void Memory::tlb_probe(u32 vaddr) {
  // Extract VPN2 from virtual address (bits 31-13)
  u32 vpn2 = (vaddr >> 13) & 0x3FFFFF;
  // Current ASID from EntryHi (bits 7-0)
  u32 vaddr_asid = tlb_entryhi_ & 0xFFu;

  bool found = false;
  for (u32 i = 0; i < kTLBEntries; ++i) {
    const TLBEntry &entry = tlb_entries_[i];

    // Extract VPN2 from the TLB entry (bits 31-13 of entry_hi)
    u32 entry_vpn2 = (entry.entry_hi >> 13) & 0x3FFFFF;
    // Entry ASID (bits 7-0 of entry_hi)
    u32 entry_asid = entry.entry_hi & 0xFFu;

    // Check if the Global bit is set in either entry_lo0 or entry_lo1
    bool global_bit_set =
        ((entry.entry_lo0 & 0x1u) || (entry.entry_lo1 & 0x1u));
    bool asid_match = global_bit_set || (entry_asid == vaddr_asid);

    if (entry_vpn2 == vpn2 && asid_match) {
      tlb_index_ = i;
      found = true;
      break;
    }
  }

  if (!found) {
    tlb_index_ = 0x80000000; // Set high bit to indicate not found
  }
}

u32 Memory::tlb_translate(u32 vaddr, bool &found, bool &invalid) const {
  // Extract VPN2 from virtual address
  // The actual comparison needs to mask based on the page mask of each entry
  bool global_bit_set = false;
  u32 vaddr_asid = tlb_entryhi_ & 0xFFu; // Current ASID from EntryHi

  for (u32 i = 0; i < kTLBEntries; ++i) {
    const TLBEntry &entry = tlb_entries_[i];

    // Calculate the mask based on the page mask in the entry
    // PageMask value: 0x00000000 = 1KB page, 0x3FFE0000 = 4KB page, etc.
    // We need to invert it to get the comparison mask
    u32 mask = ~(
        entry.page_mask &
        0xFFFFE000u); // Mask out the bits that don't matter for VPN comparison
    if ((mask & 0x80000000u) == 0) {
      mask |= 0x80000000u; // Ensure we don't mask out the sign bit
    }

    // Extract VPN2 from the virtual address, masked by the entry's page mask
    u32 vpn2 = (vaddr >> 13) & mask;

    // Extract VPN2 from the TLB entry, masked by the entry's page mask
    u32 entry_vpn2 = (entry.entry_hi >> 13) & mask;

    // Check ASID (Address Space ID) - lower 8 bits of entry_hi
    u32 entry_asid = entry.entry_hi & 0xFFu;

    // Check if the Global bit is set in either entry_lo0 or entry_lo1
    bool global_bit_set_in_entry =
        ((entry.entry_lo0 & 0x1u) || (entry.entry_lo1 & 0x1u));

    bool asid_match = global_bit_set_in_entry || (entry_asid == vaddr_asid);

    if (entry_vpn2 == vpn2 && asid_match) {
      found = true;

      // Determine which page (even or odd) based on the mask
      // We need to figure out which page table entry to use based on the
      // address and the page mask

      // Calculate the page size from the page mask
      // PageMask encodes the page size as: (~(PageMask >> 13) & 0x3FFF) + 1) *
      // 2KB
      u32 page_mask_val = entry.page_mask;
      u32 page_size = (((~page_mask_val) >> 13) & 0x3FFF) + 1;
      page_size *= 2048; // Convert to bytes

      // Determine offset within the page
      u32 offset_in_page = vaddr & (page_size - 1);

      // Determine if we're on the even or odd page (entry_lo0 vs entry_lo1)
      // This depends on how the TLB splits the page - typically for odd/even
      // pages within a larger page frame
      bool use_lo1 = (offset_in_page >= (page_size / 2));

      // Get the physical frame number
      u32 pfn = use_lo1 ? (entry.entry_lo1 >> 6) : (entry.entry_lo0 >> 6);

      // Construct physical address
      u32 paddr = (pfn << 12) | (vaddr & (page_size - 1));

      // Check if valid (bit 1 of entry_lo)
      invalid = !(use_lo1 ? (entry.entry_lo1 & 0x2)
                          : (entry.entry_lo0 & 0x2)); // Valid bit

      // If we found a valid entry, return the physical address immediately
      if (!invalid) {
        return paddr;
      }
      // If we found an invalid entry, we break so that the exception handling
      // below will set the TLB invalid exception.
      break;
    }
  }

  found = false;
  invalid = true;
  return 0; // Should not be used when !found
}

// TLB register access
u32 Memory::read_tlb_register(u32 reg) const {
  switch (reg) {
  case 0: // Index
    return tlb_index_;
  case 1: // Random
    return tlb_random_;
  case 2: // EntryLo0
    return tlb_entrylo0_;
  case 3: // EntryLo1
    return tlb_entrylo1_;
  case 4: // Context
    // Context is mostly read-only, but we'll allow writing for initialization
    return (tlb_entryhi_ & 0x07FFFFFF) << 7; // Simplified
  case 5:                                    // PageMask
    return tlb_pagemask_;
  case 6: // Wired
    return tlb_wired_;
  case 7: // Reserved
    return 0;
  case 8: // BadVAddr
    // Would need to store last bad address
    return 0;
  case 9: // Count
    // Would need timer implementation
    return 0;
  case 10: // EntryHi
    return tlb_entryhi_;
  case 11: // Compare
    // Would need timer implementation
    return 0;
  case 12: // Status
    // This is actually a CP0 register, not TLB
    return 0;
  case 13: // Cause
    // This is actually a CP0 register, not TLB
    return 0;
  case 14: // EPC
    // This is actually a CP0 register, not TLB
    return 0;
  case 15: // PRId
    // This is actually a CP0 register, not TLB
    return 0;
  case 16: // Config
    // This is actually a CP0 register, not TLB
    return 0;
  case 17: // LLAddr
    // This is actually a CP0 register, not TLB
    return 0;
  case 18: // WatchLo
    // This is actually a CP0 register, not TLB
    return 0;
  case 19: // WatchHi
    // This is actually a CP0 register, not TLB
    return 0;
  case 20: // XContext
    // This is actually a CP0 register, not TLB
    return 0;
  case 21: // Reserved
    return 0;
  case 22: // Reserved
    return 0;
  case 23: // Debug
    // This is actually a CP0 register, not TLB
    return 0;
  case 24: // DEPC
    // This is actually a CP0 register, not TLB
    return 0;
  case 25: // Reserved
    return 0;
  case 26: // Reserved
    return 0;
  case 27: // Reserved
    return 0;
  case 28: // PErr
    // This is actually a CP0 register, not TLB
    return 0;
  case 29: // CacheErr
    // This is actually a CP0 register, not TLB
    return 0;
  case 30: // TagLo
    // This is actually a CP0 register, not TLB
    return 0;
  case 31: // TagHi
    // This is actually a CP0 register, not TLB
    return 0;
  default:
    return 0;
  }
}

void Memory::write_tlb_register(u32 reg, u32 value) {
  switch (reg) {
  case 0:                      // Index
    tlb_index_ = value & 0x3F; // Only 6 bits used for 64 entries
    break;
  case 1: // Random
    // Random is read-only, but we'll allow writing for initialization
    tlb_random_ = value & 0x3F;
    break;
  case 2: // EntryLo0
    tlb_entrylo0_ = value;
    break;
  case 3: // EntryLo1
    tlb_entrylo1_ = value;
    break;
  case 4: // Context
    // Context is mostly read-only, but we'll allow writing for initialization
    break;
  case 5: // PageMask
    tlb_pagemask_ = value;
    break;
  case 6:                      // Wired
    tlb_wired_ = value & 0x3F; // Only 6 bits used
    break;
  case 7: // Reserved
    break;
  case 8: // BadVAddr
    // BadVAddr is written by hardware on address error
    break;
  case 9: // Count
    // Count is self-incrementing
    break;
  case 10: // EntryHi
    tlb_entryhi_ = value;
    break;
  case 11: // Compare
    // Would need timer implementation
    break;
  case 12: // Status
    // This is actually a CP0 register, not TLB
    break;
  case 13: // Cause
    // This is actually a CP0 register, not TLB
    break;
  case 14: // EPC
    // This is actually a CP0 register, not TLB
    break;
  case 15: // PRId
    // This is actually a CP0 register, not TLB
    break;
  case 16: // Config
    // This is actually a CP0 register, not TLB
    break;
  case 17: // LLAddr
    // This is actually a CP0 register, not TLB
    break;
  case 18: // WatchLo
    // This is actually a CP0 register, not TLB
    break;
  case 19: // WatchHi
    // This is actually a CP0 register, not TLB
    break;
  case 20: // XContext
    // This is actually a CP0 register, not TLB
    break;
  case 21: // Reserved
    break;
  case 22: // Reserved
    break;
  case 23: // Debug
    // This is actually a CP0 register, not TLB
    break;
  case 24: // DEPC
    // This is actually a CP0 register, not TLB
    break;
  case 25: // Reserved
    break;
  case 26: // Reserved
    break;
  case 27: // Reserved
    break;
  case 28: // PErr
    // This is actually a CP0 register, not TLB
    break;
  case 29: // CacheErr
    // This is actually a CP0 register, not TLB
    break;
  case 30: // TagLo
    // This is actually a CP0 register, not TLB
    break;
  case 31: // TagHi
    // This is actually a CP0 register, not TLB
    break;
  default:
    break;
  }
}

// TLB exception handling
bool Memory::checkAndClearTLBException(u32 &vaddr, bool &is_store,
                                       TLBExceptionType &type) {
  if (tlb_exception_occurred_) {
    vaddr = tlb_exception_vaddr_;
    is_store = tlb_exception_is_store_;
    type = tlb_exception_type_;
    tlb_exception_occurred_ = false;
    return true;
  }
  return false;
}

void Memory::addIoDevice(IODevice *device, uint32_t base_addr, uint32_t size) {
  io_bus_.addDevice(device, base_addr, size);
}

// Static member definitions
u32 Memory::tlb_exception_vaddr_ = 0;
bool Memory::tlb_exception_occurred_ = false;
Memory::TLBExceptionType Memory::tlb_exception_type_ =
    Memory::TLBExceptionType::kNone;
bool Memory::tlb_exception_is_store_ = false;

} // namespace indyemu