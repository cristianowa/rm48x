#include "self_test.h"
#include "sys_memory.h"
#include "sci_print.h"
#include "sci.h"

void memoryPort0TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data)
{
  sciInit();
  print_line("memoryPort0TestFailNotification\n\r");
}

void memoryPort1TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data)
{
   sciInit();
   print_line("memoryPort1TestFailNotification\n\r");
}