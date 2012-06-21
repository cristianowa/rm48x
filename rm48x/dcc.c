/** @file dcc.c 
*   @brief DCC Driver Inmplmentation File
*   @date 04.October.2011
*   @version 1.02.000
*
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */

#include "dcc.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void dccInit(void)
*   @brief Initializes the DCC Driver
*
*   This function initializes the DCC module.
*/
void dccInit(void)
{

/* USER CODE BEGIN (2) */
/* USER CODE END */

    /** @b intalise @b DCC1 */
	   
    /** DCC1 Clock0 Counter Seed value configuration */
    dccREG1->CNT0SEED   = 78408;
    
    /** DCC1 Clock0 Valid Counter Seed value configuration */
    dccREG1->VALID0SEED = 1584;          
    
    /** DCC1 Clock1 Counter Seed value configuration */
    dccREG1->CNT1SEED   = 792000;

    /** DCC1 Global Control register configuration */
    dccREG1->GCTRL     	= 0xA |       /** Enable DCC1 */
                         (0xA << 4) | /** Error Interrupt */
                         (0x5 << 8) | /** Single Shot mode */
                         (0xA << 12); /** Done Interupt */

    /** DCC1 Clock1 Source 1 Select */
    dccREG1->CLKSRC1    = (10 << 12) |     /** DCC Enable Key */
                          DCC1_CNT1_PLL1;  /** DCC1 Clock Source 1 */
   
    dccREG1->CLKSRC0    = DCC1_CNT0_OSCIN;  /** DCC1 Clock Source 0 */


    /** @b intalise @b DCC2 */

    /** DCC2 Clock0 Counter Seed value configuration */
    dccREG2->CNT0SEED   = 0;
    
    /** DCC2 Clock0 Valid Counter Seed value configuration */
    dccREG2->VALID0SEED = 0;          
    
    /** DCC2 Clock1 Counter Seed value configuration */
    dccREG2->CNT1SEED   = 0;

    /** DCC2 Global Control register configuration */
    dccREG2->GCTRL     	= 0xA |       /** Enable DCC2 */
                         (0xA << 4) | /** Error Interrupt */
                         (0x5 << 8) | /** Single Shot mode */
                         (0xA << 12); /** Done Interupt */

    /** DCC2 Clock1 Source 1 Select */
    dccREG2->CLKSRC1    = (0x5 << 12) |     /** DCC Enable Key */
                          DCC2_CNT1_VCLK;  /** DCC2 Clock Source 1 */
   
    dccREG2->CLKSRC0    = DCC2_CNT0_OSCIN;  /** DCC2 Clock Source 0 */


/* USER CODE BEGIN (3) */
/* USER CODE END */

}

/** @fn void dccSetCounter0Seed(dccBASE_t  *dcc, uint32_t cnt0seed)
*   @brief Set dcc Clock source 0 counter seed value
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*   @param[in] cnt0seed - Clock Source 0 Counter seed value:
*
*   This function sets the seed value for Clock source 0 counter.
*
*/
void dccSetCounter0Seed(dccBASE_t  *dcc, uint32_t cnt0seed)
{
/* USER CODE BEGIN (4) */
/* USER CODE END */

    dcc->CNT0SEED 	= cnt0seed;

/* USER CODE BEGIN (5) */
/* USER CODE END */
}

/** @fn void dccSetTolerance(dccBASE_t  *dcc, uint32_t valid0seed)
*   @brief Set dcc Clock source 0 counter seed value
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*   @param[in] valid0seed - Clock Source 0 Counter tolerence value:
*
*   This function sets the seed value for Clock source 0 tolerance or 
*	valid counter.
*
*/
void dccSetTolerance(dccBASE_t  *dcc, uint32_t valid0seed)
{
/* USER CODE BEGIN (6) */
/* USER CODE END */

    dcc->VALID0SEED = valid0seed;

/* USER CODE BEGIN (7) */
/* USER CODE END */
}

/** @fn void dccSetCounter1Seed(dccBASE_t  *dcc, uint32_t cnt1seed)
*   @brief Set dcc Clock source 1 counter seed value
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*   @param[in] cnt1seed - Clock Source 1 Counter seed value:
*
*   This function sets the seed value for Clock source 1 counter.
*
*/

void dccSetCounter1Seed(dccBASE_t  *dcc, uint32_t cnt1seed)
{
/* USER CODE BEGIN (8) */
/* USER CODE END */

    dcc->CNT1SEED 	= cnt1seed;

/* USER CODE BEGIN (9) */
/* USER CODE END */
}

/** @fn void dccSetSeed(dccBASE_t  *dcc, uint32_t cnt0seed, uint32_t valid0seed, uint32_t cn1seed)
*   @brief Set dcc Clock source 0 counter seed value
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*   @param[in] cnt0seed		- Clock Source 0 Counter seed value.
*   @param[in] valid0seed	- Clock Source 0 Counter tolerence value:
*   @param[in] cnt0seed		- Clock Source 1 Counter seed value.
*
*   This function sets the seed value for clock source 0, clock source 1 
*	and tolerence counter.
*
*/
void dccSetSeed(dccBASE_t  *dcc, uint32_t cnt0seed, uint32_t valid0seed, uint32_t cnt1seed)
{
/* USER CODE BEGIN (10) */
/* USER CODE END */

    dcc->CNT0SEED   = cnt0seed;
    dcc->VALID0SEED = valid0seed;
    dcc->CNT1SEED   = cnt1seed;

/* USER CODE BEGIN (11) */
/* USER CODE END */
}

/** @fn void dccSelectClockSource(dccBASE_t  *dcc, uint32_t cnt0_Clock_Source, uint32_t cnt1_Clock_Source)
*   @brief Set dcc counter Clock sources
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*   @param[in] cnt0_Clock_Source - Clock source for counter 0.
*   @param[in] cnt1_Clock_Source - Clock source for counter 1.
*
*   This function sets the dcc counter 0 and counter 1 clock sources.
*
*/
void dccSelectClockSource(dccBASE_t  *dcc, uint32_t cnt0_Clock_Source, uint32_t cnt1_Clock_Source)
{
/* USER CODE BEGIN (12) */
/* USER CODE END */

    dcc->CLKSRC1 = cnt1_Clock_Source;
    dcc->CLKSRC0 = cnt0_Clock_Source;

/* USER CODE BEGIN (13) */
/* USER CODE END */
}

/** @fn void dccEnable(dccBASE_t  *dcc)
*   @brief Enable dcc module to begin counting
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*
*   This function enables the dcc counters to begin counting.
*
*/
void dccEnable(dccBASE_t  *dcc)
{
/* USER CODE BEGIN (14) */
/* USER CODE END */

    dcc->GCTRL = (dcc->GCTRL & 0xFFFFFFF0) | 0xA; 

/* USER CODE BEGIN (15) */
/* USER CODE END */
}

/** @fn void dccDisable(dccBASE_t  *dcc)
*   @brief Make selected dcc module to stop counting
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*
*   This function stops the dcc counters from counting.
*
*/
void dccDisable(dccBASE_t  *dcc)
{
/* USER CODE BEGIN (16) */
/* USER CODE END */

    dcc->GCTRL = (dcc->GCTRL & 0xFFFFFFF0) | 0x5; 

/* USER CODE BEGIN (17) */
/* USER CODE END */
}

/** @fn uint32_t dccGetErrStatus(dccBASE_t  *dcc)
*   @brief Get error status from selected dcc module
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*
*   @return The Error status of selected dcc module
*
*   Returns the error status of selected dcc module.
*
*/
uint32_t dccGetErrStatus(dccBASE_t  *dcc)
{
/* USER CODE BEGIN (18) */
/* USER CODE END */

    return(dcc->STAT & 0x00000001); 
}

/** @fn void dccEnableNotification(dccBASE_t  *dcc, uint32_t notification)
*   @brief Enable notification of selected DCC module
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*   @param[in] notification Select notification of DCC module:
*              - dccNOTIFICATION_DONE:	DCC DONE notification
*              - dccNOTIFICATION_ERROR: DCC ERROR notification
*
*   This function will enable the selected notification of a DCC module.
*   It is possible to enable multiple notifications masked.
*/

void dccEnableNotification(dccBASE_t  *dcc, uint32_t notification)
{
/* USER CODE BEGIN (19) */
/* USER CODE END */

    dcc->GCTRL = ((dcc->GCTRL & 0xFFFF0FF0) | notification); 

/* USER CODE BEGIN (20) */
/* USER CODE END */
}

/** @fn void dccDisableNotification(uint32_t notification)
*   @brief Disable notification of selected DCC module
*   @param[in] dcc Pointer to DCC module:
*              - dccREG1: DCC1 module pointer
*              - dccREG2: DCC2 module pointer
*   @param[in] notification Select notification of DCC module:
*              - dccNOTIFICATION_DONE:	DCC DONE notification
*              - dccNOTIFICATION_ERROR: DCC ERROR notification
*
*   This function will enable the selected notification of a DCC module.
*   It is possible to enable multiple notifications masked.
*/

void dccDisableNotification(dccBASE_t  *dcc, uint32_t notification)
{
/* USER CODE BEGIN (21) */
/* USER CODE END */

    dcc->GCTRL = ((dcc->GCTRL & 0xFFFF0FF0) | ((~notification) & 0x0000F00F)); 

/* USER CODE BEGIN (22) */
/* USER CODE END */
}

/** @fn void dcc1DoneInterrupt(void)
*   @brief DCC Interrupt Handler
*
*   DCC1 Done Interrupt handler for DCC1 interrupt 
*
*/
#pragma INTERRUPT(dcc1DoneInterrupt, IRQ)

void dcc1DoneInterrupt(void)
{
    uint32_t flags = dccREG1->STAT;

/* USER CODE BEGIN (23) */
/* USER CODE END */

				dccREG1->STAT = flags;
    dccNotification(dccREG1,flags);

/* USER CODE BEGIN (24) */
/* USER CODE END */
}


/** @fn void dcc2DoneInterrupt(void)
*   @brief DCC Interrupt Handler
*
*   DCC2 Done Interrupt handler for DCC2 interrupt 
*
*/
#pragma INTERRUPT(dcc2DoneInterrupt, IRQ)

void dcc2DoneInterrupt(void)
{
    uint32_t flags = dccREG2->STAT;

/* USER CODE BEGIN (25) */
/* USER CODE END */

    dccREG2->STAT = flags;
    dccNotification(dccREG2,flags);

/* USER CODE BEGIN (26) */
/* USER CODE END */
}

