/** @file sys_startup.c 
*   @brief Startup Source File
*   @date 15.Feb.2012
*   @version 03.00.01
*
*   This file contains:
*   - Include Files
*   - Type Definitions
*   - External Functions
*   - VIM RAM Setup
*   - Startup Routine
*   .
*   which are relevant for the Startup.
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */

/* USER CODE BEGIN (0) */
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "het.h"
#include "pinmux.h"
#include "sci_print.h"
#include "mac.h"
#include "can.h"
/* USER CODE END */


/* Include Files */

#include "sys_common.h"
#include "system.h"
#include "sys_vim.h"
#include "sys_core.h"
#include "sys_memory.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */


/* Type Definitions */

/* USER CODE BEGIN (2) */
/* USER CODE END */


/* External Functions */

extern void __cmain(void);

/* USER CODE BEGIN (3) */
void osInit(void)
{
/* Set high end timer GIO port hetPort pin direction to all output */
    gioSetDirection(hetPORT1, 0xFFFFFFFF);

     boot_message(); 
    /* Create Task 1 */
    if (xTaskCreate(vTask1, (const signed char *)"Task1", configMINIMAL_STACK_SIZE, NULL, 1, &xTask1Handle) != pdTRUE)
    {
        /* Task could not be created */
        while(1);
    }

    if (xTaskCreate(vTask2, (const signed char *)"Task2", configMINIMAL_STACK_SIZE, NULL, 1, &xTask2Handle) != pdTRUE)
    {
        /* Task could not be created */
        while(1);
    }
    
    if (xTaskCreate(vTask3, (const signed char *)"Task3", configMINIMAL_STACK_SIZE, NULL, 1, &xTask3Handle) != pdTRUE)
    {
        /* Task could not be created */
        while(1);
    }
    
    if (xTaskCreate(vTask4, (const signed char *)"Task4", configMINIMAL_STACK_SIZE, NULL, 1, &xTask4Handle) != pdTRUE)
    {
        /* Task could not be created */
        while(1);
    }

    /* Start Scheduler */
    vTaskStartScheduler();

    /* Run forever */
    while(1);
}
/* USER CODE END */


/* Vim Ram Definition */
/** @struct vimRam
*   @brief Vim Ram Definition
*
*   This type is used to access the Vim Ram.
*/
/** @typedef vimRAM_t
*   @brief Vim Ram Type Definition
*
*   This type is used to access the Vim Ram.
*/
typedef volatile struct vimRam
{
    t_isrFuncPTR ISR[VIM_CHANNELS];
} vimRAM_t;

#define vimRAM ((vimRAM_t *)0xFFF82000U)

static const t_isrFuncPTR s_vim_init[] =
{
    &phantomInterrupt,
    &esmHighInterrupt,
    &phantomInterrupt,
    &vPreemptiveTick,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &linHighLevelInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &esmLowInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &linLowLevelInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &can2LowLevelInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
    &phantomInterrupt,
};


/* Startup Routine */

/* USER CODE BEGIN (4) */
/* USER CODE END */

/* Note: stackless keyword is supported since compiler version 6.20.1 */
__stackless

void _c_int00()
{
	
/* USER CODE BEGIN (5) */
/* USER CODE END */

    /* Initialize Core Registers to avoid CCM Error */
    _coreInitRegisters_();

    /* Initialize Stack Pointers */
    _coreInitStackPointer_();

/* USER CODE BEGIN (6) */
/* USER CODE END */

    /* Implement work-around for CCM-R4 issue on silicon revision A */
    if (DEVICE_ID_REV == 0x802AAD05)
    {
        _esmCcmErrorsClear_();
    }
	 
/* USER CODE BEGIN (7) */
/* USER CODE END */

    /* Reset handler: the following instructions read from the system exception status register
     * to identify the cause of the CPU reset.
     */

	/* check for power-on reset condition */
	if (SYS_EXCEPTION & 0x8000)
	{
		/* clear all reset status flags */
		SYS_EXCEPTION = 0xFFFF;

/* USER CODE BEGIN (8) */
/* USER CODE END */

		/* continue with normal start-up sequence */
	}
	else if (SYS_EXCEPTION & 0x4000)
	{
		/* Reset caused due to oscillator failure.
		Add user code here to handle oscillator failure */

/* USER CODE BEGIN (9) */
/* USER CODE END */
	}
	else if (SYS_EXCEPTION & 0x2000)
	{
		/* Reset caused due to windowed watchdog violation.
		Add user code here to handle watchdog violation */

/* USER CODE BEGIN (10) */
/* USER CODE END */
	}
	else if (SYS_EXCEPTION & 0x20)
	{
		/* Reset caused due to CPU reset.
		CPU reset can be caused by CPU self-test completion, or
		by toggling the "CPU RESET" bit of the CPU Reset Control Register.
		Add user code to handle CPU reset:
		check for selftest completion without any error and continue start-up. */

/* USER CODE BEGIN (11) */
/* USER CODE END */
	}
	else if (SYS_EXCEPTION & 0x10)
	{
		/* Reset caused due to software reset.
		Add user code to handle software reset. */

/* USER CODE BEGIN (12) */
/* USER CODE END */
	}
	else
	{
		/* Reset caused by nRST being driven low externally.
		Add user code to handle external reset. */

/* USER CODE BEGIN (13) */
/* USER CODE END */
	}

    /* Initialize System */
    systemInit();
	
    /* Initialize memory */
    _memoryInit_();
	
    /* Initialize VIM table */
    {
        uint32_t i;

        for (i = 0; i < 90U; i++)
        {
            vimRAM->ISR[i] = s_vim_init[i];
        }
    }

    /* set IRQ/FIQ priorities */
    vimREG->FIRQPR0 =  SYS_FIQ
                    | (SYS_FIQ <<  1U)
                    | (SYS_IRQ <<  2U)
                    | (SYS_IRQ <<  3U)
                    | (SYS_IRQ <<  4U)
                    | (SYS_IRQ <<  5U)
                    | (SYS_IRQ <<  6U)
                    | (SYS_IRQ <<  7U)
                    | (SYS_IRQ <<  8U)
                    | (SYS_IRQ <<  9U)
                    | (SYS_IRQ << 10U)
                    | (SYS_IRQ << 11U)
                    | (SYS_IRQ << 12U)
                    | (SYS_IRQ << 13U)
                    | (SYS_IRQ << 14U)
                    | (SYS_IRQ << 15U)
                    | (SYS_IRQ << 16U)
                    | (SYS_IRQ << 17U)
                    | (SYS_IRQ << 18U)
                    | (SYS_IRQ << 19U)
                    | (SYS_IRQ << 20U)
                    | (SYS_IRQ << 21U)
                    | (SYS_IRQ << 22U)
                    | (SYS_IRQ << 23U)
                    | (SYS_IRQ << 24U)
                    | (SYS_IRQ << 25U)
                    | (SYS_IRQ << 26U)
                    | (SYS_IRQ << 27U)
                    | (SYS_IRQ << 28U)
                    | (SYS_IRQ << 29U)
                    | (SYS_IRQ << 30U)
                    | (SYS_IRQ << 31U);

    vimREG->FIRQPR1 =  SYS_IRQ
                    | (SYS_IRQ <<  1U)
                    | (SYS_IRQ <<  2U)
                    | (SYS_IRQ <<  3U)
                    | (SYS_IRQ <<  4U)
                    | (SYS_IRQ <<  5U)
                    | (SYS_IRQ <<  6U)
                    | (SYS_IRQ <<  7U)
                    | (SYS_IRQ <<  8U)
                    | (SYS_IRQ <<  9U)
                    | (SYS_IRQ << 10U)
                    | (SYS_IRQ << 11U)
                    | (SYS_IRQ << 12U)
                    | (SYS_IRQ << 13U)
                    | (SYS_IRQ << 14U)
                    | (SYS_IRQ << 15U)
                    | (SYS_IRQ << 16U)
                    | (SYS_IRQ << 17U)
                    | (SYS_IRQ << 18U)
                    | (SYS_IRQ << 19U)
                    | (SYS_IRQ << 20U)
                    | (SYS_IRQ << 21U)
                    | (SYS_IRQ << 22U)
                    | (SYS_IRQ << 23U)
                    | (SYS_IRQ << 24U)
                    | (SYS_IRQ << 25U)
                    | (SYS_IRQ << 26U)
                    | (SYS_IRQ << 27U)
                    | (SYS_IRQ << 28U)
                    | (SYS_IRQ << 29U)
                    | (SYS_IRQ << 30U)
                    | (SYS_IRQ << 31U);


    vimREG->FIRQPR2 =  SYS_IRQ
                    | (SYS_IRQ << 1U)
                    | (SYS_IRQ << 2U)
                    | (SYS_IRQ << 3U)
                    | (SYS_IRQ << 4U)
                    | (SYS_IRQ << 5U)
                    | (SYS_IRQ << 6U)
                    | (SYS_IRQ << 7U)
                    | (SYS_IRQ << 8U)
                    | (SYS_IRQ << 9U)
                    | (SYS_IRQ << 10U)
                    | (SYS_IRQ << 11U)
                    | (SYS_IRQ << 12U)
                    | (SYS_IRQ << 13U)
                    | (SYS_IRQ << 14U)
                    | (SYS_IRQ << 15U)
                    | (SYS_IRQ << 16U)
                    | (SYS_IRQ << 17U)
                    | (SYS_IRQ << 18U)
                    | (SYS_IRQ << 19U)
                    | (SYS_IRQ << 20U)
                    | (SYS_IRQ << 21U)
                    | (SYS_IRQ << 22U)
                    | (SYS_IRQ << 23U)
                    | (SYS_IRQ << 24U)
                    | (SYS_IRQ << 25U);


    /* enable interrupts */
    vimREG->REQMASKSET0 = 1U
                        | (0U << 1U)
                        | (1U << 2U)
                        | (0U << 3U)
                        | (0U << 4U)
                        | (0U << 5U)
                        | (0U << 6U)
                        | (0U << 7U)
                        | (0U << 8U)
                        | (0U << 9U)
                        | (0U << 10U)
                        | (0U << 11U)
                        | (0U << 12U)
                        | (1U << 13U)
                        | (0U << 14U)
                        | (0U << 15U)
                        | (0U << 16U)
                        | (0U << 17U)
                        | (0U << 18U)
                        | (0U << 19U)
                        | (1U << 20U)
                        | (0U << 21U)
                        | (0U << 22U)
                        | (0U << 23U)
                        | (0U << 24U)
                        | (0U << 25U)
                        | (0U << 26U)
                        | (1U << 27U)
                        | (0U << 28U)
                        | (0U << 29U)
                        | (0U << 30U)
                        | (0U << 31U);

    vimREG->REQMASKSET1 = 0U
                        | (0U << 1U)
                        | (0U << 2U)
                        | (0U << 3U)
                        | (0U << 4U)
                        | (0U << 5U)
                        | (0U << 6U)
                        | (0U << 7U)
                        | (0U << 8U)
                        | (0U << 9U)
                        | (1U << 10U)
                        | (0U << 11U)
                        | (0U << 12U)
                        | (0U << 13U)
                        | (0U << 14U)
                        | (0U << 15U)
                        | (0U << 16U)
                        | (0U << 17U)
                        | (0U << 18U)
                        | (0U << 19U)
                        | (0U << 20U)
                        | (0U << 21U)
                        | (0U << 22U)
                        | (0U << 23U)
                        | (0U << 24U)
                        | (0U << 25U)
                        | (0U << 26U)
                        | (0U << 27U)
                        | (0U << 28U)
                        | (0U << 29U)
                        | (0U << 30U)
                        | (0U << 31U);

    vimREG->REQMASKSET2 = 0U
                        | (0U << 1U)
                        | (0U << 2U)
                        | (0U << 3U)
                        | (0U << 4U)
                        | (0U << 5U)
                        | (0U << 6U)
                        | (0U << 7U)
                        | (0U << 8U)
                        | (0U << 9U)
                        | (0U << 10U)
                        | (0U << 11U)
                        | (0U << 12U)
                        | (0U << 13U)
                        | (0U << 14U)
                        | (0U << 15U)
                        | (0U << 16U)
                        | (0U << 17U)
                        | (0U << 18U)
                        | (0U << 19U)
                        | (0U << 20U)
                        | (0U << 21U)
                        | (0U << 22U)
                        | (0U << 23U)
                        | (0U << 24U)
                        | (0U << 25U);




/* USER CODE BEGIN (14) */
/* USER CODE END */

    /* configure muxed pins */
    muxInit();

/* USER CODE BEGIN (15) */
/* Initialize SCI driver */
    sciInit();
/* Initialize CAN driver */    
    canInit();
_disable_interrupt_();
/*
if(promt_question("Start EMAC/MDIO ? "))
   {
    if (macInit())
    {
      print_line("failure in network init");
    }
    else
    {
      print_line("Network Initialized");
    }
}
 _enable_interrupt_();   
 */   
    osInit();
/* USER CODE END */
	
    /* call the application */
    __cmain();
}


/* USER CODE BEGIN (16) */
/* USER CODE END */
