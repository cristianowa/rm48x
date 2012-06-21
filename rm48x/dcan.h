/** @file DCAN.h
*   @brief DCAN Driver Header File
*   @date 04.October.2011
*   @version 1.02.000
*   
*   This file contains:
*   - Definitions
*   - Types
*   - Interface Prototypes
*   .
*   which are relevant for the DCAN driver.
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */

#include "sys_common.h"

#ifndef __DCAN_H__
#define __DCAN_H__

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* DCAN General Definitions */

/** @def DCANLEVEL_ACTIVE
*   @brief Alias name for DCAN error operation level active (Error couter 0-95)  
*/
#define DCANLEVEL_ACTIVE 0x00U

/** @def DCANLEVEL_WARNING
*   @brief Alias name for DCAN error operation level warning (Error couter 96-127)  
*/
#define DCANLEVEL_WARNING 0x40U

/** @def DCANLEVEL_PASSIVE
*   @brief Alias name for DCAN error operation level passive (Error couter 128-255)  
*/
#define DCANLEVEL_PASSIVE 0x20U

/** @def DCANLEVEL_BUS_OFF
*   @brief Alias name for DCAN error operation level bus off (Error couter 256)  
*/
#define DCANLEVEL_BUS_OFF 0x80U

/** @def DCANERROR_NO
*   @brief Alias name for no DCAN error occured 
*/
#define DCANERROR_OK 0U

/** @def DCANERROR_STUFF
*   @brief Alias name for DCAN stuff error an RX message 
*/
#define DCANERROR_STUFF 1U

/** @def DCANERROR_FORMAT
*   @brief Alias name for DCAN form/format error an RX message 
*/
#define DCANERROR_FORMAT 2U

/** @def DCANERROR_ACKNOWLEDGE
*   @brief Alias name for DCAN TX message wasn't acknowledged  
*/
#define DCANERROR_ACKNOWLEDGE 3U

/** @def DCANERROR_BIT1
*   @brief Alias name for DCAN TX message sendig recessive level but monitoring dominant  
*/
#define DCANERROR_BIT1 4U

/** @def DCANERROR_BIT0
*   @brief Alias name for DCAN TX message sendig dominant level but monitoring recessive  
*/
#define DCANERROR_BIT0 5U

/** @def DCANERROR_CRC
*   @brief Alias name for DCAN RX message received wrong CRC  
*/
#define DCANERROR_CRC 6U

/** @def DCANERROR_NO
*   @brief Alias name for DCAN no message has send or received sinced last call of DCANGetLastError  
*/
#define DCANERROR_NO 7U

/** @def DCANMESSAGE_BOX1
*   @brief Alias name for DCAN message box 1
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX1 1U

/** @def DCANMESSAGE_BOX2
*   @brief Alias name for DCAN message box 2
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX2 2U

/** @def DCANMESSAGE_BOX3
*   @brief Alias name for DCAN message box 3
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX3 3U

/** @def DCANMESSAGE_BOX4
*   @brief Alias name for DCAN message box 4
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX4 4U

/** @def DCANMESSAGE_BOX5
*   @brief Alias name for DCAN message box 5
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX5 5U

/** @def DCANMESSAGE_BOX6
*   @brief Alias name for DCAN message box 6
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX6 6U

/** @def DCANMESSAGE_BOX7
*   @brief Alias name for DCAN message box 7
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX7 7U

/** @def DCANMESSAGE_BOX8
*   @brief Alias name for DCAN message box 8
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX8 8U

/** @def DCANMESSAGE_BOX9
*   @brief Alias name for DCAN message box 9
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX9 9U

/** @def DCANMESSAGE_BOX10
*   @brief Alias name for DCAN message box 10
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX10 10U

/** @def DCANMESSAGE_BOX11
*   @brief Alias name for DCAN message box 11
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX11 11U

/** @def DCANMESSAGE_BOX12
*   @brief Alias name for DCAN message box 12
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX12 12U

/** @def DCANMESSAGE_BOX13
*   @brief Alias name for DCAN message box 13
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX13 13U

/** @def DCANMESSAGE_BOX14
*   @brief Alias name for DCAN message box 14
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX14 14U

/** @def DCANMESSAGE_BOX15
*   @brief Alias name for DCAN message box 15
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX15 15U

/** @def DCANMESSAGE_BOX16
*   @brief Alias name for DCAN message box 16
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX16 16U

/** @def DCANMESSAGE_BOX17
*   @brief Alias name for DCAN message box 17
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX17 17U

/** @def DCANMESSAGE_BOX18
*   @brief Alias name for DCAN message box 18
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX18 18U

/** @def DCANMESSAGE_BOX19
*   @brief Alias name for DCAN message box 19
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX19 19U

/** @def DCANMESSAGE_BOX20
*   @brief Alias name for DCAN message box 20
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX20 20U

/** @def DCANMESSAGE_BOX21
*   @brief Alias name for DCAN message box 21
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX21 21U

/** @def DCANMESSAGE_BOX22
*   @brief Alias name for DCAN message box 22
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX22 22U

/** @def DCANMESSAGE_BOX23
*   @brief Alias name for DCAN message box 23
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX23 23U

/** @def DCANMESSAGE_BOX24
*   @brief Alias name for DCAN message box 24
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX24 24U

/** @def DCANMESSAGE_BOX25
*   @brief Alias name for DCAN message box 25
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX25 25U

/** @def DCANMESSAGE_BOX26
*   @brief Alias name for DCAN message box 26
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX26 26U

/** @def DCANMESSAGE_BOX27
*   @brief Alias name for DCAN message box 27
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX27 27U

/** @def DCANMESSAGE_BOX28
*   @brief Alias name for DCAN message box 28
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX28 28U

/** @def DCANMESSAGE_BOX29
*   @brief Alias name for DCAN message box 29
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX29 29U

/** @def DCANMESSAGE_BOX30
*   @brief Alias name for DCAN message box 30
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX30 30U

/** @def DCANMESSAGE_BOX31
*   @brief Alias name for DCAN message box 31
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX31 31U

/** @def DCANMESSAGE_BOX32
*   @brief Alias name for DCAN message box 32
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX32 32U

/** @def DCANMESSAGE_BOX33
*   @brief Alias name for DCAN message box 33
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX33 33U

/** @def DCANMESSAGE_BOX34
*   @brief Alias name for DCAN message box 34
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX34 34U

/** @def DCANMESSAGE_BOX35
*   @brief Alias name for DCAN message box 35
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX35 35U

/** @def DCANMESSAGE_BOX36
*   @brief Alias name for DCAN message box 36
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX36 36U

/** @def DCANMESSAGE_BOX37
*   @brief Alias name for DCAN message box 37
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX37 37U

/** @def DCANMESSAGE_BOX38
*   @brief Alias name for DCAN message box 38
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX38 38U

/** @def DCANMESSAGE_BOX39
*   @brief Alias name for DCAN message box 39
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX39 39U

/** @def DCANMESSAGE_BOX40
*   @brief Alias name for DCAN message box 40
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX40 40U

/** @def DCANMESSAGE_BOX41
*   @brief Alias name for DCAN message box 41
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX41 41U

/** @def DCANMESSAGE_BOX42
*   @brief Alias name for DCAN message box 42
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX42 42U

/** @def DCANMESSAGE_BOX43
*   @brief Alias name for DCAN message box 43
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX43 43U

/** @def DCANMESSAGE_BOX44
*   @brief Alias name for DCAN message box 44
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX44 44U

/** @def DCANMESSAGE_BOX45
*   @brief Alias name for DCAN message box 45
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX45 45U

/** @def DCANMESSAGE_BOX46
*   @brief Alias name for DCAN message box 46
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX46 46U

/** @def DCANMESSAGE_BOX47
*   @brief Alias name for DCAN message box 47
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX47 47U

/** @def DCANMESSAGE_BOX48
*   @brief Alias name for DCAN message box 48
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX48 48U

/** @def DCANMESSAGE_BOX49
*   @brief Alias name for DCAN message box 49
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX49 49U

/** @def DCANMESSAGE_BOX50
*   @brief Alias name for DCAN message box 50
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX50 50U

/** @def DCANMESSAGE_BOX51
*   @brief Alias name for DCAN message box 51
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX51 51U

/** @def DCANMESSAGE_BOX52
*   @brief Alias name for DCAN message box 52
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX52 52U

/** @def DCANMESSAGE_BOX53
*   @brief Alias name for DCAN message box 53
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX53 53U

/** @def DCANMESSAGE_BOX54
*   @brief Alias name for DCAN message box 54
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX54 54U

/** @def DCANMESSAGE_BOX55
*   @brief Alias name for DCAN message box 55
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX55 55U

/** @def DCANMESSAGE_BOX56
*   @brief Alias name for DCAN message box 56
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX56 56U

/** @def DCANMESSAGE_BOX57
*   @brief Alias name for DCAN message box 57
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX57 57U

/** @def DCANMESSAGE_BOX58
*   @brief Alias name for DCAN message box 58
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX58 58U

/** @def DCANMESSAGE_BOX59
*   @brief Alias name for DCAN message box 59
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX59 59U

/** @def DCANMESSAGE_BOX60
*   @brief Alias name for DCAN message box 60
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX60 60U

/** @def DCANMESSAGE_BOX61
*   @brief Alias name for DCAN message box 61
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX61 61U

/** @def DCANMESSAGE_BOX62
*   @brief Alias name for DCAN message box 62
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX62 62U

/** @def DCANMESSAGE_BOX63
*   @brief Alias name for DCAN message box 63
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX63 63U

/** @def DCANMESSAGE_BOX64
*   @brief Alias name for DCAN message box 64
*
*   @note This value should be used for API argument @a messageBox
*/
#define DCANMESSAGE_BOX64 64U

/* USER CODE BEGIN (1) */
/* USER CODE END */


/** @struct DCANBase
*   @brief DCAN Register Frame Definition
*
*   This type is used to access the DCAN Registers.
*/
/** @typedef dcanBASE_t
*   @brief DCAN Register Frame Type Definition
*
*   This type is used to access the DCAN Registers.
*/
typedef volatile struct DCANBase
{
    uint32_t      CTL;          /**< 0x0000: Control Register                       */
    uint32_t      ES;           /**< 0x0004: Error and Status Register              */
    uint32_t      EERC;         /**< 0x0008: Error Counter Register                 */
    uint32_t      BTR;          /**< 0x000C: Bit Timing Register                    */
    uint32_t      INT;          /**< 0x0010: Interrupt Register                     */
    uint32_t      TEST;         /**< 0x0014: Test Register                          */
    uint32_t      : 32U;        /**< 0x0018: Reserved                               */
    uint32_t      PERR;         /**< 0x001C: Parity/SECDED Error Code Register      */
    uint32_t      REL;          /**< 0x0020: Core Release Register                  */
    uint32_t      ECCDIAG;      /**< 0x0024: ECC Diagnostic Register                */
    uint32_t      ECCDIADSTAT;  /**< 0x0028: ECC Diagnostic Status Register         */
    uint32_t      : 32U;        /**< 0x002C: Reserved                               */
    uint32_t      : 32U;        /**< 0x0030: Reserved                               */
    uint32_t      : 32U;        /**< 0x0034: Reserved                               */
    uint32_t      : 32U;        /**< 0x0038: Reserved                               */
    uint32_t      : 32U;        /**< 0x003C: Reserved                               */
    uint32_t      : 32U;        /**< 0x0040: Reserved                               */
    uint32_t      : 32U;        /**< 0x0044: Reserved                               */
    uint32_t      : 32U;        /**< 0x0048: Reserved                               */
    uint32_t      : 32U;        /**< 0x004C: Reserved                               */
    uint32_t      : 32U;        /**< 0x0050: Reserved                               */
    uint32_t      : 32U;        /**< 0x0054: Reserved                               */
    uint32_t      : 32U;        /**< 0x0058: Reserved                               */
    uint32_t      : 32U;        /**< 0x005C: Reserved                               */
    uint32_t      : 32U;        /**< 0x0060: Reserved                               */
    uint32_t      : 32U;        /**< 0x0064: Reserved                               */
    uint32_t      : 32U;        /**< 0x0068: Reserved                               */
    uint32_t      : 32U;        /**< 0x006C: Reserved                               */
    uint32_t      : 32U;        /**< 0x0070: Reserved                               */
    uint32_t      : 32U;        /**< 0x0074: Reserved                               */
    uint32_t      : 32U;        /**< 0x0078: Reserved                               */
    uint32_t      : 32U;        /**< 0x007C: Reserved                               */
    uint32_t      ABOTR;        /**< 0x0080: Auto Bus On Time Register              */
    uint32_t      TXRQX;        /**< 0x0084: Transmission Request X Register        */
    uint32_t      TXRQx[4U];    /**< 0x0088-0x0094: Transmission Request Registers  */
    uint32_t      NWDATX;       /**< 0x0098: New Data X Register                    */
    uint32_t      NWDATx[4U];   /**< 0x009C-0x00A8: New Data Registers              */
    uint32_t      INTPNDX;      /**< 0x00AC: Interrupt Pending X Register           */
    uint32_t      INTPNDx[4U];  /**< 0x00B0-0x00BC: Interrupt Pending Registers     */
    uint32_t      MSGVALX;      /**< 0x00C0: Message Valid X Register               */
    uint32_t      MSGVALx[4U];  /**< 0x00C4-0x00D0: Message Valid Registers         */
    uint32_t      : 32U;        /**< 0x00D4: Reserved                               */
    uint32_t      INTMUXx[4U];  /**< 0x00D8-0x00E4: Interrupt Multiplexer Registers */
    uint32_t      : 32U;        /**< 0x00E8: Reserved                               */
    uint32_t      : 32U;        /**< 0x00EC: Reserved                               */
    uint32_t      : 32U;        /**< 0x00F0: Reserved                               */
    uint32_t      : 32U;        /**< 0x00F4: Reserved                               */
    uint32_t      : 32U;        /**< 0x00F8: Reserved                               */
    uint32_t      : 32U;        /**< 0x00FC: Reserved                               */
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
    uint8_t IF1NO;              /**< 0x0100: IF1 Command Register, Msg Number       */
    uint8_t IF1STAT;            /**< 0x0100: IF1 Command Register, Status           */
    uint8_t IF1CMD;             /**< 0x0100: IF1 Command Register, Command          */
    uint32_t      : 8U;         /**< 0x0100: IF1 Command Register, Reserved         */
#else
    uint32_t      : 8U;         /**< 0x0100: IF1 Command Register, Reserved         */
    uint8_t IF1CMD;             /**< 0x0100: IF1 Command Register, Command          */
    uint8_t IF1STAT;            /**< 0x0100: IF1 Command Register, Status           */
    uint8_t IF1NO;              /**< 0x0100: IF1 Command Register, Msg Number       */
#endif
    uint32_t      IF1MSK;       /**< 0x0104: IF1 Mask Register                      */
    uint32_t      IF1ARB;       /**< 0x0108: IF1 Arbitration Register               */
    uint32_t      IF1MCTL;      /**< 0x010C: IF1 Message Control Register           */
    uint8_t IF1DATx[8U];        /**< 0x0110-0x0114: IF1 Data A and B Registers      */
    uint32_t      : 32U;        /**< 0x0118: Reserved                               */
    uint32_t      : 32U;        /**< 0x011C: Reserved                               */
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
    uint8_t IF2NO;              /**< 0x0120: IF2 Command Register, Msg No           */
    uint8_t IF2STAT;            /**< 0x0120: IF2 Command Register, Status           */
    uint8_t IF2CMD;             /**< 0x0120: IF2 Command Register, Command          */
    uint32_t      : 8U;         /**< 0x0120: IF2 Command Register, Reserved         */
#else
    uint32_t      : 8U;         /**< 0x0120: IF2 Command Register, Reserved         */
    uint8_t IF2CMD;             /**< 0x0120: IF2 Command Register, Command          */
    uint8_t IF2STAT;            /**< 0x0120: IF2 Command Register, Status           */
    uint8_t IF2NO;              /**< 0x0120: IF2 Command Register, Msg Number       */
#endif
    uint32_t      IF2MSK;       /**< 0x0124: IF2 Mask Register                      */
    uint32_t      IF2ARB;       /**< 0x0128: IF2 Arbitration Register               */
    uint32_t      IF2MCTL;      /**< 0x012C: IF2 Message Control Register           */
    uint8_t IF2DATx[8U];        /**< 0x0130-0x0134: IF2 Data A and B Registers      */
    uint32_t      : 32U;        /**< 0x0138: Reserved                               */
    uint32_t      : 32U;        /**< 0x013C: Reserved                               */
    uint32_t      IF3OBS;       /**< 0x0140: IF3 Observation Register               */
    uint32_t      IF3MSK;       /**< 0x0144: IF3 Mask Register                      */
    uint32_t      IF3ARB;       /**< 0x0148: IF3 Arbitration Register               */
    uint32_t      IF3MCTL;      /**< 0x014C: IF3 Message Control Register           */
    uint8_t IF3DATx[8U];        /**< 0x0150-0x0154: IF3 Data A and B Registers      */
    uint32_t      : 32U;        /**< 0x0158: Reserved                               */
    uint32_t      : 32U;        /**< 0x015C: Reserved                               */
    uint32_t      IF3UEy[4U];   /**< 0x0160-0x016C: IF3 Update Enable Registers     */
    uint32_t      : 32U;        /**< 0x0170: Reserved                               */
    uint32_t      : 32U;        /**< 0x0174: Reserved                               */
    uint32_t      : 32U;        /**< 0x0178: Reserved                               */
    uint32_t      : 32U;        /**< 0x017C: Reserved                               */
    uint32_t      : 32U;        /**< 0x0180: Reserved                               */
    uint32_t      : 32U;        /**< 0x0184: Reserved                               */
    uint32_t      : 32U;        /**< 0x0188: Reserved                               */
    uint32_t      : 32U;        /**< 0x018C: Reserved                               */
    uint32_t      : 32U;        /**< 0x0190: Reserved                               */
    uint32_t      : 32U;        /**< 0x0194: Reserved                               */
    uint32_t      : 32U;        /**< 0x0198: Reserved                               */
    uint32_t      : 32U;        /**< 0x019C: Reserved                               */
    uint32_t      : 32U;        /**< 0x01A0: Reserved                               */
    uint32_t      : 32U;        /**< 0x01A4: Reserved                               */
    uint32_t      : 32U;        /**< 0x01A8: Reserved                               */
    uint32_t      : 32U;        /**< 0x01AC: Reserved                               */
    uint32_t      : 32U;        /**< 0x01B0: Reserved                               */
    uint32_t      : 32U;        /**< 0x01B4: Reserved                               */
    uint32_t      : 32U;        /**< 0x01B8: Reserved                               */
    uint32_t      : 32U;        /**< 0x01BC: Reserved                               */
    uint32_t      : 32U;        /**< 0x01C0: Reserved                               */
    uint32_t      : 32U;        /**< 0x01C4: Reserved                               */
    uint32_t      : 32U;        /**< 0x01C8: Reserved                               */
    uint32_t      : 32U;        /**< 0x01CC: Reserved                               */
    uint32_t      : 32U;        /**< 0x01D0: Reserved                               */
    uint32_t      : 32U;        /**< 0x01D4: Reserved                               */
    uint32_t      : 32U;        /**< 0x01D8: Reserved                               */
    uint32_t      : 32U;        /**< 0x01DC: Reserved                               */
    uint32_t      TIOC;         /**< 0x01E0: TX IO Control Register                 */
    uint32_t      RIOC;         /**< 0x01E4: RX IO Control Register                 */
} dcanBASE_t;


/** @def dcanREG1
*   @brief DCAN1 Register Frame Pointer
*
*   This pointer is used by the DCAN driver to access the DCAN1 registers.
*/
#define dcanREG1 ((dcanBASE_t *)0xFFF7DC00U)

/** @def dcanREG2
*   @brief DCAN2 Register Frame Pointer
*
*   This pointer is used by the DCAN driver to access the DCAN2 registers.
*/
#define dcanREG2 ((dcanBASE_t *)0xFFF7DE00U)

/** @def dcanREG3
*   @brief DCAN3 Register Frame Pointer
*
*   This pointer is used by the DCAN driver to access the DCAN3 registers.
*/
#define dcanREG3 ((dcanBASE_t *)0xFFF7E000U)

/* USER CODE BEGIN (2) */
/* USER CODE END */


/* DCAN Interface Functions */

void     dcanInit(void);
uint32_t dcanTransmit(dcanBASE_t *node, uint32_t messageBox, const uint8_t *data);
uint32_t dcanGetData(dcanBASE_t *node, uint32_t messageBox, uint8_t * const data);
uint32_t dcanIsTxMessagePending(dcanBASE_t *node, uint32_t messageBox);
uint32_t dcanIsRxMessageArrived(dcanBASE_t *node, uint32_t messageBox);
uint32_t dcanIsMessageBoxValid(dcanBASE_t *node, uint32_t messageBox);
uint32_t dcanGetLastError(dcanBASE_t *node);
uint32_t dcanGetErrorLevel(dcanBASE_t *node);
void     dcanEnableErrorNotification(dcanBASE_t *node);
void     dcanDisableErrorNotification(dcanBASE_t *node);

/** @fn void dcanErrorNotification(dcanBASE_t *node, uint32_t notification)
*   @brief Error notification
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] notification Error notification code:
*           - DCANLEVEL_WARNING (0x40): When RX- or TX error counter are between 96 and 127     
*           - DCANLEVEL_BUS_OFF (0x80): When RX- or TX error counter are above 255     
*
*   @note This function has to be provide by the user.
*/
void dcanErrorNotification(dcanBASE_t *node, uint32_t notification);

/** @fn void dcanMessageNotification(dcanBASE_t *node, uint32_t messageBox)
*   @brief Message notification
*   @param[in] node Pointer to DCAN node:
*              - dcanREG1: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] messageBox Message box number of DCAN node:
*              - DCANMESSAGE_BOX1: DCAN message box 1
*              - DCANMESSAGE_BOXn: DCAN message box n [n: 1-64]
*              - DCANMESSAGE_BOX64: DCAN message box 64
*
*   @note This function has to be provide by the user.
*/
void dcanMessageNotification(dcanBASE_t *node, uint32_t messageBox);

/* USER CODE BEGIN (3) */
/* USER CODE END */


#endif
