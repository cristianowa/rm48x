/** @file mibadc.c 
*   @brief MIBADC Driver Source File
*   @date 04.October.2011
*   @version 1.02.000
*
*   This file contains:
*   - API Funcions
*   - Interrupt Handlers
*   .
*   which are relevant for the MIBADC driver.
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "mibadc.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */


/** @fn void mibadcInit(void)
*   @brief Initializes MIBADC Driver
*
*   This function initializes the MIBADC driver.
*
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

void mibadcInit(void)
{
/* USER CODE BEGIN (3) */
/* USER CODE END */



    /** @b Initialize @b MIBADC1: */

    /** - Reset MIBADC module */
    mibadcREG1->RSTCR = 1U;
    mibadcREG1->RSTCR = 0U;
 
    /** - Setup prescaler */
    mibadcREG1->CLOCKCR = 7U;
 
    /** - Setup memory boundaries */
    mibadcREG1->BNDCR  = 8U << 16U | 8U;
    mibadcREG1->BNDEND = 2U;
 
    /** - Setup event group conversion mode
	*     - Setup data format
    *     - Enable/Disable channel id in conversion result
    *     - Enable/Disable continuous conversion
	*/
    mibadcREG1->GxMODECR[0U] = MIBADC_12_BIT
                          | 0x00000000U
                          | 0x00000000U;

    /** - Setup event group hardware trigger
	*     - Setup hardware trigger edge
    *     - Setup hardware trigger source
	*/
    mibadcREG1->G0SRC = 0x00000000U
                   | MIBADC1_EVENT;

    /** - Setup event group sample window */
    mibadcREG1->G0SAMP = 0U;

    /** - Setup event group sample discharge 
    *     - Setup discharge prescaler
    *     - Enable/Disable discharge
    */
    mibadcREG1->G0SAMPDISEN = 0U << 8U
                         | 0x00000000U;

    /** - Setup group 1 conversion mode
	*     - Setup data format
    *     - Enable/Disable channel id in conversion result
    *     - Enable/Disable continuous conversion
	*/
    mibadcREG1->GxMODECR[1U] = MIBADC_12_BIT
                          | 0x00000000U
                          | 0x00000000U
                          | 0x00000000U;

    /** - Setup group 1 hardware trigger
	*     - Setup hardware trigger edge
    *     - Setup hardware trigger source
	*/
    mibadcREG1->G1SRC = 0x00000000U
                   | MIBADC1_EVENT;

    /** - Setup group 1 sample window */
    mibadcREG1->G1SAMP = 0U;

    /** - Setup group 1 sample discharge 
    *     - Setup discharge prescaler
    *     - Enable/Disable discharge
    */
    mibadcREG1->G1SAMPDISEN = 0U << 8U
                         | 0x00000000U;

    /** - Setup group 2 conversion mode
	*     - Setup data format
    *     - Enable/Disable channel id in conversion result
    *     - Enable/Disable continuous conversion
	*/
    mibadcREG1->GxMODECR[2U] = MIBADC_12_BIT
                          | 0x00000000U
                          | 0x00000000U
                          | 0x00000000U;

    /** - Setup group 2 hardware trigger
	*     - Setup hardware trigger edge
    *     - Setup hardware trigger source
	*/
    mibadcREG1->G2SRC = 0x00000000U
                   | MIBADC1_EVENT;

    /** - Setup group 2 sample window */
    mibadcREG1->G2SAMP = 0U;

    /** - Setup group 2 sample discharge 
    *     - Setup discharge prescaler
    *     - Enable/Disable discharge
    */
    mibadcREG1->G2SAMPDISEN = 0U << 8U
                         | 0x00000000U;

    /** - Enable MIBADC module */
    mibadcREG1->OPMODECR = 0x00140001U;

    /** - Wait for buffer inialisation complete */
    while ((mibadcREG1->BUFINIT) != 0) { /* Wait */ } 
    
    /** - Setup parity */
    mibadcREG1->PARCR = 0x0000000AU;



    /** @b Initialize @b MIBADC2: */

    /** - Reset MIBADC module */
    mibadcREG2->RSTCR = 1U;
    mibadcREG2->RSTCR = 0U;
 
    /** - Setup prescaler */
    mibadcREG2->CLOCKCR = 7U;
 
    /** - Setup memory boundaries */
    mibadcREG2->BNDCR  = 8U << 16U | 8U;
    mibadcREG2->BNDEND = 2U;
 
    /** - Setup event group conversion mode
	*     - Setup data format
    *     - Enable/Disable channel id in conversion result
    *     - Enable/Disable continuous conversion
	*/
    mibadcREG2->GxMODECR[0U] = MIBADC_12_BIT
                          | 0x00000000U
                          | 0x00000000U;

    /** - Setup event group hardware trigger
	*     - Setup hardware trigger edge
    *     - Setup hardware trigger source
	*/
    mibadcREG2->G0SRC = 0x00000000U
                   | MIBADC1_EVENT;

    /** - Setup event group sample window */
    mibadcREG2->G0SAMP = 0U;

    /** - Setup event group sample discharge 
    *     - Setup discharge prescaler
    *     - Enable/Disable discharge
    */
    mibadcREG2->G0SAMPDISEN = 0U << 8U
                         | 0x00000000U;

    /** - Setup group 1 conversion mode
	*     - Setup data format
    *     - Enable/Disable channel id in conversion result
    *     - Enable/Disable continuous conversion
	*/
    mibadcREG2->GxMODECR[1U] = MIBADC_12_BIT
                          | 0x00000000U
                          | 0x00000000U
                          | 0x00000000U;

    /** - Setup group 1 hardware trigger
	*     - Setup hardware trigger edge
    *     - Setup hardware trigger source
	*/
    mibadcREG2->G1SRC = 0x00000000U
                   | MIBADC1_EVENT;

    /** - Setup group 1 sample window */
    mibadcREG2->G1SAMP = 0U;

    /** - Setup group 1 sample discharge 
    *     - Setup discharge prescaler
    *     - Enable/Disable discharge
    */
    mibadcREG2->G1SAMPDISEN = 0U << 8U
                         | 0x00000000U;

    /** - Setup group 2 conversion mode
	*     - Setup data format
    *     - Enable/Disable channel id in conversion result
    *     - Enable/Disable continuous conversion
	*/
    mibadcREG2->GxMODECR[2U] = MIBADC_12_BIT
                          | 0x00000000U
                          | 0x00000000U
                          | 0x00000000U;

    /** - Setup group 2 hardware trigger
	*     - Setup hardware trigger edge
    *     - Setup hardware trigger source
	*/
    mibadcREG2->G2SRC = 0x00000000U
                   | MIBADC1_EVENT;

    /** - Setup group 2 sample window */
    mibadcREG2->G2SAMP = 0U;

    /** - Setup group 2 sample discharge 
    *     - Setup discharge prescaler
    *     - Enable/Disable discharge
    */
    mibadcREG2->G2SAMPDISEN = 0U << 8U
                         | 0x00000000U;

    /** - Enable MIBADC module */
    mibadcREG2->OPMODECR = 0x00140001U;

    /** - Wait for buffer inialisation complete */
    while ((mibadcREG2->BUFINIT) != 0) { /* Wait */ } 
    
    /** - Setup parity */
    mibadcREG2->PARCR = 0x00000005U;

    /**   @note This function has to be called before the driver can be used.\n
    *           This function has to be executed in priviledged mode.\n
    */
/* USER CODE BEGIN (4) */
/* USER CODE END */
}

/* USER CODE BEGIN (5) */
/* USER CODE END */


/** @fn void mibadcStartConversion(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Starts an MIBADC conversion
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*
*   This function starts a convesion of the MIBADC hardware group.
*
*/

/** - s_adcSelect is used as constant table for channel selection */
static const uint32_t s_adcSelect[2U][3U] =
{
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U,
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U,
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U,
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U,
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U,
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
    0x00000000U |
	0x00000000U |
    0x00000000U,
};

/** - s_adcSelect is used as constant table for channel selection */
static const int s_adcFiFoSize[2U][3U] =
{
    16U,
    16U,
    16U,
    16U,
    16U,
    16U,
};

/* USER CODE BEGIN (6) */
/* USER CODE END */

void mibadcStartConversion(mibadcBASE_t *mibadc, uint32_t group)
{
    uint32_t index = mibadc == mibadcREG1 ? 0U : 1U;

/* USER CODE BEGIN (7) */
/* USER CODE END */

    /** - Setup FiFo size */
    mibadc->GxINTCR[group] = s_adcFiFoSize[index][group];

    /** - Start Conversion */
    mibadc->GxSEL[group] = s_adcSelect[index][group];

    /**   @note The function mibadcInit has to be called before this function can be used. */

/* USER CODE BEGIN (8) */
/* USER CODE END */
}

/* USER CODE BEGIN (9) */
/* USER CODE END */


/** @fn void mibadcStopConversion(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Stops an MIBADC conversion
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*
*   This function stops a convesion of the MIBADC hardware group.
*
*/

/* USER CODE BEGIN (10) */
/* USER CODE END */

void mibadcStopConversion(mibadcBASE_t *mibadc, uint32_t group)
{
/* USER CODE BEGIN (11) */
/* USER CODE END */

    /** - Stop Conversion */
    mibadc->GxSEL[group] = 0U;

    /**   @note The function mibadcInit has to be called before this function can be used. */

/* USER CODE BEGIN (12) */
/* USER CODE END */
}

/* USER CODE BEGIN (13) */
/* USER CODE END */


/** @fn void mibadcResetFiFo(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Resets FiFo read and write pointer.
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*
*   This function resets the FiFo read and write pointrs.
*
*/

/* USER CODE BEGIN (14) */
/* USER CODE END */

void mibadcResetFiFo(mibadcBASE_t *mibadc, uint32_t group)
{
/* USER CODE BEGIN (15) */
/* USER CODE END */

    /** - Reset FiFo */
    mibadc->GxFIFORESETCR[group] = 1U;

    /**   @note The function mibadcInit has to be called before this function can be used.\n
    *           the conversion should be stopped before calling this function. 
    */

/* USER CODE BEGIN (16) */
/* USER CODE END */
}

/* USER CODE BEGIN (17) */
/* USER CODE END */


/** @fn int mibadcGetData(mibadcBASE_t *mibadc, uint32_t group, mibadcData_t *data)
*   @brief Gets converted a MIBADC values
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*              - mibadcREG3: MIBADC3 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*   @param[out] data Pointer to store MIBADC converted data
*   @return The function will return the number of converted values copied into data buffer:
*
*   This function writes a MIBADC message into a MIBADC message box.
*
*/


/* USER CODE BEGIN (18) */
/* USER CODE END */

int mibadcGetData(mibadcBASE_t *mibadc, uint32_t group, mibadcData_t *data)
{
    int       i;
    uint32_t  buf;
    uint32_t  index = mibadc == mibadcREG1 ? 0U : 1U;
    int       count = mibadc->GxINTCR[group] >= 256U ? s_adcFiFoSize[index][group] : s_adcFiFoSize[index][group] - (int)(mibadc->GxINTCR[group] & 0xFF);
    mibadcData_t *ptr = data; 

/* USER CODE BEGIN (19) */
/* USER CODE END */

    /** -  Get conversion data and channel/pin id */
    for (i = 0; i < count; i++)
    {
        buf        = mibadc->GxBUF[group].BUF0;
        ptr->value = (uint16_t)(buf & 0xFFFU);
        ptr->id    = (int)((buf >> 16U) & 0x1FU);
        ptr++;
    }

    mibadc->GxINTFLG[group] = 9U;

    /**   @note The function mibadcInit has to be called before this function can be used.\n
    *           The user is responsible to initialize the message box.
    */

/* USER CODE BEGIN (20) */
/* USER CODE END */

    return count;
}

/* USER CODE BEGIN (21) */
/* USER CODE END */


/** @fn int mibadcIsFifoFull(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Checks if FiFo buffer is full
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*              - mibadcREG3: MIBADC3 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*   @return The function will return:
*           - 0: When FiFo buffer is not full   
*           - 1: When FiFo buffer is full   
*           - 3: When FiFo buffer overflow occured    
*
*   This function checks FiFo buffer status.
*
*/


/* USER CODE BEGIN (22) */
/* USER CODE END */

int mibadcIsFifoFull(mibadcBASE_t *mibadc, uint32_t group)
{
    int flags;

/* USER CODE BEGIN (23) */
/* USER CODE END */

    /** - Read FiFo flags */
    flags = mibadc->GxINTFLG[group] & 3U;

    /**   @note The function mibadcInit has to be called before this function can be used. */

/* USER CODE BEGIN (24) */
/* USER CODE END */

    return flags;
}

/* USER CODE BEGIN (25) */
/* USER CODE END */


/** @fn int mibadcIsConversionComplete(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Checks if Conversion is complete
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*              - mibadcREG3: MIBADC3 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*   @return The function will return:
*           - 0: When is not finished   
*           - 8: When conversion is complete   
*
*   This function checks if conversion is complete.
*
*/


/* USER CODE BEGIN (26) */
/* USER CODE END */

int mibadcIsConversionComplete(mibadcBASE_t *mibadc, uint32_t group)
{
    int flags;

/* USER CODE BEGIN (27) */
/* USER CODE END */

    /** - Read conversion flags */
    flags = mibadc->GxINTFLG[group] & 8U;

    /**   @note The function mibadcInit has to be called before this function can be used. */

/* USER CODE BEGIN (28) */
/* USER CODE END */

    return flags;
}

/* USER CODE BEGIN (29) */
/* USER CODE END */


/** @fn void mibadcEnableNotification(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Enable notification
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*              - mibadcREG3: MIBADC3 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*
*   This function will enable the notification of a conversion.
*   In single conversion mode for conversion complete and
*   in continuous conversion mode when the FiFo buffer is full.
*
*/

/* USER CODE BEGIN (30) */
/* USER CODE END */

void mibadcEnableNotification(mibadcBASE_t *mibadc, uint32_t group)
{
    uint32_t notif = mibadc->GxMODECR[group] & 2U ? 1U : 8U;

/* USER CODE BEGIN (31) */
/* USER CODE END */

    mibadc->GxINTENA[group] = notif;

    /**   @note The function mibadcInit has to be called before this function can be used.\n
    *           This function should be called before the conversion is started
    */

/* USER CODE BEGIN (32) */
/* USER CODE END */
}

/* USER CODE BEGIN (33) */
/* USER CODE END */


/** @fn void mibadcDisableNotification(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Disable notification
*   @param[in] mibadc Pointer to MIBADC module:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*              - mibadcREG3: MIBADC3 module pointer
*   @param[in] group Hardware group of MIBADC module:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*
*   This function will disable the notification of a conversion.
*/

/* USER CODE BEGIN (34) */
/* USER CODE END */

void mibadcDisableNotification(mibadcBASE_t *mibadc, uint32_t group)
{
/* USER CODE BEGIN (35) */
/* USER CODE END */

    mibadc->GxINTENA[group] = 0U;

    /**   @note The function mibadcInit has to be called before this function can be used. */

/* USER CODE BEGIN (36) */
/* USER CODE END */
}

/* USER CODE BEGIN (37) */
/* USER CODE END */


/** @fn void mibadc1Group0Interrupt(void)
*   @brief MIBADC1 Event Group Interrupt Handler
*/

/* USER CODE BEGIN (38) */
/* USER CODE END */

#pragma INTERRUPT(mibadc1Group0Interrupt, IRQ)

void mibadc1Group0Interrupt(void)
{
/* USER CODE BEGIN (39) */
/* USER CODE END */
    
    mibadcREG1->GxINTFLG[0U] = 9U;

    mibadcNotification(mibadcREG1, mibadcGROUP0);

/* USER CODE BEGIN (40) */
/* USER CODE END */
}

/* USER CODE BEGIN (41) */
/* USER CODE END */


/** @fn void mibadc1Group1Interrupt(void)
*   @brief MIBADC1 Group 1 Interrupt Handler
*/

/* USER CODE BEGIN (42) */
/* USER CODE END */

#pragma INTERRUPT(mibadc1Group1Interrupt, IRQ)

void mibadc1Group1Interrupt(void)
{
/* USER CODE BEGIN (43) */
/* USER CODE END */
    
    mibadcREG1->GxINTFLG[1U] = 9U;

    mibadcNotification(mibadcREG1, mibadcGROUP1);

/* USER CODE BEGIN (44) */
/* USER CODE END */
}

/* USER CODE BEGIN (45) */
/* USER CODE END */


/** @fn void mibadc1Group2Interrupt(void)
*   @brief MIBADC1 Group 2 Interrupt Handler
*/

/* USER CODE BEGIN (46) */
/* USER CODE END */

#pragma INTERRUPT(mibadc1Group2Interrupt, IRQ)

void mibadc1Group2Interrupt(void)
{
/* USER CODE BEGIN (47) */
/* USER CODE END */
    
    mibadcREG1->GxINTFLG[2U] = 9U;

    mibadcNotification(mibadcREG1, mibadcGROUP2);

/* USER CODE BEGIN (48) */
/* USER CODE END */
}

/* USER CODE BEGIN (49) */
/* USER CODE END */


/** @fn void adc2Group0Interrupt(void)
*   @brief MIBADC2 Event Group Interrupt Handler
*/

/* USER CODE BEGIN (50) */
/* USER CODE END */

#pragma INTERRUPT(adc2Group0Interrupt, IRQ)

void adc2Group0Interrupt(void)
{
/* USER CODE BEGIN (51) */
/* USER CODE END */
    
    mibadcREG2->GxINTFLG[0U] = 9U;

    mibadcNotification(mibadcREG2, mibadcGROUP0);

/* USER CODE BEGIN (52) */
/* USER CODE END */
}

/* USER CODE BEGIN (53) */
/* USER CODE END */


/** @fn void adc2Group1Interrupt(void)
*   @brief MIBADC2 Group 1 Interrupt Handler
*/

/* USER CODE BEGIN (54) */
/* USER CODE END */

#pragma INTERRUPT(adc2Group1Interrupt, IRQ)

void adc2Group1Interrupt(void)
{
/* USER CODE BEGIN (55) */
/* USER CODE END */
    
    mibadcREG2->GxINTFLG[1U] = 9U;

    mibadcNotification(mibadcREG2, mibadcGROUP1);

/* USER CODE BEGIN (56) */
/* USER CODE END */
}

/* USER CODE BEGIN (57) */
/* USER CODE END */


/** @fn void mibadc2Group2Interrupt(void)
*   @brief MIBADC2 Group 2 Interrupt Handler
*/

/* USER CODE BEGIN (58) */
/* USER CODE END */

#pragma INTERRUPT(mibadc2Group2Interrupt, IRQ)

void mibadc2Group2Interrupt(void)
{
/* USER CODE BEGIN (59) */
/* USER CODE END */
    
    mibadcREG2->GxINTFLG[2U] = 9U;

    mibadcNotification(mibadcREG2, mibadcGROUP2);

/* USER CODE BEGIN (60) */
/* USER CODE END */
}

/* USER CODE BEGIN (61) */
/* USER CODE END */
