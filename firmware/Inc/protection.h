#pragma once
#include <stdint.h>
typedef enum { E_FUSE_OFF, E_FUSE_ARMED, E_FUSE_ON, E_FUSE_RETRY_WAIT, E_FUSE_TRIP, E_FUSE_LATCHED_FAULT } e_fuse_state_t;
typedef struct { float over_current_a; float trip_current_a; float over_temp_c; uint8_t auto_retry; uint8_t max_retries; uint32_t retry_delay_ms; } protection_cfg_t;
typedef struct { e_fuse_state_t state; uint8_t output_enabled; uint8_t retry_count; uint16_t fault_flags; uint32_t trip_count; } channel_runtime_t;
void protection_init(channel_runtime_t *rt);
void protection_command_on(channel_runtime_t *rt);
void protection_command_off(channel_runtime_t *rt);
void protection_step(channel_runtime_t *rt,const protection_cfg_t *cfg,float current_a,float temp_c,uint32_t dt_ms);