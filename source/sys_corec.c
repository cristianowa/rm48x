#include "sys_core.h"

unsigned int _get_CPSR(void)
{
 asm("mrs r1,cpsr \n"); 
}