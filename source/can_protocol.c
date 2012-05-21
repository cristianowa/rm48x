#include "can_protocol.h"
#include "can.h"

#define MAXIMUM_MESSAGE_SIZE 1500

volatile canBASE_t * can;
uint32_t msg_box_rx;
uint32_t msg_box_tx;
int message_arrived = 0;

uint8_t message_buffer[MAXIMUM_MESSAGE_SIZE] = {0};
int buffer_index = 0;
void can_protocol_init(canBASE_t *node, uint32_t rx_message_box, uint32_t tx_message_box)
{
    can = node;
    msg_box_rx = rx_message_box;
    msg_box_tx = tx_message_box;
}

int can_protocol_is_message_arrived()
{
  return message_arrived;
}

void can_protocol_receive_fragment()
{
  
  
}

uint8_t* can_protocol_receive()
{
 
  buffer_index = 0;
}


void can_protocol_send(uint8_t* message)
{
  
}