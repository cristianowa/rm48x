#ifndef __CAN__PROTOCOL__H__
#define __CAN__PROTOCOL__H__
#include "can.h"
typedef uint8_t can_buffer[8];

void can_protocol_send(canBASE_t * node,uint32_t msg_box,uint8_t* message,int size);
void can_protocol_message_arrived(uint8_t* message);

#endif