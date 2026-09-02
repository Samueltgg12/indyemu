# CLAUDE.md — IndyEmu Guide for Claude

This file gives Claude (and Claude-based agents) the context and working agreements needed to contribute effectively to IndyEmu. It complements `AGENTS.md` (the canonical reference for all AI agents) — read both. Where they overlap, this file adds Claude-specific workflow guidance.

---

## Project in one paragraph

IndyEmu is a **C++17 emulator for the SGI Indy workstation** (MIPS R4400-class CPU). The immediate goal is to **boot into the PROM** with working CPU, memory, IO, graphics, and sound; then expand hardware until **IRIX boots**; then add a **MIPS→x86_64 JIT** and polish the **Qt GUI**; finally ensure **cross-platform** builds via GitHub Actions. The design is deliberately staged and grounded in real hardware behavior — the MAME `indy_4610` driver and the datasheets in `hardware-docs/` are the source of truth.

---

## Before you write any code

1. **Read `AGENTS.md`** — it has the full architecture, conventions, build/test commands, and the device/bus contract. Do not skip it.
2. **Check the hardware docs** for the subsystem you're touching:
   - Interrupts → `hardware-docs/interrupt_map.md`, `hardware-docs/ioc.md`
   - Audio → `hardware-docs/hal2.md`
   - HPC3 / PBUS / DMA → `hardware-docs/hpc3.md`
   - Memory controller → `hardware-docs/mc.md`
   - Graphics → `hardware-docs/rex3.md`
3. **Match the existing pattern.** Look at `Rex3` or `Hal2Audio` before adding a new device; look at an existing test before adding one.

---

## Non-negotiable conventions

- **Namespace:** everything in `namespace indyemu`.
- **Types:** use the aliases from `src/core/common.hpp` (`u8/u16/u32/u64`, `i8/i16/i32/i64`) — never raw `int` for hardware values.
- **Memory bases** (already defined, reuse them): `kPromBase=0x3FC00000`, `kRamBase=0x80000000`, `kIoBase=0x1F000000`.
- **Endianness:** the machine is **big-endian**. Byte-lane handling in device `read32`/`write32` must respect this.
- **IODevice contract:** bus devices implement `contains(address)`, `read32(address)`, `write32(address, value)`. The bus passes the **full physical address**; the device subtracts its own base internally.
- **Interrupts:** interrupt sources implement `InterruptController::pendingInterruptLines()`; `Ioc2Controller` is wired to the CPU in `IndySystem`.
- **Config:** machine profiles are TOML via `loadConfigFromToml()`; RAM size is configurable and flows into `Memory`.

---

## How Claude should approach tasks here

**For hardware implementation tasks:**
1. Locate the relevant doc in `hardware-docs/` and extract the exact register map / bit definitions / reset sequence.
2. Find the corresponding file in `src/io/` or `src/system/` (or confirm it needs creating).
3. Implement to match the documented behavior, with a comment citing the doc for non-obvious behavior.
4. Build: `cmake --build build`. Fix all errors before moving on.
5. Add/extend a test in `tests/` and register it in `CMakeLists.txt` following the existing pattern.

**For CPU/interpreter work:**
- Correctness first, always. The JIT (later) must not change observable hardware behavior.
- Validate against the PROM execution flow — that's the primary proof.

**For refactors:**
- Keep the staged roadmap intact. Don't pull JIT work forward before the interpreter + hardware model are stable.

---

## Build / test / verify (do this every time)

```bash
cmake -S . -B build          # configure (first time or after CMakeLists changes)
cmake --build build          # build everything
cd build && ctest            # run the test suite
./build/indyemu --steps 100  # smoke-test the boot path
```

A change is **done** when: it builds cleanly, tests pass, behavior matches the hardware docs/MAME, and conventions above are followed.

---

## Current state snapshot (so you don't re-derive it)

- ✅ CPU interpreter + CP0 + 64-entry TLB + interrupt/exception handling
- ✅ Configurable RAM via TOML (default 128MB), dynamic TLB setup
- ✅ PROM load + reset-vector boot path
- ✅ IOC2 interrupt controller (L0/L1/MAP, IP2/IP3 routing)
- ✅ HAL2 indirect-register mechanism (IAR/IDR0-3)
- ✅ Rex3 graphics, GIO64 bus, RTC, timer, serial, system controller (partial)
- ⚠️ Memory controller (MC), VINO, SCSI, EEPROM, Ethernet — partial/missing
- ⬜ JIT (`src/jit/`), sound output (`src/sound/`), extra devices (`src/devices/`) — empty, future work

---

## Where to get help

- `AGENTS.md` — full architecture + conventions (read this first)
- `docs/IMPLEMENTATION_ROADMAP.md` — the staged plan and rationale
- `docs/IMPLEMENTATION_CHECKLIST.md` — phase-by-phase progress
- `docs/INDY_HARDWARE_ANALYSIS.md` — boot flow + hardware assumptions
- `hardware-docs/` — the actual chip/register documentation

When in doubt about hardware behavior, the docs and the MAME reference win over intuition.

<!-- AICB:BEGIN {"version":1,"target":"CLAUDE.md","generatedAt":"2026-09-02T00:34:33.919Z","hash":"sha256:1d5a551ce408706a2b6c79f04c0acf25f8e4b7f6221f26f83277391f7582d9c8"} -->
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
- `src/core/cpu/mips_cpu.cpp` _(auto:recent-edit)_
- `tests/cpu_64bit_test.cpp` _(auto:recent-edit)_
- `CMakeLists.txt` _(auto:recent-edit)_

## How to use this handoff
1. Read every file under "Spec / context files" before acting.
2. Continue the work described in the most recent thought.
3. Honor skill statuses: `ENABLED` use freely, `ASK` require explicit user confirmation each time, `DISABLED` must not be used.
4. When you reach a non-trivial decision, append a thought to `.aicb/state.json` (modelId + text + sourceReference if relevant).
<!-- AICB:END -->
