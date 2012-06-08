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

void __jump();

void ccm_enable_error()
{

  /*must be in supervisor mode to make changes*/

  _svc_entry_();
  
}

void ccm_enable_error_cont()
{
  ccmREG->CCMKEYR = ERROR_FORCING_MODE;
  _svc_exit_();
 
  
  print_hex(ccmREG->CCMKEYR);
}
