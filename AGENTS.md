# AGENTS.md — IndyEmu AI Agent Guide

This file is the canonical reference for AI coding agents (Copilot, Claude, Cursor, etc.) working on IndyEmu. It exists to make you immediately productive and to keep every change aligned with the project's real architecture and goals. Read it fully before editing code.

---

## 1. What this project is

**IndyEmu** is a C++17 emulator for the **SGI Indy** workstation (MIPS R4400-class CPU). The goal is a faithful, staged emulation of the real hardware — not a synthetic approximation.

**The staged roadmap (in order):**

1. **Boot into the PROM** (current focus) — CPU, memory, IO, graphics, sound
2. **Boot into IRIX** — expand hardware until the OS loads
3. **JIT + optimizations** — MIPS→x86_64 block translation on top of a stable interpreter
4. **GUI enhancement** — retro IndigoMagic-style Qt shell
5. **Cross-platform + CI** — Linux, Windows, macOS via GitHub Actions

**Source-of-truth references** (consult these before inventing behavior):
- MAME `indy_4610` driver — authoritative machine layout
- `hardware-docs/` — real chip datasheets and register maps (ioc.md, hpc3.md, hal2.md, interrupt_map.md, mc.md, rex3.md, etc.)
- `iris-milestones/` — milestone notes from the IRIS emulator project
- `docs/` — project roadmap, checklist, hardware analysis

> **Rule:** When hardware behavior is unclear, check `hardware-docs/` and the MAME reference first. Do not invent synthetic behavior.

---

## 2. Build, test, run

```bash
# Configure + build (from repo root)
cmake -S . -B build
cmake --build build

# Run the CLI emulator
./build/indyemu                  # boots with default profile
./build/indyemu --trace          # with CPU trace
./build/indyemu --steps 1000     # run N steps
./build/indyemu path/to/prom.bin # explicit PROM image

# Run the Qt GUI
./build/indyemu_gui

# Run tests (CTest)
cd build && ctest
# Or run individual test binaries directly:
./build/cpu_r4400_test
./build/prom_reset_vector_test
```

**Build requirements:** CMake ≥ 3.16, a C++17 compiler, Qt5 Widgets (GUI only). `toml++` is fetched automatically via CMake `FetchContent` — no manual dependency install needed.

---

## 3. Repository layout

```
src/
  main.cpp            # CLI entry point (arg parsing, config load, boot)
  core/               # CPU, memory, machine model
    cpu/mips_cpu.*    # MIPS R4400 interpreter + CP0/TLB + interrupt handling
    memory.*          # Physical memory, TLB, address translation, IO dispatch
    indy_system.*     # Top-level machine: wires CPU + devices together
    indy_hardware.*   # MachineConfig struct (the hardware profile)
    common.hpp        # Type aliases (u8..u64) + memory base constants
  io/                 # IO devices
    ioc2.*            # IOC2 interrupt controller (INT3) @ 0x1FBD9800
    hal2_audio.*      # HAL2 audio ASIC (indirect registers) @ 0x1FBD8000
    serial.*, system_controller.*, register_map.*
  system/             # Bus + system devices
    gio64_bus.*       # GIO64 bus: IODevice interface + device dispatch
    rex3.*            # Rex3/Newport graphics engine
    rtc.*, timer.*, interrupt_controller.*
  gfx/                # XL graphics
  gui/                # Qt5 GUI (main.cpp, main_window.cpp)
  config/indy_config.hpp  # TOML config: generation + parsing (header-only)
  devices/  jit/  sound/   # (currently empty — future expansion points)
tests/                # One executable per test, registered in CMakeLists.txt
hardware-docs/        # Real chip datasheets + register maps (READ THESE)
iris-milestones/      # IRIS emulator milestone notes
docs/                 # Project roadmap, checklist, hardware analysis
.github/workflows/    # CI (multi-platform CMake, etc.)
```

---

## 4. Coding conventions (follow these exactly)

**Language:** C++17. No exceptions across device boundaries; no RTTI dependence.

**Namespace:** Everything lives in `namespace indyemu`.

**Types:** Always use the fixed-width aliases from `src/core/common.hpp`:
```cpp
u8, u16, u32, u64   // unsigned
i8, i16, i32, i64   // signed
```
Never use raw `int`/`uint32_t` for hardware values — use the aliases.

**Memory base constants** (already defined in `common.hpp` — reuse, don't redefine):
```cpp
kPromBase = 0x3FC00000u   // physical PROM base
kRamBase  = 0x80000000u   // physical RAM base
kIoBase   = 0x1F000000u   // GIO64 IO base
```

**Key architectural facts:**
- CPU reset vector: `0xBFC00000` (kseg1 PROM alias)
- MIPS is **big-endian** in this machine model
- The CPU is an interpreter; JIT comes later and must not change the hardware model
- `Memory` owns RAM + PROM + a `GIO64Bus` for IO dispatch
- Devices attach to the bus via `Memory::addIoDevice(device, base, size)`

**IODevice contract** (`src/system/gio64_bus.hpp`): any bus-attached device implements:
```cpp
bool contains(uint32_t address) const;          // is this address mine?
uint32_t read32(uint32_t address) const;        // full address, compute offset internally
void write32(uint32_t address, uint32_t value); // full address, compute offset internally
```
The bus passes the **full physical address**; the device subtracts its own base. See `Rex3` and `Hal2Audio` for the pattern.

**Interrupt model:** Devices that raise CPU interrupts implement the `InterruptController` interface (`pendingInterruptLines()` returning a bitmask of IP lines). `Ioc2Controller` is the system interrupt controller and is wired to the CPU via `cpu_.setInterruptController(&ioc2_)` in `IndySystem`.

**Config:** Machine profiles are TOML, parsed by `loadConfigFromToml()` in `src/config/indy_config.hpp`. RAM size is configurable (`ram_bytes`) and flows into the `Memory` constructor.

---

## 5. How to make changes safely

1. **Read before editing.** Understand the existing device/CPU/memory pattern before adding to it. Match the surrounding style.
2. **Ground hardware behavior in the docs.** Register addresses, bit layouts, and reset sequences must match `hardware-docs/` or MAME. Cite the doc in a comment when implementing a non-obvious behavior.
3. **Keep the interpreter correct first.** JIT/optimization work must preserve exact hardware semantics.
4. **Add a test when you add behavior.** Tests live in `tests/` and are registered as separate executables in `CMakeLists.txt` (follow the existing pattern: source list + `target_include_directories(... PRIVATE src)` + `add_test`).
5. **Build and run tests before finishing:**
   ```bash
   cmake --build build && (cd build && ctest)
   ```
6. **Don't break the build on any platform.** CI builds on Linux (gcc/clang) and Windows (MSVC). Avoid platform-specific APIs unless guarded.

---

## 6. Current implementation status

**Working / in place:**
- MIPS R4400 interpreter with CP0 + full TLB (64 entries) + interrupt/exception handling
- Configurable RAM (TOML-driven, default 128MB) with dynamic TLB setup
- PROM loading + reset vector boot path
- IOC2 interrupt controller (L0/L1/MAP registers, IP2/IP3 routing to CPU)
- HAL2 audio (indirect register mechanism via IAR/IDR0-3)
- Rex3/Newport graphics engine (command FIFO, rasterizer, framebuffer)
- GIO64 bus device framework
- RTC (Dallas DS1687), timer, serial, system controller (partial)
- TOML config generation + parsing
- Qt5 GUI shell

**Partial / needs work:**
- Memory controller (MC) registers
- VINO video, WD33C93B SCSI, 93C56 EEPROM, SEEQ80C03 Ethernet
- HAL2 DMA engine + audio output
- IOC2 → full device interrupt wiring (devices asserting lines)

**Not started:** JIT translator (`src/jit/`), sound output (`src/sound/`), extra devices (`src/devices/`)

---

## 7. Where to look things up

| Question | Where |
|----------|-------|
| Interrupt routing / priorities | `hardware-docs/interrupt_map.md`, `hardware-docs/ioc.md` |
| HPC3 / PBUS / DMA | `hardware-docs/hpc3.md` |
| HAL2 audio registers | `hardware-docs/hal2.md` |
| Memory controller | `hardware-docs/mc.md` |
| Rex3 graphics | `hardware-docs/rex3.md` |
| Project plan / phases | `docs/IMPLEMENTATION_ROADMAP.md`, `docs/IMPLEMENTATION_CHECKLIST.md` |
| Hardware boot flow | `docs/INDY_HARDWARE_ANALYSIS.md` |

---

## 8. Definition of done for a change

- Compiles cleanly on the existing CMake targets (no new warnings)
- Relevant tests pass (`ctest`)
- Hardware behavior matches the reference docs / MAME
- New behavior is covered by a test where practical
- Code follows the conventions in §4 (types, namespace, device pattern)

<!-- AICB:BEGIN {"version":1,"target":"AGENTS.md","generatedAt":"2026-09-02T02:28:13.334Z","hash":"sha256:ba93dce1ced36ce49152bbd4a686beb2e156fdc600e56096adac9fe90e79a2fc"} -->
# AI Context Bridge — Handoff

Workspace: `/home/samuel/untitledctest/indyemu`

## Spec / context files (read these first)
- `CLAUDE.md` _(spec)_ — Claude Code instructions
- `AGENTS.md` _(spec)_ — Multi-agent instructions
- `README.md` _(spec)_ — Project README
- `.agent/AGENTS.md` _(spec)_ — Multi-agent instructions (.agent)
- `GEMINI.md` _(spec)_ — Gemini instructions
- `AGENT.md` _(spec)_ — Multi-agent instructions
- `.cursorrules` _(spec)_ — Cursor rules
- `.windsurfrules` _(spec)_ — Windsurf rules
- `.github/copilot-instructions.md` _(spec)_ — GitHub Copilot instructions (.github)

## Working files (current focus)
- `src/core/memory.hpp` _(auto:recent-edit)_
- `src/core/memory.cpp` _(auto:recent-edit)_

## How to use this handoff
1. Read every file under "Spec / context files" before acting.
2. Continue the work described in the most recent thought.
3. Honor skill statuses: `ENABLED` use freely, `ASK` require explicit user confirmation each time, `DISABLED` must not be used.
4. When you reach a non-trivial decision, append a thought to `.aicb/state.json` (modelId + text + sourceReference if relevant).
<!-- AICB:END -->
