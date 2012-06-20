
#ifndef __SCI_PRINT__
#define __SCI_PRINT__

#include "sci.h"
#include "sys_common.h"

void print(uint8_t *text);

void print_line(uint8_t *text);

void print_number(int number);

void print_hex(int number);

void sci_display_text(sciBASE_t *sci, uint8_t *text);

void boot_message();
#define UART scilinREG

#endif