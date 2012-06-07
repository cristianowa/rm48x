#include "ccm.h"
#include "sci_print.h"
void ccmErrorNotification()
{
    print_line("ccmErrorNotification");
}

void ccm_set_lockstep_mode()
{
  ccmREG->CCMKEYR = LOCKSTEP_MODE;  
}

void ccm_self_test()
{
  ccmREG->CCMKEYR = SELFTEST_MODE;
  while( !(ccmREG->CCMSR & 0x10 ) );
  if ( ccmREG->CCMSR & 0x1 )
    ccmErrorNotification();
}

void ccm_enable_selftest_error()
{
  ccmREG->CCMKEYR = SELFTEST_ERROR_FORCING_MODE;
}

void ccm_enable_error()
{
  asm("mrs r8,cpsr");
  asm("mrs r10,cpsr");
  asm("and r9,r8,#0xFFFFFF00");
  asm("orr r8,r9,#0x1F");
  asm("msr cpsr,r9");
  
  /*must be in supervisor mode to make changes*/
  
  ccmREG->CCMKEYR = ERROR_FORCING_MODE;
      
  asm("msr cpsr,r10");    
  
  print_hex(ccmREG->CCMKEYR);
}
