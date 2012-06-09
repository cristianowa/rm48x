#include "ccm.h"
#include "sci_print.h"
#include "svc.h"

uint32_t value_ccmkeyr;

void ccm_ccmkeyr()
{
   ccmREG->CCMKEYR = value_ccmkeyr; 
}


void ccm_keyr_set(uint32_t value)
{
  value_ccmkeyr = value;
  svc_action_request(CCM_KEYR_SET);
  svc_call();
}


void ccmErrorNotification()
{
    print_line("ccmErrorNotification");
}


void ccm_set_lockstep_mode()
{
  ccm_keyr_set(LOCKSTEP_MODE);
}

void ccm_self_test()
{
    ccm_keyr_set(SELFTEST_MODE);
  while( !(ccmREG->CCMSR & 0x10 ) );
  if ( ccmREG->CCMSR & 0x1 )
    ccmErrorNotification();
}

void ccm_enable_selftest_error()
{
    ccm_keyr_set(SELFTEST_ERROR_FORCING_MODE);
}



void ccm_enable_error()
{
   ccm_keyr_set( ERROR_FORCING_MODE); 
  
    print_hex(ccmREG->CCMKEYR);
}
