/** @file sys_main.c 
*   @brief Application main file
*   @date 15.December.2011
*   @version 03.00.00
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "sys_common.h"
#include "system.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */


/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* Include FreeRTOS scheduler files */
#include "FreeRTOS.h"
#include "os_task.h"

/* Include HET header file - types, definitions and function declarations for system driver */
#include "het.h"
#include "gio.h"
#include "esm.h"
#include "task1.h"


/* USER CODE END */




uint8_t		emacAddress[6] 	= 	{0x1, 0x2, 0x3, 0x4, 0x5, 0x6};
uint32_t 	emacPhyAddress	=	1;

void main(void)
{
/* USER CODE BEGIN (3) */
       
    /* Set high end timer GIO port hetPort pin direction to all output */
    gioSetDirection(hetPORT1, 0xFFFFFFFF);


    /* Create Task 1 */
    if (xTaskCreate(vTask1, (const signed char *)"Task1", configMINIMAL_STACK_SIZE, NULL, 1, &xTask1Handle) != pdTRUE)
    {
        /* Task could not be created */
        while(1);
    }

    /* Start Scheduler */
    vTaskStartScheduler();

    /* Run forever */
    while(1);
/* USER CODE END */
}


/* USER CODE BEGIN (4) */
/* ESM interrupt notification (Not used but must be provided) */
void esmGroup1Notification(unsigned channel){}
void esmGroup2Notification(unsigned channel){}

/* GIO interrupt notification (Not used but must be provided) */
void gioNotification(int bit)
{
    return;
}


/* USER CODE END */
