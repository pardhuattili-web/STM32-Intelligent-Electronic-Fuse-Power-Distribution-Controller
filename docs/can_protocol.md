# CAN Protocol

- 0x300: channel control. Byte 0 = channel 0..3, byte 1 = 0/1.
- 0x301: threshold configuration. Byte 0 = channel, bytes 1..2 = trip current in A x100.
- 0x310: current telemetry.
- 0x311: bus voltage/temperature telemetry.
- 0x320: fault bitmap and channel states.
- 0x330: event counters.

IDs are project-local examples, not an OEM CAN database.