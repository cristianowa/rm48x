#ifndef __MAC__
#define __MAC__
#include "sys_common.h"

int macInit();


int eth_transmmit(uint8_t* buf,uint32_t length);

int eth_dummy_send();

void dump_mac_state();

typedef struct eth_frame_t
{
  uint8_t destination;
  
} eth_frame_t;

#endif