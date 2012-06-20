#ifndef __DEBUG__H__
#define __DEBUG__H__

#include "sys_common.h"

#define PRINT_FUNCTION(m,x) debug_print(m,#x); x;


void debug_print(uint8_t *id,uint8_t *text);
void dump_memory(void *start,int size);
void dump_memory_promt(uint8_t * question,int address,int size);

//#define __MAC_DEBUG__
#define __CAN__DEBUG__
#define __CAN_PROTOCOL__DEBUG__
#endif