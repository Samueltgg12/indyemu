# IndyEmu implementation checklist

This checklist follows the proven plan for the SGI Indy emulator:

- source-of-truth hardware references from the MAME `indy_4610` driver
- SGI Indy public documentation
- IRIS emulator architecture and lessons
- interpreter-first execution model
- JIT added only after the core machine model is stable

## Phase 0: project grounding

- [x] Confirm the SGI Indy target platform and machine profile
- [x] Confirm CPU family target: MIPS R4400-class
- [x] Confirm target memory profile: 128MB RAM
- [x] Confirm PROM boot path and reset vector assumptions
- [x] Confirm target graphics path: 24-bit XL framebuffer
- [x] Confirm fixed Ethernet MAC and hardware config assumptions
- [x] Document the emulator as a staged project

## Phase 1: CPU and memory correctness

- [ ] Map the Indy memory model precisely
- [ ] Implement full PROM / RAM / I/O address translation semantics
- [ ] Expand the CPU interpreter beyond the current minimal instruction set
- [ ] Validate instruction behavior against PROM execution flow
- [ ] Add basic register and trap/interrupt stubs
- [ ] Build deterministic tests for memory behavior and CPU decoding

## Phase 2: framebuffer and XL graphics

- [ ] Document the XL framebuffer memory window and mode behavior
- [ ] Add a framebuffer device abstraction
- [ ] Implement a software display surface for pixel output
- [ ] Map graphics registers and startup configuration
- [ ] Render a classic SGI / IndigoMagic startup screen
- [ ] Validate the initial display and boot visual path

## Phase 3: IO and device shell

- [ ] Implement the timer and clock model
- [ ] Implement interrupt controller behavior
- [ ] Implement serial / console device stubs
- [ ] Implement system controller and NVRAM hooks
- [ ] Add device register windows aligned to Indy hardware
- [ ] Maintain the memory-mapped IO model as the source of truth

## Phase 4: storage and disk path

- [ ] Add SCSI / disk controller stubs
- [ ] Add bootable CD / ISO support
- [ ] Add filesystem layer and EFS hooks
- [ ] Add disk image loading and raw media access
- [ ] Validate boot ordering from PROM to disk

## Phase 5: networking

- [ ] Add Ethernet device model
- [ ] Implement MAC configuration and NIC register windows
- [ ] Add network boot and data path hooks
- [ ] Support host networking and local emulated transport
- [ ] Validate early network initialization path

## Phase 6: system configuration and boot progression

- [ ] Add a machine configuration layer for hardware variants
- [ ] Add CPU / chipset / memory / graphics / storage configuration
- [ ] Document the boot flow from PROM to kernel startup
- [ ] Add configuration UI and machine profile management
- [ ] Validate the real Indy setup path against the desired hardware profile

## Phase 7: JIT acceleration

- [ ] Define the JIT translation model for hot MIPS blocks
- [ ] Add block cache keyed by MIPS PC
- [ ] Translate core opcodes into x86_64 code
- [ ] Keep memory/MMIO accesses through explicit helper paths
- [ ] Implement interpreter fallback for unsupported or special paths
- [ ] Benchmark the interpreter and JIT performance against the target
- [ ] Tune the JIT for stable, high-speed execution

## Phase 8: IRIX integration

- [ ] Boot the PROM path successfully through the early firmware
- [ ] Reach the system startup and console path
- [ ] Add early IRIX-compatible display and desktop behavior
- [ ] Expand toward the Indy/IRIX 5.x software experience
- [ ] Keep visual fidelity aligned with the IndigoMagic look

## Done criteria

The project is considered ready to move beyond the bootstrap stage when:

- the PROM boots cleanly and reaches real firmware code
- the CPU can execute the real Indy instruction stream
- the framebuffer is visible and the display path works
- the device map and IO windows are implemented
- storage and network support can be initialized
- the interpreter is stable enough to run the JIT on top
