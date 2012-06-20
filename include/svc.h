#ifndef __SVC_H__
#define __SVC_H__
#include "sys_common.h"

void _svc(void);
void svc_action_request(uint32_t action);
void svc_call();
void _svc_entry_(void);
void _svc_exit_(void);
enum svc_action {
 CCM_KEYR_SET 
  
};

#endif