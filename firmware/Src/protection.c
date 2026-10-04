#include "protection.h"
#define FAULT_OVERCURRENT 1U
#define FAULT_OVERTEMP 2U
void protection_init(channel_runtime_t*r){if(!r)return;*r=(channel_runtime_t){.state=E_FUSE_OFF};}
void protection_command_on(channel_runtime_t*r){if(!r)return;if(r->state==E_FUSE_OFF||r->state==E_FUSE_ARMED){r->state=E_FUSE_ON;r->output_enabled=1;}}
void protection_command_off(channel_runtime_t*r){if(!r)return;r->output_enabled=0;r->state=E_FUSE_OFF;}
void protection_step(channel_runtime_t*r,const protection_cfg_t*c,float i,float t,uint32_t dt){
 if(!r||!c)return;
 if(r->state==E_FUSE_ON){
   if(i>=c->trip_current_a){r->output_enabled=0;r->fault_flags|=FAULT_OVERCURRENT;r->trip_count++;r->state=c->auto_retry?E_FUSE_RETRY_WAIT:E_FUSE_LATCHED_FAULT;}
   else if(t>=c->over_temp_c){r->output_enabled=0;r->fault_flags|=FAULT_OVERTEMP;r->trip_count++;r->state=E_FUSE_LATCHED_FAULT;}
 } else if(r->state==E_FUSE_RETRY_WAIT && dt>=c->retry_delay_ms){
   if(r->retry_count<c->max_retries){r->retry_count++;r->fault_flags=0;r->state=E_FUSE_ARMED;protection_command_on(r);}
   else r->state=E_FUSE_LATCHED_FAULT;
 }
}