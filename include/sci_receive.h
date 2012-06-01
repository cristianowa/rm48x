#ifndef __SCI__RECEIVE__
#define __SCI__RECEIVE__

extern uint8_t sci_transfer_buffer[4];

void sci_receive_rotine();

int sci_receive_byte();

void sci_receive_wait(uint8_t ch);

int sci_receive_key_pressed(uint8_t ch);

int promt_question(uint8_t* question);
#endif