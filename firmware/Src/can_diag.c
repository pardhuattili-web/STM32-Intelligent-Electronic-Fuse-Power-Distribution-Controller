#include "can_diag.h"
#define ID_CONTROL 0x300U
#define ID_THRESH 0x301U
static uint8_t bitmap(const e_fuse_controller_t*c){uint8_t b=0;for(uint8_t i=0;i<4;i++)if(c->rt[i].fault_flags)b|=(uint8_t)(1U<<i);return b;}
uint8_t can_diag_handle(uint16_t id,const uint8_t*d,uint8_t n,e_fuse_controller_t*c,uint8_t*r,uint8_t*rn){
 if(!d||!c||!r||!rn)return 1;
 *rn=1;r[0]=0;
 if(id==ID_CONTROL&&n>=2){uint8_t ch=d[0]&3U;e_fuse_set_channel(c,ch,d[1]?1:0);return 0;}
 if(id==ID_THRESH&&n>=3){uint8_t ch=d[0]&3U;uint16_t ma=(uint16_t)d[1]<<8|d[2];c->cfg[ch].trip_current_a=ma/100.0f;return 0;}
 r[0]=0x7f;return 1;
}
void can_diag_pack_status(const e_fuse_controller_t*c,uint8_t*out){if(!c||!out)return;out[0]=bitmap(c);out[1]=(uint8_t)c->rt[0].state;out[2]=(uint8_t)c->rt[1].state;out[3]=(uint8_t)c->rt[2].state;out[4]=(uint8_t)c->rt[3].state;out[5]=(uint8_t)(c->cycle_count>>8);out[6]=(uint8_t)c->cycle_count;}