# STM32 Intelligent Electronic Fuse & Power Distribution Controller

A reference STM32 embedded controller for smart low-voltage power distribution. The firmware models four protected load channels, evaluates current, voltage, and temperature measurements, disconnects faulty channels through deterministic state machines, and reports health and fault information over CAN.

> Safety and validation: software/reference implementation only. Real power-stage behavior, MOSFET SOA, current-sense accuracy, thermal performance, EMC, and fault-clearing behavior require hardware validation with protected low-voltage test equipment.

## Why this project

A conventional fuse only opens after a fault. An intelligent electronic fuse can measure the event, react using defined protection rules, identify the failed channel, report diagnostics, and support controlled recovery.

## Architecture

Power source -> four load channels -> sensing -> measurement layer -> protection FSMs -> CAN diagnostics.

Each channel has independent state, threshold configuration, fault flags, retry counters, and output control.

## Channel state machine

OFF -> ARMED -> ON -> TRIP -> LATCHED_FAULT

A non-critical event can optionally use a cooldown and retry path before returning to ARMED.

## Features

- Four independent protected channels
- Current, bus-voltage, and temperature measurement abstraction
- Configurable per-channel current limits
- Over-current and thermal protection
- Fault latching
- Configurable automatic retry
- Per-channel current and energy statistics
- CAN command/status interface
- Fault and event counters
- Software fault-injection mode
- Deterministic host-side tests
- Hardware-independent reference implementation

## CAN interface

| CAN ID | Direction | Purpose |
|---|---|---|
| 0x300 | Master -> Controller | Channel control |
| 0x301 | Master -> Controller | Threshold configuration |
| 0x310 | Controller -> Master | Channel currents |
| 0x311 | Controller -> Master | Bus voltage and temperature |
| 0x320 | Controller -> Master | Fault bitmap |
| 0x330 | Controller -> Master | Event counters |

These IDs are project-local examples, not an OEM database.

## Protection policy

1. Acquire and validate measurements.
2. Apply qualification/filtering.
3. Compare against channel thresholds.
4. Trip persistent over-current or thermal faults.
5. Latch critical faults.
6. Optionally retry after cooldown.
7. Report state and diagnostics over CAN.

For safety-critical products, the fastest shutdown path should have independent hardware protection rather than relying only on firmware.

## Recommended hardware

- STM32G4 or STM32F3-class MCU
- Suitable current-sense amplifier/sensor
- Low-Rds(on) MOSFET power stage
- Gate driver where required
- NTC temperature sensor
- CAN transceiver
- Protected low-voltage DC source
- Resistive or electronic dummy loads

## Repository structure

```
firmware/
  Inc/
    e_fuse.h
    measurements.h
    protection.h
    can_diag.h
    channel_config.h
  Src/
    e_fuse.c
    measurements.c
    protection.c
    can_diag.c
    app_reference.c
test/
  protection_test.c
tools/
  can_demo.py
docs/
  architecture.md
  can_protocol.md
  protection_model.md
  test_plan.md
```

## Validation status

Software logic and deterministic test cases are included. Physical trip latency, thermal limits, switching losses, MOSFET safe-operating-area compliance, CAN electrical behavior, and automotive qualification are not claimed without hardware measurements.

## License

MIT
