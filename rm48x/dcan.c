/** @file dcan.c 
*   @brief DCAN Driver Source File
*   @date 04.October.2011
*   @version 1.02.000
*
*   This file contains:
*   - API Funcions
*   - Interrupt Handlers
*   .
*   which are relevant for the DCAN driver.
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* Include Files */

#include "dcan.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */


/* Global and Static Variables */

#ifndef __little_endian__
    static const uint32_t s_dcanByteOrder[] = {3U, 2U, 1U, 0U, 7U, 6U, 5U, 4U};
#endif

/* USER CODE BEGIN (2) */
/* USER CODE END */


/** @fn void dcanInit(void)
*   @brief Initializes DCAN Driver
*
*   This function initializes the DCAN driver.
*
*/

/* USER CODE BEGIN (3) */
/* USER CODE END */

void dcanInit(void)
{
/* USER CODE BEGIN (4) */
/* USER CODE END */



    /** @b Initialize @b DCAN1: */

    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Disable parity and ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrups
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    dcanREG1->CTL = 0x00000000U | 0x00000000U | 0x00021443U;

    /** - Clear all pending error flags and reset current status */
    dcanREG1->ES = 0x0000031FU;

    /** - Assign interrupt level for messages */
    dcanREG1->INTMUXx[0U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;

    dcanREG1->INTMUXx[1U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;

    /** - Setup auto bus on timer pewriod */
    dcanREG1->ABOTR = 0U;

    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 ) 
    {  
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((1U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 1;

    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
     {
     }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((2U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 2;

    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
     }
    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((3U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 3;

    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((4U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 4;

    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((5U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 5;

    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((6U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 6;

    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((7U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 7;

    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((8U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 8;

    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((9U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 9;

    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((10U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 10;

    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((11U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 11;

    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((12U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 12;

    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((13U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 13;

    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((14U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 14;

    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
     }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((15U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 15;

    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((16U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 16;

    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((17U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 17;

    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((18U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 18;

    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((19U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 19;

    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((20U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 20;

    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((21U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 21;

    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((22U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 22;

    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }


    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((23U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 23;

    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((24U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 24;

    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((25U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 25;

    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((26U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 26;

    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((27U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 27;

    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((28U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 28;

    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((29U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 29;

    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((30U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 30;

    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((31U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 31;

    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((32U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 32;

    /** - Initialize message 33 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((33U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 33;

    /** - Initialize message 34 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((34U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 34;

    /** - Initialize message 35 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((35U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 35;

    /** - Initialize message 36 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((36U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 36;

    /** - Initialize message 37 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((37U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 37;

    /** - Initialize message 38 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((38U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 38;

    /** - Initialize message 39 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((39U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 39;

    /** - Initialize message 40 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((40U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 40;

    /** - Initialize message 41 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((41U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 41;

    /** - Initialize message 42 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((42U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 42;

    /** - Initialize message 43 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((43U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 43;

    /** - Initialize message 44 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((44U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 44;

    /** - Initialize message 45 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((45U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 45;

    /** - Initialize message 46 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((46U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 46;

    /** - Initialize message 47 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((47U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 47;

    /** - Initialize message 48 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((48U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 48;

    /** - Initialize message 49 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((49U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 49;

    /** - Initialize message 50 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((50U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 50;

    /** - Initialize message 51 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((51U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 51;

    /** - Initialize message 52 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((52U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 52;

    /** - Initialize message 53 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((53U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 53;

    /** - Initialize message 54 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((54U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 54;

    /** - Initialize message 55 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((55U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 55;

    /** - Initialize message 56 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((56U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 56;

    /** - Initialize message 57 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((57U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 57;

    /** - Initialize message 58 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((58U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 58;

    /** - Initialize message 59 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((59U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 59;

    /** - Initialize message 60 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((60U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 60;

    /** - Initialize message 61 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((61U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 61;

    /** - Initialize message 62 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((62U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 62;

    /** - Initialize message 63 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((63U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF1CMD  = 0xF8;
    dcanREG1->IF1NO   = 63;

    /** - Initialize message 64 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((64U & 0x1FFFFFFFU) << 0U);
    dcanREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG1->IF2CMD  = 0xF8;
    dcanREG1->IF2NO   = 64;

    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF1CMD  = 0x87;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while ( (dcanREG1->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG1->IF2CMD = 0x17;

    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    dcanREG1->BTR = (0U << 16U) |
                   ((2U - 1U) << 12U) |
                   (((3U + 2U) - 1U) << 8U) |
                   ((2U - 1U) << 6U) |
                   19U;

     /** - DCAN1 Port output values */
    dcanREG1->TIOC = (1  << 18 )
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (1  << 2 )    
                   | (0 << 1 )  
                   | (0  );     
    dcanREG1->RIOC = (1  << 18 )    
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (0  << 2 )
                   | (0 <<1 )  
                   | (0  );        

    /** - Leave configuration and initialization mode  */
    dcanREG1->CTL &= ~0x00000041U;






    /** @b Initialize @b DCAN2: */

    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Disable parity and ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrups
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    dcanREG2->CTL = 0x00000000U | 0x00000000U | 0x00021443U;

    /** - Clear all pending error flags and reset current status */
    dcanREG2->ES = 0x0000031FU;

    /** - Assign interrupt level for messages */
    dcanREG2->INTMUXx[0U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;

    dcanREG2->INTMUXx[1U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;


    /** - Setup auto bus on timer pewriod */
    dcanREG2->ABOTR = 0U;

    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((1U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 1;

    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((2U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 2;

    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((3U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 3;

    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((4U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 4;

    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((5U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 5;

    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((6U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 6;

    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((7U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 7;

    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((8U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 8;

    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((9U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 9;

    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((10U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 10;

    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((11U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 11;

    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((12U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 12;

    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((13U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 13;

    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((14U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 14;

    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((15U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 15;

    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((16U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 16;

    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((17U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 17;

    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((18U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 18;

    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((19U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 19;

    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((20U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 20;

    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((21U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 21;

    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((22U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 22;

    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((23U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 23;

    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((24U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 24;

    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((25U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 25;

    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((26U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 26;

    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((27U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 27;

    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((28U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 28;

    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((29U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 29;

    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((30U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 30;

    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((31U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 31;

    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((32U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 32;

    /** - Initialize message 33 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((33U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 33;

    /** - Initialize message 34 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((34U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 34;

    /** - Initialize message 35 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((35U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 35;

    /** - Initialize message 36 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((36U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 36;

    /** - Initialize message 37 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((37U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 37;

    /** - Initialize message 38 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((38U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 38;

    /** - Initialize message 39 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((39U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 39;

    /** - Initialize message 40 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((40U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 40;

    /** - Initialize message 41 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
    {
    }

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((41U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 41;

    /** - Initialize message 42 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
	{
	}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((42U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 42;

    /** - Initialize message 43 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((43U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 43;

    /** - Initialize message 44 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((44U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 44;

    /** - Initialize message 45 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((45U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 45;

    /** - Initialize message 46 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((46U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 46;

    /** - Initialize message 47 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((47U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 47;

    /** - Initialize message 48 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((48U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 48;

    /** - Initialize message 49 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((49U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 49;

    /** - Initialize message 50 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((50U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 50;

    /** - Initialize message 51 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((51U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 51;

    /** - Initialize message 52 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((52U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 52;

    /** - Initialize message 53 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((53U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 53;

    /** - Initialize message 54 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((54U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 54;

    /** - Initialize message 55 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((55U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 55;

    /** - Initialize message 56 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((56U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 56;

    /** - Initialize message 57 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((57U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 57;

    /** - Initialize message 58 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((58U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 58;

    /** - Initialize message 59 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((59U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 59;

    /** - Initialize message 60 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((60U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 60;

    /** - Initialize message 61 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((61U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 61;

    /** - Initialize message 62 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((62U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 62;

    /** - Initialize message 63 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((63U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF1CMD  = 0xF8;
    dcanREG2->IF1NO   = 63;

    /** - Initialize message 64 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((64U & 0x1FFFFFFFU) << 0U);
    dcanREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG2->IF2CMD  = 0xF8;
    dcanREG2->IF2NO   = 64;

    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1CMD  = 0x87;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while ( (dcanREG2->IF2STAT & 0x80) == 1 )
{
}

    dcanREG2->IF2CMD = 0x17;

    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    dcanREG2->BTR = (0U << 16U) |
                   ((2U - 1U) << 12U) |
                   (((3U + 2U) - 1U) << 8U) |
                   ((2U - 1U) << 6U) |
                   19U;

   /** - DCAN2 Port output values */
    dcanREG2->TIOC = (1  << 18 )
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (1  << 2 )    
                   | (0 << 1 )  
                   | (0  );     
    dcanREG2->RIOC = (1  << 18 )    
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (0  << 2 )
                   | (0 <<1 )  
                   | (0  );       

    /** - Leave configuration and initialization mode  */
    dcanREG2->CTL &= ~0x00000041U;




    /** @b Initialize @b DCAN3: */

    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Disable parity and ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrups
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    dcanREG3->CTL = 0x00000000U | 0x00000000U | 0x00021443U;

    /** - Clear all pending error flags and reset current status */
    dcanREG3->ES = 0x0000031FU;

    /** - Assign interrupt level for messages */
    dcanREG3->INTMUXx[0U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;

    /** - Setup auto bus on timer pewriod */
    dcanREG3->ABOTR = 0U;

    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((1U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 1;

    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((2U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 2;

    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((3U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 3;

    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((4U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 4;

    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((5U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 5;

    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((6U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 6;

    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((7U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 7;

    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((8U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 8;

    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((9U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 9;

    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((10U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 10;

    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((11U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 11;

    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((12U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 12;

    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((13U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 13;

    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((14U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 14;

    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((15U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 15;

    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((16U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 16;

    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((17U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 17;

    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((18U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 18;

    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((19U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 19;

    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((20U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 20;

    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((21U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 21;

    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((22U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 22;

    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((23U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 23;

    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((24U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 24;

    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((25U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 25;

    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((26U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 26;

    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((27U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 27;

    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((28U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 28;

    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((29U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 29;

    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((30U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 30;

    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((31U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF1CMD  = 0xF8;
    dcanREG3->IF1NO   = 31;

    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((32U & 0x1FFFFFFFU) << 0U);
    dcanREG3->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    dcanREG3->IF2CMD  = 0xF8;
    dcanREG3->IF2NO   = 32;

    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1CMD  = 0x87;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while ( (dcanREG3->IF2STAT & 0x80) == 1 )
{
}

    dcanREG3->IF2CMD = 0x17;

    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    dcanREG3->BTR = (0U << 16U) |
                   ((2U - 1U) << 12U) |
                   (((3U + 2U) - 1U) << 8U) |
                   ((2U - 1U) << 6U) |
                   19U;

   
    /** - DCAN3 Port output values */
    dcanREG3->TIOC = (1  << 18 )
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (1  << 2 )    
                   | (0 << 1 )  
                   | (0  );     
    dcanREG3->RIOC = (1  << 18 )    
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (0  << 2 )
                   | (0 <<1 )  
                   | (0  );       

    /** - Leave configuration and initialization mode  */
    dcanREG3->CTL &= ~0x00000041U;

    /**   @note This function has to be called before the driver dcan be used.\n
    *           This function has to be executed in priviledged mode.\n
    */

/* USER CODE BEGIN (5) */
/* USER CODE END */
}



/** @fn uint32_t dcanTransmit(dcanBASE_t *node, uint32_t messageBox, const uint8_t *data)
*   @brief Transmits a DCAN message
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] messageBox Message box number of DCAN node:
*              - dcanMESSAGE_BOX1: DCAN message box 1
*              - dcanMESSAGE_BOXn: DCAN message box n [n: 1-64]
*              - dcanMESSAGE_BOX64: DCAN message box 64
*   @param[in] data Pointer to DCAN TX data
*   @return The function will return:
*           - 0: When the setup of the TX message box wasn't successful   
*           - 1: When the setup of the TX message box was successful   
*
*   This function writes a DCAN message into a DCAN message box.
*
*/

/* USER CODE BEGIN (6) */
/* USER CODE END */

uint32_t dcanTransmit(dcanBASE_t *node, uint32_t messageBox, const uint8_t *data)
{
    uint32_t i;
    uint32_t success  = 0U;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (7) */
/* USER CODE END */

    /** - Check for pending message:
    *     - pending message, return 0
    *     - no pending message, start new transmission 
    */
    if ((node->TXRQx[regIndex] & bitIndex) != 0)
    {
        return success;
    }

    /** - Wait until IF1 is ready for use */
    while ( (node->IF1STAT & 0x80) == 1 )
{
}

    /** - Copy TX data into IF1 */
    for (i = 0U; i < 8U; i++)
    {
#ifdef __little_endian__
        node->IF1DATx[i] = *data++;
#else
        node->IF1DATx[s_dcanByteOrder[i]] = *data++;
#endif
    }

    /** - Copy TX data into mesasge box */
    node->IF1NO = messageBox;

    success = 1U; 

    /**   @note The function dcanInit has to be called before this function dcan be used.\n
    *           The user is responsible to initialize the message box.
    */

/* USER CODE BEGIN (8) */
/* USER CODE END */

    return success;
}


/** @fn uint32_t dcanGetData(dcanBASE_t *node, uint32_t messageBox, uint8_t * const data)
*   @brief Gets received a DCAN message
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] messageBox Message box number of DCAN node:
*              - dcanMESSAGE_BOX1: DCAN message box 1
*              - dcanMESSAGE_BOXn: DCAN message box n [n: 1-64]
*              - dcanMESSAGE_BOX64: DCAN message box 64
*   @param[out] data Pointer to store DCAN RX data
*   @return The function will return:
*           - 0: When RX message box hasn't received new data   
*           - 1: When RX data are stored in the data buffer   
*           - 3: When RX data are stored in the data buffer and a message was lost   
*
*   This function writes a DCAN message into a DCAN message box.
*
*/


/* USER CODE BEGIN (9) */
/* USER CODE END */

uint32_t dcanGetData(dcanBASE_t *node, uint32_t messageBox, uint8_t * const data)
{
    uint32_t       i;
    uint32_t       size;
    uint8_t *pData    = (uint8_t *)data;
    uint32_t       success  = 0U;
    uint32_t       regIndex = (messageBox - 1U) >> 5U;
    uint32_t       bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (10) */
/* USER CODE END */

    /** - Check if new data have been arrived:
    *     - no new data, return 0
    *     - new data, get received message 
    */
    if (!(node->NWDATx[regIndex] & bitIndex))
    {
        return success;
    }

    /** - Wait until IF2 is ready for use */
    while ( (node->IF2STAT & 0x80) == 1 )
{
}

    /** - Copy data into IF2 */
    node->IF2NO = messageBox;

    /** - Wait until data are copied into IF2 */
    while ( (node->IF2STAT & 0x80) == 1 ){}

    /** - Get number of received bytes */
    size = node->IF2MCTL & 0xFU;

    /** - Copy RX data into destination buffer */
    for (i = 0U; i < size; i++)
    {
#ifdef __little_endian__
        *pData++ = node->IF2DATx[i];
#else
        *pData++ = node->IF2DATx[s_dcanByteOrder[i]];
#endif
    }

    success = 1U;

    /** - Check if data have been lost:
    *     - no data lost, return 1
    *     - data lost, return 3 
    */
    if ((node->IF2MCTL & 0x4000U) != 0 )
    {
        success = 3U;
    }

    /**   @note The function dcanInit has to be called before this function dcan be used.\n
    *           The user is responsible to initialize the message box.
    */

/* USER CODE BEGIN (11) */
/* USER CODE END */

    return success;
}


/** @fn uint32_t dcanIsTxMessagePending(dcanBASE_t *node, uint32_t messageBox)
*   @brief Gets Tx message box transmission status
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] messageBox Message box number of DCAN node:
*              - dcanMESSAGE_BOX1: DCAN message box 1
*              - dcanMESSAGE_BOXn: DCAN message box n [n: 1-64]
*              - dcanMESSAGE_BOX64: DCAN message box 64
*   @return The function will return the tx request flag
*
*   Checks to see if the Tx message box has a pending Tx request, returns
*   0 is flag not set otherwise will return the Tx request flag itself.
*/


/* USER CODE BEGIN (12) */
/* USER CODE END */

uint32_t dcanIsTxMessagePending(dcanBASE_t *node, uint32_t messageBox)
{
    uint32_t flag;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (13) */
/* USER CODE END */

    /** - Read Tx request reigster */
    flag = node->TXRQx[regIndex] & bitIndex;

/* USER CODE BEGIN (14) */
/* USER CODE END */

    return flag;
}


/** @fn uint32_t dcanIsRxMessageArrived(dcanBASE_t *node, uint32_t messageBox)
*   @brief Gets Rx message box reception status
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] messageBox Message box number of DCAN node:
*              - dcanMESSAGE_BOX1: DCAN message box 1
*              - dcanMESSAGE_BOXn: DCAN message box n [n: 1-64]
*              - dcanMESSAGE_BOX64: DCAN message box 64
*   @return The function will return the new data flag
*
*   Checks to see if the Rx message box has pending Rx data, returns
*   0 is flag not set otherwise will return the Tx request flag itself.
*/


/* USER CODE BEGIN (15) */
/* USER CODE END */

uint32_t dcanIsRxMessageArrived(dcanBASE_t *node, uint32_t messageBox)
{
    uint32_t flag;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (16) */
/* USER CODE END */

    /** - Read Tx request register */
    flag = node->NWDATx[regIndex] & bitIndex;

/* USER CODE BEGIN (17) */
/* USER CODE END */

    return flag;
}


/** @fn uint32_t dcanIsMessageBoxValid(dcanBASE_t *node, uint32_t messageBox)
*   @brief Chechs if message box is valid
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] messageBox Message box number of DCAN node:
*              - dcanMESSAGE_BOX1: DCAN message box 1
*              - dcanMESSAGE_BOXn: DCAN message box n [n: 1-64]
*              - dcanMESSAGE_BOX64: DCAN message box 64
*   @return The function will return the new data flag
*
*   Checks to see if the message box is valid for operation, returns
*   0 is flag not set otherwise will return the validation flag itself.
*/


/* USER CODE BEGIN (18) */
/* USER CODE END */

uint32_t dcanIsMessageBoxValid(dcanBASE_t *node, uint32_t messageBox)
{
    uint32_t flag;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (19) */
/* USER CODE END */

    /** - Read Tx request register */
    flag = node->MSGVALx[regIndex] & bitIndex;

/* USER CODE BEGIN (20) */
/* USER CODE END */

    return flag;
}


/** @fn uint32_t dcanGetLastError(dcanBASE_t *node)
*   @brief Gets last RX/TX-Error of DCAN message traffic
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @return The function will return:
*           - dcanERROR_OK (0): When no DCAN error occured   
*           - dcanERROR_STUFF (1): When a stuff error occured on RX message    
*           - dcanERROR_FORMAT (2): When a form/format error occured on RX message   
*           - dcanERROR_ACKNOWLEDGE (3): When a TX message wasn't acknowledged  
*           - dcanERROR_BIT1 (4): When a TX message monitored dominant level where recessive is expected   
*           - dcanERROR_BIT0 (5): When a TX message monitored recessive level where dominant is expected   
*           - dcanERROR_CRC (6): When a RX message has wrong CRC value   
*           - dcanERROR_NO (7): When no error occured since last call of this function   
*
*   This function returns the last occured error code of an RX or TX message,
*   since the last call of this function.
*
*/


/* USER CODE BEGIN (21) */
/* USER CODE END */

uint32_t dcanGetLastError(dcanBASE_t *node)
{
    uint32_t errorCode;

/* USER CODE BEGIN (22) */
/* USER CODE END */

    /** - Get last error code */
    errorCode = node->ES & 7U;

    /**   @note The function dcanInit has to be called before this function dcan be used. */

/* USER CODE BEGIN (23) */
/* USER CODE END */

    return errorCode;
}


/** @fn uint32_t dcanGetErrorLevel(dcanBASE_t *node)
*   @brief Gets error level of a DCAN node
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @return The function will return:
*           - dcanLEVEL_ACTIVE (0x00): When RX- and TX error counters are below 96   
*           - dcanLEVEL_WARNING (0x40): When RX- or TX error counter are between 96 and 127     
*           - dcanLEVEL_PASSIVE (0x20): When RX- or TX error counter are between 128 and 255     
*           - dcanLEVEL_BUS_OFF (0x80): When RX- or TX error counter are above 255     
*
*   This function returns the current error level of a DCAN node.
*
*/


/* USER CODE BEGIN (24) */
/* USER CODE END */

uint32_t dcanGetErrorLevel(dcanBASE_t *node)
{
    uint32_t errorLevel;

/* USER CODE BEGIN (25) */
/* USER CODE END */

    /** - Get error level */
    errorLevel = node->ES & 0xE0U;

    /**   @note The function dcanInit has to be called before this function dcan be used. */

/* USER CODE BEGIN (26) */
/* USER CODE END */

    return errorLevel;
}


/** @fn void dcanEnableErrorNotification(dcanBASE_t *node)
*   @brief Enable error notification
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*
*   This function will enable the notification for the reaching the error levels warning, passive and bus off.
*/

/* USER CODE BEGIN (27) */
/* USER CODE END */

void dcanEnableErrorNotification(dcanBASE_t *node)
{
/* USER CODE BEGIN (28) */
/* USER CODE END */

    node->CTL |= 8U;

    /**   @note The function dcanInit has to be called before this function dcan be used. */

/* USER CODE BEGIN (29) */
/* USER CODE END */
}


/** @fn void dcanDisableErrorNotification(dcanBASE_t *node)
*   @brief Disable error notification
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*
*   This function will disable the notification for the reaching the error levels warning, passive and bus off.
*/

/* USER CODE BEGIN (30) */
/* USER CODE END */

void dcanDisableErrorNotification(dcanBASE_t *node)
{
/* USER CODE BEGIN (31) */
/* USER CODE END */

    node->CTL &= ~8U;

    /**   @note The function dcanInit has to be called before this function dcan be used. */

/* USER CODE BEGIN (32) */
/* USER CODE END */
}


/** @fn void dcan1HighLevelInterrupt(void)
*   @brief DCAN1 Level 0 Interrupt Handler
*/

/* USER CODE BEGIN (33) */
/* USER CODE END */

#pragma INTERRUPT(dcan1HighLevelInterrupt, IRQ)

void dcan1HighLevelInterrupt(void)
{
    uint32_t value = dcanREG1->INT;

/* USER CODE BEGIN (34) */
/* USER CODE END */

    if (value == 0x8000U)
    {
        dcanErrorNotification(dcanREG1, dcanREG1->ES & 0xE0U);
        return;
    }

    /** - Setup IF1 for clear pending interrupt flag */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
{
}

    dcanREG1->IF1CMD = 0x08;
    dcanREG1->IF1NO  = value;

    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
{
}

    dcanREG1->IF1CMD = 0x87;

    dcanMessageNotification(dcanREG1, value);

/* USER CODE BEGIN (35) */
/* USER CODE END */
}


/** @fn void dcan1LowLevelInterrupt(void)
*   @brief DCAN1 Level 1 Interrupt Handler
*/

/* USER CODE BEGIN (36) */
/* USER CODE END */

#pragma INTERRUPT(dcan1LowLevelInterrupt, IRQ)

void dcan1LowLevelInterrupt(void)
{
    uint32_t messageBox = dcanREG1->INT >> 16U;

/* USER CODE BEGIN (37) */
/* USER CODE END */

    /** - Setup IF1 for clear pending interrupt flag */
    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
{
}

    dcanREG1->IF1CMD = 0x08;
    dcanREG1->IF1NO  = messageBox;

    while ( (dcanREG1->IF1STAT & 0x80) == 1 )
{
}

    dcanREG1->IF1CMD = 0x87;

    dcanMessageNotification(dcanREG1, messageBox);

/* USER CODE BEGIN (38) */
/* USER CODE END */
}


/** @fn void dcan2HighLevelInterrupt(void)
*   @brief DCAN2 Level 0 Interrupt Handler
*/

/* USER CODE BEGIN (39) */
/* USER CODE END */

#pragma INTERRUPT(dcan2HighLevelInterrupt, IRQ)

void dcan2HighLevelInterrupt(void)
{
    uint32_t value = dcanREG2->INT;

/* USER CODE BEGIN (40) */
/* USER CODE END */

    if (value == 0x8000U)
    {
        dcanErrorNotification(dcanREG2, dcanREG2->ES & 0xE0U);
        return;
    }

    /** - Setup IF1 for clear pending interrupt flag */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1CMD = 0x08;
    dcanREG2->IF1NO  = value;

    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1CMD = 0x87;

    dcanMessageNotification(dcanREG2, value);

/* USER CODE BEGIN (41) */
/* USER CODE END */
}


/** @fn void dcan2LowLevelInterrupt(void)
*   @brief DCAN2 Level 1 Interrupt Handler
*/

/* USER CODE BEGIN (42) */
/* USER CODE END */

#pragma INTERRUPT(dcan2LowLevelInterrupt, IRQ)

void dcan2LowLevelInterrupt(void)
{
    uint32_t messageBox = dcanREG2->INT >> 16U;

/* USER CODE BEGIN (43) */
/* USER CODE END */

    /** - Setup IF1 for clear pending interrupt flag */
    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1CMD = 0x08;
    dcanREG2->IF1NO  = messageBox;

    while ( (dcanREG2->IF1STAT & 0x80) == 1 )
{
}

    dcanREG2->IF1CMD = 0x87;

    dcanMessageNotification(dcanREG2, messageBox);

/* USER CODE BEGIN (44) */
/* USER CODE END */
}


/** @fn void dcan3HighLevelInterrupt(void)
*   @brief DCAN3 Level 0 Interrupt Handler
*/

/* USER CODE BEGIN (45) */
/* USER CODE END */

#pragma INTERRUPT(dcan3HighLevelInterrupt, IRQ)

void dcan3HighLevelInterrupt(void)
{
    uint32_t value = dcanREG3->INT;

/* USER CODE BEGIN (46) */
/* USER CODE END */

    if (value == 0x8000U)
    {
        dcanErrorNotification(dcanREG3, dcanREG3->ES & 0xE0U);
        return;
    }

    /** - Setup IF1 for clear pending interrupt flag */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1CMD = 0x08;
    dcanREG3->IF1NO  = value;

    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1CMD = 0x87;

    dcanMessageNotification(dcanREG3, value);

/* USER CODE BEGIN (47) */
/* USER CODE END */
}


/** @fn void dcan3LowLevelInterrupt(void)
*   @brief DCAN3 Level 1 Interrupt Handler
*/

/* USER CODE BEGIN (48) */
/* USER CODE END */

#pragma INTERRUPT(dcan3LowLevelInterrupt, IRQ)

void dcan3LowLevelInterrupt(void)
{
    uint32_t messageBox = dcanREG3->INT >> 16U;

/* USER CODE BEGIN (49) */
/* USER CODE END */

    /** - Setup IF1 for clear pending interrupt flag */
    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1CMD = 0x08;
    dcanREG3->IF1NO  = messageBox;

    while ( (dcanREG3->IF1STAT & 0x80) == 1 )
{
}

    dcanREG3->IF1CMD = 0x87;

    dcanMessageNotification(dcanREG3, messageBox);

/* USER CODE BEGIN (50) */
/* USER CODE END */
}
