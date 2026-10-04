#pragma once
#include <stdint.h>
#include "protection.h"
#include "measurements.h"
#define E_FUSE_CHANNELS 4U
typedef struct { protection_cfg_t cfg[E_FUSE_CHANNELS]; channel_runtime_t rt[E_FUSE_CHANNELS]; measurement_snapshot_t meas; uint32_t cycle_count; } e_fuse_controller_t;
void e_fuse_init(e_fuse_controller_t *c);
void e_fuse_process(e_fuse_controller_t *c,uint32_t dt_ms);
void e_fuse_set_channel(e_fuse_controller_t *c,uint8_t ch,uint8_t on);