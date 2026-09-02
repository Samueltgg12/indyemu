#include "core/cpu/mips_cpu.hpp"
#include "core/memory.hpp"

#include <array>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

namespace {

// Append a 32-bit instruction as a big-endian word (the machine is big-endian).
void appendWord(std::vector<unsigned char> &out, std::uint32_t word) {
  out.push_back(static_cast<unsigned char>((word >> 24) & 0xFF));
  out.push_back(static_cast<unsigned char>((word >> 16) & 0xFF));
  out.push_back(static_cast<unsigned char>((word >> 8) & 0xFF));
  out.push_back(static_cast<unsigned char>(word & 0xFF));
}

} // namespace

int main() {
  const std::string prom_path = "./cpu_64bit_test_prom.bin";

  std::vector<unsigned char> prom;
  // lui $1, 0x8000            -> $1 = 0xFFFFFFFF80000000 (sign-extended)
  appendWord(prom, 0x3C018000u);
  // ori $2, $zero, 4          -> $2 = 4
  appendWord(prom, 0x34020004u);
  // dadd $3, $1, $2           -> 0xFFFFFFFF80000004
  appendWord(prom, 0x0022182Cu);
  // dsub $4, $1, $2           -> 0xFFFFFFFF7FFFFFFC
  appendWord(prom, 0x0022202Eu);
  // dsll $5, $1, 4            -> 0xFFFFFFF800000000
  appendWord(prom, 0x00012938u);
  // dsrl $6, $1, 4            -> 0x0FFFFFFFF8000000
  appendWord(prom, 0x0001313Au);
  // dsra $7, $1, 4            -> 0xFFFFFFFFF8000000
  appendWord(prom, 0x0001393Bu);
  // dsllv $8, $1, $2          -> 0xFFFFFFF800000000
  appendWord(prom, 0x00414014u);
  // dsrlv $9, $1, $2          -> 0x0FFFFFFFF8000000
  appendWord(prom, 0x00414816u);
  // dsrav $10, $1, $2         -> 0xFFFFFFFFF8000000
  appendWord(prom, 0x00415017u);
  // dsll32 $11, $1, 4         -> 0x0000000000000000 (0xFFFFFFFF80000000 << 36)
  appendWord(prom, 0x0001593Cu);
  // dsrl32 $12, $1, 4         -> 0x0FFFFFFF
  appendWord(prom, 0x0001613Eu);
  // dsra32 $13, $1, 4         -> 0xFFFFFFFFFFFFFFFF
  appendWord(prom, 0x0001693Fu);

  {
    std::ofstream out(prom_path, std::ios::binary);
    out.write(reinterpret_cast<const char *>(prom.data()),
              static_cast<std::streamsize>(prom.size()));
  }

  indyemu::Memory mem;
  if (!mem.loadProm(prom_path)) {
    return 2;
  }

  indyemu::MipsCpu cpu(mem);
  for (std::size_t i = 0; i < prom.size() / 4; ++i) {
    cpu.step();
  }

  const auto &gpr = cpu.registers().gpr;
  if (gpr[3] != 0xFFFFFFFF80000004ull)
    return 1;
  if (gpr[4] != 0xFFFFFFFF7FFFFFFCull)
    return 2;
  if (gpr[5] != 0xFFFFFFF800000000ull)
    return 3;
  if (gpr[6] != 0x0FFFFFFFF8000000ull)
    return 4;
  if (gpr[7] != 0xFFFFFFFFF8000000ull)
    return 5;
  if (gpr[8] != 0xFFFFFFF800000000ull)
    return 6;
  if (gpr[9] != 0x0FFFFFFFF8000000ull)
    return 7;
  if (gpr[10] != 0xFFFFFFFFF8000000ull)
    return 8;
  if (gpr[11] != 0x0000000000000000ull)
    return 9;
  if (gpr[12] != 0x0FFFFFFFull)
    return 10;
  if (gpr[13] != 0xFFFFFFFFFFFFFFFFull)
    return 11;

  return 0;
}