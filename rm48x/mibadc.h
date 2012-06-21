/** @file mibadc.h
*   @brief MIBADC Driver Header File
*   @date 04.October.2011
*   @version 1.02.000
*   
*   This file contains:
*   - Definitions
*   - Types
*   - Interface Prototypes
*   .
*   which are relevant for the MIBADC driver.
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */

#include "sys_common.h"

#ifndef __MIBADC_H__
#define __MIBADC_H__

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* MIBADC General Definitions */

/** @def mibadcGROUP0
*   @brief Alias name for MIBADC event group
*
*   @note This value should be used for API argument @a group
*/
#define mibadcGROUP0 0U

/** @def mibadcGROUP1
*   @brief Alias name for MIBADC group 1
*
*   @note This value should be used for API argument @a group
*/
#define mibadcGROUP1 1U

/** @def mibadcGROUP2
*   @brief Alias name for MIBADC group 2
*
*   @note This value should be used for API argument @a group
*/
#define mibadcGROUP2 2U

/** @enum mibadcResolution
*   @brief Alias names for data resolution
*   This enumeration is used to provide alias names for the data resolution:
*     - 12 bit resolution
*     - 10 bit resolution
*     - 8  bit resolution
*/

enum mibadcResolution
{
    MIBADC_12_BIT = 0x00000000, /**< Alias for 12 bit data resolution */
    MIBADC_10_BIT = 0x00000100, /**< Alias for 10 bit data resolution */
    MIBADC_8_BIT  = 0x00000200  /**< Alias for 8 bit data resolution  */
};

/** @enum mibadcFiFoStatus
*   @brief Alias names for FiFo status
*   This enumeration is used to provide alias names for the current FiFo states:
*     - FiFo is not full
*     - FiFo is full
*     - FiFo overflow occured
*/

enum mibadcFiFoStatus
{
    MIBADC_FIFO_IS_NOT_FULL = 0, /**< Alias for FiFo is not full       */
    MIBADC_FIFO_IS_FULL     = 1, /**< Alias for FiFo is full           */
    MIBADC_FIFO_OVERFLOW    = 3  /**< Alias for FiFo overflow occured  */
};

/** @enum mibadcConversionStatus
*   @brief Alias names for conversion status
*   This enumeration is used to provide alias names for the current conversion states:
*     - Conversion is not finished
*     - Conversion is finished
*/

enum mibadcConversionStatus
{
    MIBADC_CONVERSION_IS_NOT_FINISHED = 0, /**< Alias for current conversion is not finished */
    MIBADC_CONVERSION_IS_FINISHED     = 8  /**< Alias for current conversion is  finished    */
};

/** @enum mibadcHwTriggerSource
*   @brief Alias names for hardware trigger source
*   This enumeration is used to provide alias names for the hardware trigger sources:
*/

enum mibadc1HwTriggerSource
{
    MIBADC1_EVENT,         /**< Alias for event pin             */
    MIBADC1_NHET1_8,       /**< Alias for NHET1 pin 8           */
    MIBADC1_NHET1_10,      /**< Alias for NHET1 pin 10          */
    MIBADC1_RTI_COMP0,     /**< Alias for RTI compare 0 match   */
    MIBADC1_NHET1_12,      /**< Alias for NHET1 pin 12          */
    MIBADC1_NHET1_14,      /**< Alias for NHET1 pin 14          */
    MIBADC1_GIOB0,         /**< Alias for GIO port b pin 0      */
    MIBADC1_GIOB1          /**< Alias for GIO port b pin 1      */
};
/** @enum mibadc2HwTriggerSource
*   @brief Alias names for hardware trigger source
*   This enumeration is used to provide alias names for the hardware trigger sources:
*/

enum mibadc2HwTriggerSource
{
    MIBADC2_ADEVT,          /**< Alias for event pin             */
    MIBADC2_NHET2_5,        /**< Alias for NHET2 pin 5           */
    MIBADC2_NHET1_27,       /**< Alias for NHET1 pin 10          */
    MIBADC2_RTI_COMP0,      /**< Alias for RTI compare 0 match   */
    MIBADC2_NHET1_17,       /**< Alias for NHET pin 17           */
    MIBADC2_NHET1_19,       /**< Alias for NHET pin 19           */
    MIBADC2_NHET1_11,       /**< Alias for GIO port b pin 0      */
    MIBADC2_NHET2_13        /**< Alias for GIO port b pin 1      */
};


/* USER CODE BEGIN (1) */
/* USER CODE END */


/** @struct mibadcData
*   @brief MIBADC Conversion data structure
*
*   This type is used to pass mibadc conversion data.
*/
/** @typedef mibadcData_t
*   @brief MIBADC Data Type Definition
*/
typedef struct mibadcData
{
    int            id;     /**< Channel/Pin Id        */
    uint16_t value;  /**< Conversion data value */
} mibadcData_t;

/** @struct mibadcBase
*   @brief MIBADC Register Frame Definition
*
*   This type is used to access the MIBADC Registers.
*/
/** @typedef mibadcBASE_t
*   @brief MIBADC Register Frame Type Definition
*
*   This type is used to access the MIBADC Registers.
*/
typedef volatile struct mibadcBase
{
    uint32_t RSTCR;              /**< 0x0000: Reset control register                            */
    uint32_t OPMODECR;           /**< 0x0004: Operating mode control register                   */
    uint32_t CLOCKCR;            /**< 0x0008: Clock control register                            */
    uint32_t CALCR;              /**< 0x000C: Calibration control register                      */
    uint32_t GxMODECR[3U];       /**< 0x0010,0x0014,0x0018: Group 0-2 mode control register     */
    uint32_t G0SRC;              /**< 0x001C: Group 0 trigger source control register           */
    uint32_t G1SRC;              /**< 0x0020: Group 1 trigger source control register           */
    uint32_t G2SRC;              /**< 0x0024: Group 2 trigger source control register           */
    uint32_t GxINTENA[3U];       /**< 0x0028,0x002C,0x0030: Group 0-2 interrupt enable register */
    uint32_t GxINTFLG[3U];       /**< 0x0034,0x0038,0x003C: Group 0-2 interrupt flag register   */
    uint32_t GxINTCR[3U];        /**< 0x0040-0x0048: Group 0-2 interrupt threshold register     */
    uint32_t G0DMACR;            /**< 0x004C: Group 0 DMA control register                      */
    uint32_t G1DMACR;            /**< 0x0050: Group 1 DMA control register                      */
    uint32_t G2DMACR;            /**< 0x0054: Group 2 DMA control register                      */
    uint32_t BNDCR;              /**< 0x0058: Buffer boundary control register                  */
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1)) 
    uint32_t BNDEND  : 16U;      /**< 0x005C: Buffer boundary end register                      */
    uint32_t BUFINIT : 16U;      /**< 0x005C: Buffer initialization register                    */
#else
    uint32_t BUFINIT : 16U;      /**< 0x005C: Buffer initialization register                    */
    uint32_t BNDEND  : 16U;      /**< 0x005C: Buffer boundary end register                      */
#endif
    uint32_t G0SAMP;             /**< 0x0060: Group 0 sample window register                    */
    uint32_t G1SAMP;             /**< 0x0064: Group 1 sample window register                    */
    uint32_t G2SAMP;             /**< 0x0068: Group 2 sample window register                    */
    uint32_t G0SR;               /**< 0x006C: Group 0 status register                           */
    uint32_t G1SR;               /**< 0x0070: Group 1 status register                           */
    uint32_t G2SR;               /**< 0x0074: Group 2 status register                           */
    uint32_t GxSEL[3U];          /**< 0x0078-0x007C: Group 0-2 channel select register          */
    uint32_t CALR;               /**< 0x0084: Calibration register                              */
    uint32_t SMSTATE;            /**< 0x0088: State machine state register                      */
    uint32_t LASTCONV;           /**< 0x008C: Last conversion register                          */
    struct
    {
        uint32_t BUF0;           /**< 0x0090,0x00B0,0x00D0: Group 0-2 result buffer 1 register  */
        uint32_t BUF1;           /**< 0x0094,0x00B4,0x00D4: Group 0-2 result buffer 1 register  */
        uint32_t BUF2;           /**< 0x0098,0x00B8,0x00D8: Group 0-2 result buffer 2 register  */
        uint32_t BUF3;           /**< 0x009C,0x00BC,0x00DC: Group 0-2 result buffer 3 register  */
        uint32_t BUF4;           /**< 0x00A0,0x00C0,0x00E0: Group 0-2 result buffer 4 register  */
        uint32_t BUF5;           /**< 0x00A4,0x00C4,0x00E4: Group 0-2 result buffer 5 register  */
        uint32_t BUF6;           /**< 0x00A8,0x00C8,0x00E8: Group 0-2 result buffer 6 register  */
        uint32_t BUF7;           /**< 0x00AC,0x00CC,0x00EC: Group 0-2 result buffer 7 register  */
    } GxBUF[3U];
    uint32_t G0EMUBUFFER;        /**< 0x00F0: Group 0 emulation result buffer                   */
    uint32_t G1EMUBUFFER;        /**< 0x00F4: Group 1 emulation result buffer                   */
    uint32_t G2EMUBUFFER;        /**< 0x00F8: Group 2 emulation result buffer                   */
    uint32_t EVTDIR;             /**< 0x00FC: Event pin direction register                      */
    uint32_t EVTOUT;             /**< 0x0100: Event pin digital output register                 */
    uint32_t EVTIN;              /**< 0x0104: Event pin digital input register                  */
    uint32_t EVTSET;             /**< 0x0108: Event pin set register                            */
    uint32_t EVTCLR;             /**< 0x010C: Event pin clear register                          */
    uint32_t EVTPDR;             /**< 0x0110: Event pin open drain register                     */
    uint32_t EVTDIS;             /**< 0x0114: Event pin pull disable register                   */
    uint32_t EVTPSEL;            /**< 0x0118: Event pin pull select register                    */
    uint32_t G0SAMPDISEN;        /**< 0x011C: Group 0 sample discharge register                 */
    uint32_t G1SAMPDISEN;        /**< 0x0120: Group 1 sample discharge register                 */
    uint32_t G2SAMPDISEN;        /**< 0x0124: Group 2 sample discharge register                 */
    uint32_t MAGINTCR1;          /**< 0x0128: Magnitude interrupt control register 1            */
    uint32_t MAGINT1MASK;        /**< 0x012C: Magnitude interrupt mask register 1               */
    uint32_t MAGINTCR2;          /**< 0x0130: Magnitude interrupt control register 2            */
    uint32_t MAGINT2MASK;        /**< 0x0134: Magnitude interrupt mask register 2               */
    uint32_t MAGINTCR3;          /**< 0x0138: Magnitude interrupt control register 3            */
    uint32_t MAGINT3MASK;        /**< 0x013C: Magnitude interrupt mask register 3               */
    uint32_t MAGINTCR4;          /**< 0x0140: Magnitude interrupt control register 4            */
    uint32_t MAGINT4MASK;        /**< 0x0144: Magnitude interrupt mask register 4               */
    uint32_t MAGINTCR5;          /**< 0x0148: Magnitude interrupt control register 5            */
    uint32_t MAGINT5MASK;        /**< 0x014C: Magnitude interrupt mask register 5               */
    uint32_t MAGINTCR6;          /**< 0x0150: Magnitude interrupt control register 6            */
    uint32_t MAGINT6MASK;        /**< 0x0154: Magnitude interrupt mask register 6               */
    uint32_t MAGTHRINTENASET;    /**< 0x0158: Magnitude interrupt set register                  */
    uint32_t MAGTHRINTENACLR;    /**< 0x015C: Magnitude interrupt clear register                */
    uint32_t MAGTHRINTFLG;       /**< 0x0160: Magnitude interrupt flag register                 */
    uint32_t MAGTHRINTOFFSET;    /**< 0x0164: Magnitude interrupt offset register               */
    uint32_t GxFIFORESETCR[3U];  /**< 0x0168,0x016C,0x0170: Group 0-2 fifo reset register       */
    uint32_t G0RAMADDR;          /**< 0x0174: Group 0 RAM pointer register                      */
    uint32_t G1RAMADDR;          /**< 0x0178: Group 1 RAM pointer register                      */
    uint32_t G2RAMADDR;          /**< 0x017C: Group 2 RAM pointer register                      */
    uint32_t PARCR;              /**< 0x0180: Parity control register                           */
    uint32_t PARADDR;            /**< 0x0184: Parity error address register                     */
} mibadcBASE_t;


/** @def mibadcREG1
*   @brief MIBADC1 Register Frame Pointer
*
*   This pointer is used by the MIBADC driver to access the MIBADC1 registers.
*/
#define mibadcREG1 ((mibadcBASE_t *)0xFFF7C000U)

/** @def mibadcREG2
*   @brief MIBADC2 Register Frame Pointer
*
*   This pointer is used by the MIBADC driver to access the MIBADC2 registers.
*/
#define mibadcREG2 ((mibadcBASE_t *)0xFFF7C200U)

/* USER CODE BEGIN (2) */
/* USER CODE END */


/* MIBADC Interface Functions */

void mibadcInit(void);
void mibadcStartConversion(mibadcBASE_t *mibadc, uint32_t group);
void mibadcStopConversion(mibadcBASE_t *mibadc, uint32_t group);
void mibadcResetFiFo(mibadcBASE_t *mibadc, uint32_t group);
int  mibadcGetData(mibadcBASE_t *mibadc, uint32_t group, mibadcData_t *data);
int  mibadcIsFifoFull(mibadcBASE_t *mibadc, uint32_t group);
int  mibadcIsConversionComplete(mibadcBASE_t *mibadc, uint32_t group);
void mibadcEnableNotification(mibadcBASE_t *mibadc, uint32_t group);
void mibadcDisableNotification(mibadcBASE_t *mibadc, uint32_t group);

/** @fn void mibadcNotification(mibadcBASE_t *mibadc, uint32_t group)
*   @brief Group notification
*   @param[in] mibadc Pointer to MIBADC node:
*              - mibadcREG1: MIBADC1 module pointer
*              - mibadcREG2: MIBADC2 module pointer
*   @param[in] group number of MIBADC node:
*              - mibadcGROUP0: MIBADC event group
*              - mibadcGROUP1: MIBADC group 1
*              - mibadcGROUP2: MIBADC group 2
*
*   @note This function has to be provide by the user.
*/
void mibadcNotification(mibadcBASE_t *mibadc, uint32_t group);

/* USER CODE BEGIN (3) */
/* USER CODE END */


#endif
