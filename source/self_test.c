#include "self_test.h"
#include "sys_memory.h"
#include "sci_print.h"

void memoryPort0TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data)
{
  print_line("memoryPort0TestFailNotification");
}

void memoryPort1TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data)
{
   print_line("memoryPort1TestFailNotification");
}