# Research summary

This project is grounded in the public SGI Indy / IRIS hardware model and the overall patterns used by classic workstation emulators.

## Hardware direction

The primary goals are to emulate the Indy family in a pragmatic way:

- R4400-class MIPS CPU behavior
- PROM-based startup flow
- system memory map and device windows
- 24-bit XL graphics framebuffer
- local storage and CD media
- networked boot and NIC support

## Emulator direction

The emulator design follows a staged architecture:

- Stage 1: CPU, PROM, and memory model
- Stage 2: device skeletons and NVRAM
- Stage 3: graphics framebuffer and startup screen
- Stage 4: storage, CD, SCSI, and EFS
- Stage 5: networking and IRIX compatibility

## GUI requirements

The early GUI is a hardware-planning dashboard that shows the full future system surface even before all devices are implemented. It mirrors the intended machine shell and will be expanded into a real hardware console as the project matures.

## Important file in this repo

The screenshot included in the repository shows the classic Indy PROM boot menu and is treated as the target visual milestone for the early emulator output.

The file is:

- 0001.png
