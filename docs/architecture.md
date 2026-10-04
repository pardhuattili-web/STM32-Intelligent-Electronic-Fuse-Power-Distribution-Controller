# Architecture

Measurement acquisition is separated from protection policy and CAN diagnostics.

ADC/current/NTC interfaces -> measurements.c -> e_fuse.c -> protection.c per-channel FSM -> can_diag.c.

A production power stage should also provide an independent fast hardware current-trip path. Firmware owns latching, retry, configuration, diagnostics, and telemetry.