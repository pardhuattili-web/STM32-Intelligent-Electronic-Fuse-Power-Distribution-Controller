#include "e_fuse.h"
void e_fuse_reference_step(void){e_fuse_controller_t c;e_fuse_init(&c);e_fuse_set_channel(&c,0,1);c.meas.current_a[0]=6.0f;e_fuse_process(&c,10);}