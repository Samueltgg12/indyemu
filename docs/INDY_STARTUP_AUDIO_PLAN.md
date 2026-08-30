# Indy PROM startup audio plan

This is the next milestone after the graphics and CPU core work.

## Objective

When the emulator reaches the SGI Indy PROM path, it should trigger the startup audio sequence associated with the machine.

## Source of truth

The project includes the PROM-extracted sample in the `samples` directory:

- `samples/indy_boot.aiff`

This is the canonical starting point for the audio device model.

## Implementation strategy

1. Add an `AudioDevice` component to the hardware model.
2. Hook it into the Indy memory-mapped IO map.
3. Trigger the audio event as soon as the PROM boot path reaches the startup sequence.
4. Keep the audio path controllable through register writes and an enable/disable flag.
5. Keep the device logic isolated so the JIT and interpreter can continue to run without direct audio coupling.

## Sound hardware direction

The audio path should eventually model:

- sound register windows
- playback enable and volume registers
- a startup sample trigger path
- host playback fallback when a local audio backend exists

## Current stage

This is the first implementation pass. The device is intentionally simple and will be expanded once the base graphic and CPU core are fully stable.
