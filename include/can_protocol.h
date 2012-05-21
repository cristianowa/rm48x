#ifndef __CAN__PROTOCOL__H__
#define __CAN__PROTOCOL__H__
#include "can.h"
void can_protocol_init(canBASE_t *node, uint32_t rx_message_box, uint32_t tx_message_box);

int can_protocol_is_message_arrived();

#endif