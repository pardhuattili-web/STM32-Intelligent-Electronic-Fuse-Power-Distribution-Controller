#pragma once
#include <stdint.h>
typedef struct { float current_a[4]; float bus_voltage_v; float temperature_c[4]; } measurement_snapshot_t;
void measurements_default(measurement_snapshot_t *m);
float measurements_channel_power(const measurement_snapshot_t *m,uint8_t ch);
float measurements_total_power(const measurement_snapshot_t *m);