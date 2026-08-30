# IndyEmu implementation roadmap

## Source-of-truth direction

The correct path for this emulator is to treat the public SGI Indy hardware model and the MAME `indy_4610` driver as the authoritative reference for:

- CPU behavior
- memory map
- IO windows
- device registration
- boot sequencing
- interrupt and timer architecture
- display and graphics initialization
- disk/network controller behavior

The project should not invent a synthetic machine model when the public, well-understood references already define the actual Indy platform layout.

## Core architecture

### 1. Realistic machine model

The emulator should be structured around a real machine profile:

- MIPS R4400-class CPU core
- Indy memory map with PROM/RAM/IO space
- 128MB RAM profile
- 24-bit XL graphics path
- SGI Indy-style PROM boot path
- fixed Ethernet MAC: 08:00:69:12:34:56
- serial, timer, interrupt, and system control devices
- SCSI / CD / disk support

### 2. C++ host runtime

The host runtime should remain C++17 as the primary engine layer. The design goals are:

- deterministic memory and device simulation
- explicit hardware register layout
- precise memory access semantics
- modular emulated devices
- stable platform for a future JIT translator

### 3. MIPS to x86_64 JIT translator

The project target is a dynamic code generator that translates hot MIPS blocks into x86_64 machine code. The architecture should be modular:

- fetch/cache translated blocks by MIPS PC
- translate basic blocks from the PROM / kernel / IRIX code paths
- keep memory and device access explicit at translation boundaries
- implement helper calls for uncached / memory-mapped I/O paths
- support a fast interpreter fallback for unsupported or rare instructions

This lets the emulator keep the correct hardware model while achieving the "same speed as IRIS" style performance target without discarding the C++ deterministic core.

## Execution model

The runtime pipeline should be:

1. Decode MIPS instructions in the CPU core
2. Cache translated blocks for hot regions
3. Dispatch translated x86_64 blocks when available
4. Fall back to a precise interpreter for unsupported or stateful paths
5. Keep memory and device state synchronized with the host machine

The important design point is that the JIT should optimize execution, not replace the machine model. The real hardware behavior remains the source of truth.

## Stage plan

### Stage 1: framebuffer and XL graphics

- Study the Indy XL framebuffer memory window and graphics controller behavior
- Implement the framebuffer as a real device abstraction
- Add a software display surface for the startup screen and future console output
- Map XL graphics register windows and startup configuration paths
- Validate that the emulator can render the classic SGI boot display

### Stage 2: accurate memory + machine model

- Port the Indy 4610 memory map into the emulator core
- Implement the PROM, RAM, I/O windows, and address translation rules
- Add register descriptions for console, timers, and interrupts
- Validate boot vector behavior against the actual ROM image

### Stage 3: CPU expansion and interpreter correctness

- Expand the interpreter to cover the real Indy PROM instruction stream
- Add the missing MIPS operations encountered in actual ROM code
- Model the required privileged, branch, and memory semantics
- Validate execution with the boot path as the primary proof

### Stage 4: device shell and IO mapping

- Implement memory-mapped I/O as explicit register blocks
- Add stubs for graphics, serial, timer, interrupt, and NIC devices
- Model the system controller and boot-time configuration data
- Keep the design aligned with the MAME driver behavior

### Stage 5: storage and network

- SCSI / disk emulation
- bootable CD / ISO image support
- EFS and local filesystem compatibility
- NIC model and network boot hooks

### Stage 6: configuration and boot progression

- Implement machine hardware configuration controls
- Add CPU / memory / graphics / storage / network profiles
- Document and test the hardware profile for the Indy target
- Continue from PROM boot to early IRIX startup path

### Stage 7: JIT acceleration

- Add a MIPS-to-x86_64 block translator for hot code paths
- Cache translated blocks by PC
- Keep memory and MMIO access through helper paths
- Fall back to the interpreter for unsupported or device-intensive paths
- Tune the JIT after the interpreter and hardware model are proven

### Stage 8: IRIX software path

- boot into the PROM / firmware path
- continue to startup and prompt shell
- eventually reach IRIX 5.x userland
- maintain a realistic Indy desktop experience

## Performance target

The performance target is not "full-speed emulation of everything in a naive interpreter". The target is:

- fast enough to run the Indy firmware and early IRIX path smoothly
- able to use JIT translation for hot code blocks
- maintain the same performance philosophy as high-speed IRIS workstation emulation
- keep the architecture extensible for later acceleration

## Summary

This project should be built as a realistic SGI Indy emulator grounded in the public MAME Indy 4610 reference and the SGI/IRIS hardware model, with a C++ core and x86_64 JIT translator layered on top for speed. That is the correct long-term strategy.
