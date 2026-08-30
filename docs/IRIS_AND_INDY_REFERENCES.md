# IRIS and Indy reference notes

## Reference focus

The emulator should be built around the SGI Indy family, which is one of the most recognizable IRIS workstations and has a very distinct PROM and boot flow.

## Key topics to keep in mind

- MIPS architecture and early boot ROM conventions
- SGI boot menu conventions and startup text
- memory-mapped graphics subsystem and framebuffer layout
- PROM and NVRAM interactions
- low-level boot diagnostics and hardware identification

## Project priority

The first milestone is not a full IRIX desktop. It is simple and explicit:

- the machine powers on
- the CPU begins executing PROM words
- the PROM code reaches the hardware bootstrap menu
- the framebuffer and display path can start drawing the classic Indy screen

This is the correct staging point before disk boot, networking, and IRIX support.
