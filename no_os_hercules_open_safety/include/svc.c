#include "svc.h"


#include "ccm.h"

uint32_t svc_action_requested;

void svc_action_request(uint32_t action)
{
    svc_action_requested = action;
}

void _svc(void)
{
  switch(svc_action_requested)
  {
  case CCM_KEYR_SET:
      ccm_ccmkeyr();
    break;
    
  }
_svc_exit_();
}

void svc_call()
{
    _svc_entry_();
}