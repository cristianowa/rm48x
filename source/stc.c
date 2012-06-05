/** @file stc.c 
*   @brief STC Driver Implmentation File
*   @date 14.September.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "stc.h"
#include "system.h"
#include "sci.h"
#include "esm.h"

extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);
extern void _coreBackupStackPointer_(void);
extern void _coreRestoreStackPointer_(void);

/** @fn void stcInit(void)
*   @brief Initializes the STC Driver
*
*   This function initializes the STC module.
*/
void stcInit(void)
{

	/* Clear CPU RST bit in Exception Status Register in Sys module */	
	systemREG1->SYSESR = 0x20U; 

	/* clock rate for STC/LBIST = 80MHz when HCLK=160MHz 
	 * 160 / 2 = 80 MHz */	
	systemREG2->STCCLKDIV = 1U;
	
  	/* Select the Test interval for Max coverage, 32 Interval for 90.84 */
  	stcREG->STCGCR0 = (24 << 16);

  	/* Restart the Test from Interval 0 */
  	//stcREG->STCGCR0 |= 1;

  	/* Configure the SelfTest Run Time out counter preload Register */
  	stcREG->STCTPRL = 0xFFFFFFFF;
}

/** @fn void stcStartSelfTest(void)
*   @brief Function used to start the STC self test
*
*   Note : Reset occurs once the STC is triggered and completed. 
*/
void stcStartSelfTest(void)
{
	/** - Backup Stack pointers before stating STC test */
	_coreBackupStackPointer_();

  	/** - Enable the STC Self Test */
  	stcREG->STCGCR1 = 0xA;

  	/** - Enter ARM IDLE state to start the test  */
  	asm("	WFI");
        asm("	nop");
  	asm("	nop");
  	asm("	nop");
        /* The code for handling the return of the self-test is in the sys_startup.c file */
  
}

/** @fn void stc_test(void)
*   @brief Function used to perform STC self test.
*/
void stc_test(void)
{
	/** - Initialize STC module */
	stcInit();
	
	/** - Start STC Self Test */
	stcStartSelfTest();
}	

void stcErrorNotification(void)
{
  esmEnableError(0xFFFFFFFFFFFFFFFF);
    sciInit();
    print_line("stcErrorNotification\n\r");  
  
}