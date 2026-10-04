#include "measurements.h"
void measurements_default(measurement_snapshot_t*m){if(!m)return;*m=(measurement_snapshot_t){.current_a={0,0,0,0},.bus_voltage_v=12.0f,.temperature_c={25,25,25,25}};}
float measurements_channel_power(const measurement_snapshot_t*m,uint8_t ch){if(!m||ch>=4)return 0.0f;return m->bus_voltage_v*m->current_a[ch];}
float measurements_total_power(const measurement_snapshot_t*m){if(!m)return 0.0f;float p=0;for(uint8_t i=0;i<4;i++)p+=measurements_channel_power(m,i);return p;}