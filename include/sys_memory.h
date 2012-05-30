/** @file sys_memory.h
*   @brief System Memory Header File
*   @date 15.December.2011
*   @version 03.00.00
*   
*   This file contains:
*   - Memory Interface Functions
*   .
*   which are relevant for the System driver.
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */

#ifndef __SYS_MEMORY_H__
#define __SYS_MEMORY_H__

#include "sys_common.h"

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* System Memory Interface Functions */

/** @fn void _memoryTest_(void)
*   @brief Pbist hardware memory selftest
*/
void _memoryTest_(void);

/** @fn void _memoryInit_(void)
*   @brief Automatic hardware memory initialization
*/
void _memoryInit_(void);

/** @fn void memoryPort0TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data)
*   @brief Memory Port 0 test fail notification
*   @param[in] groupSelect Failing Ram group select:
*   @param[in] dataSelect Failing Ram data select:
*   @param[in] address Failing Ram offset:
*   @param[in] data Failing data at address:
*
*   @note This function has to be provide by the user.
*/
void memoryPort0TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data);

/** @fn void memoryPort1TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data)
*   @brief Memory Port 1 test fail notification
*   @param[in] groupSelect Failing Ram group select:
*   @param[in] dataSelect Failing Ram data select:
*   @param[in] address Failing Ram offset:
*   @param[in] data Failing data at address:
*
*   @note This function has to be provide by the user.
*/
void memoryPort1TestFailNotification(uint32_t groupSelect, uint32_t dataSelect, uint32_t address, uint32_t data);

/* EFUSE Selftest Functions */

/** @fn void _efuseSelfTest_(void)
*   @brief Efuse controller Selftest 
*/
void _efuseSelfTest_(void);


/* USER CODE BEGIN (1) */
/* USER CODE END */


#endif
