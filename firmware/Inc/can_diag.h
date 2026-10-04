#pragma once
#include <stdint.h>
#include "e_fuse.h"
uint8_t can_diag_handle(uint16_t id,const uint8_t *data,uint8_t len,e_fuse_controller_t *c,uint8_t *response,uint8_t *response_len);
void can_diag_pack_status(const e_fuse_controller_t *c,uint8_t *out);