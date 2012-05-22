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

#include "sys_core.h"
/* Include HET header file - types, definitions and function declarations for system driver */
#include "het.h"
/* Include ESM header file - types, definitions and function declarations for system driver */
#include "esm.h"
/* Include GIO header file - types, definitions and function declarations for system driver */
#include "gio.h"
/* Include SCI header file - types, definitions and function declarations for system driver */
#include "sci.h"
/* Include ADC header file - types, definitions and function declarations for system driver */
#include "adc.h"
/* Include CAN header file - types, definitions and function declarations for system driver */
#include "can.h"
/* Include sci print header file - used to do io in the sci */
#include "sci_print.h"

#include "mac.h"
#include "can_protocol.h"
#include "debug.h"
/* USER CODE END */


/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
#define  D_SIZE 9
uint8_t  tx_data[D_SIZE]  = {'H','E','R','C','U','L','E','S','\0'};
uint8_t  rx_data[D_SIZE] = {0};
uint32_t error = 0;

/* USER CODE END */




uint8_t		emacAddress[6] 	= 	{0x1, 0x2, 0x3, 0x4, 0x5, 0x6};
uint32_t 	emacPhyAddress	=	1;

void main(void)
{
/* USER CODE BEGIN (3) */
     uint32_t ch_count=0;
    uint32_t id    =0;
    uint32_t value =0; 

  
/* Initialize HET driver */
 hetInit();
/* Initialize ESM driver */
esmInit();
/* Initialize GIO driver */
gioInit();
/* Initialize SCI driver */
sciInit();
/* Initialize CANdriver */
canInit();
/* Enable Notification for Push Button ( HDK ) */
gioEnableNotification(7);
/* Enable Global Interrupt int Cortex R4F */
_enable_interrupt_();
//_disable_interrupt_();
/* Disable LEDS */
hetREG1->DOUT = 0;

boot_message();


if (macInit())
{
  print_line("failure in network init");
}
else
{
  print_line("Network Initialized");
}

//wait till better buffer writing
//eth_dummy_send();

 
// canTransmit(canREG1, canMESSAGE_BOX1, "CAN MESSAGE"); 
can_protocol_send(canREG1,canMESSAGE_BOX1,"0123456789012345678901234567890123456789",44); 

/* Run forever */
while(1)
{
}
/* USER CODE END */
}


/* USER CODE BEGIN (4) */

/* Pwm interrupt notification (Not used but must be provided) */

void pwmNotification(hetBASE_t * hetREG, unsigned pwm, unsigned notification)
{
    return;
}

/* Edge interrupt notification (Not used but must be provided) */
void edgeNotification(hetBASE_t * hetREG, unsigned edge)
{
    return;
}

/* ESM Group notification (Not used but must be provided) */
void esmGroup1Notification(unsigned channel)
{
    return;
}

/* ESM Group2 notification (Not used but must be provided) */

void esmGroup2Notification(unsigned channel)
{
  
}
/* Gio notification (Not used but must be provided) */
void gioNotification(int bit)
{
   print("GIO interruption on the ");print_number(bit);print("st bit");   
   print_line("");
   hetREG1->DOUT = ~hetREG1->DOUT;
}





/* USER CODE END */
