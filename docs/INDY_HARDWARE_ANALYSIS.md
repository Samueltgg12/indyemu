# SGI Indy hardware analysis and emulator plan

## Summary

The SGI Indy is a MIPS-based workstation family built around a R4400-class CPU and a PROM-based boot path. The initial emulator goal is to reach the PROM and early hardware initialization, then add a 24-bit XL graphics framebuffer and system devices in stages.

## Core hardware assumptions

- CPU: MIPS R4400-class architecture
- Reset vector: PROM region at 0xBFC00000
- PROM boot image: embedded startup menu and diagnostics
- RAM: system memory mapped at the standard 0x80000000 window
- I/O: memory-mapped registers and device access relative to the Indy chipset
- Graphics: 24-bit XL framebuffer in the early boot path
- Audio: sound pipeline and startup tones
- Storage: CD-ROM/ISO, SCSI, disk images, EFS, and installation media
- Networking: local Ethernet with a pre-generated NVRAM MAC address

## Planned boot flow

1. Reset enters PROM code at the MIPS reset vector.
2. PROM initializes CPU state, memory, and basic controller paths.
3. Diagnostics and startup menu is displayed on the framebuffer.
4. Boot configuration is selected from NVRAM and boot devices.
5. System software is loaded from disk or installation media.

## NVRAM and networking requirements

The early emulator should include a pre-generated NVRAM payload with this stable Ethernet address:

08:00:69:12:34:56

This gives a consistent network identity for future NIC and boot protocols.

## Storage and filesystem plan

- CD-ROM / ISO images
- SCSI disk image support
- SGI EFS support
- installation and recovery media
- read-only media and writable disk image handling

## Graphics plan

The target screen is the classic Indy PROM and early workstation startup display, matching the blue background and menu interface seen in the screenshot in this repository.

## Software references to study

- SGI Indy PROM startup flow
- IRIX boot and installation procedures
- MAME SGI hardware mapping patterns
- other SGI workstation emulator work
- public SGI Indy and IRIS hardware documentation

## Current project milestone

The current milestone is defined as:

- boot to the SGI Indy PROM
- confirm the reset vector works
- emulate the MIPS CPU enough to execute PROM words
- keep a staged road to disk, graphics, and networked IRIX operation
