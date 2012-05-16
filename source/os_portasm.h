
#ifndef __OS_PORTASM__
#define __OS_PORTASM__

unsigned int _get_CPSR(void)
{
 asm("mrs r1,cpsr \n"); 
}

#endif