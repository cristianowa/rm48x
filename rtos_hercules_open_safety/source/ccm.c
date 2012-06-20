#include "ccm.h"
#include "sci_print.h"

uint32_t value_ccmkeyr;


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
   ccmREG->CCMKEYR = ERROR_FORCING_MODE; 
  
    print_hex(ccmREG->CCMKEYR);
}
