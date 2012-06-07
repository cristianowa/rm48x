#ifndef __CCM_H__
#define __CCM_H__


typedef volatile struct ccmBase
{
	unsigned CCMSR;
	unsigned CCMKEYR;

} ccmBASE_t;


#define ccmREG   ((ccmBASE_t *)0xFFFFF600U)

#define LOCKSTEP_MODE 0
#define SELFTEST_MODE 0x6
#define ERROR_FORCING_MODE 0x9
#define SELFTEST_ERROR_FORCING_MODE 0xF



void ccm_set_lockstep_mode();
void ccm_self_test();
void ccm_enable_selftest_error();
void ccm_enable_error();
void ccmErrorNotification();
#endif