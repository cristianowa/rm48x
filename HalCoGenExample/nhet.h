/** @file nhet.h
*   @brief NHET Driver Definition File
*   @date 04.October.2011
*   @version 1.02.000
*   
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */


#ifndef __NHET_H__
#define __NHET_H__

#include "sys_common.h"
#include "gio.h"
#include <string.h>

/** @def pwm0
*   @brief Pwm signal 0
*
*   Alias for pwm signal 0
*/
#define pwm0 0U

/** @def pwm1
*   @brief Pwm signal 1
*
*   Alias for pwm signal 1
*/
#define pwm1 1U

/** @def pwm2
*   @brief Pwm signal 2
*
*   Alias for pwm signal 2
*/
#define pwm2 2U

/** @def pwm3
*   @brief Pwm signal 3
*
*   Alias for pwm signal 3
*/
#define pwm3 3U

/** @def pwm4
*   @brief Pwm signal 4
*
*   Alias for pwm signal 4
*/
#define pwm4 4U

/** @def pwm5
*   @brief Pwm signal 5
*
*   Alias for pwm signal 5
*/
#define pwm5 5U

/** @def pwm6
*   @brief Pwm signal 6
*
*   Alias for pwm signal 6
*/
#define pwm6 6U

/** @def pwm7
*   @brief Pwm signal 7
*
*   Alias for pwm signal 7
*/
#define pwm7 7U


/** @def edge0
*   @brief Edge signal 0
*
*   Alias for edge signal 0
*/
#define edge0 0U

/** @def edge1
*   @brief Edge signal 1
*
*   Alias for edge signal 1
*/
#define edge1 1U

/** @def edge2
*   @brief Edge signal 2
*
*   Alias for edge signal 2
*/
#define edge2 2U

/** @def edge3
*   @brief Edge signal 3
*
*   Alias for edge signal 3
*/
#define edge3 3U

/** @def edge4
*   @brief Edge signal 4
*
*   Alias for edge signal 4
*/
#define edge4 4U

/** @def edge5
*   @brief Edge signal 5
*
*   Alias for edge signal 5
*/
#define edge5 5U

/** @def edge6
*   @brief Edge signal 6
*
*   Alias for edge signal 6
*/
#define edge6 6U

/** @def edge7
*   @brief Edge signal 7
*
*   Alias for edge signal 7
*/
#define edge7 7U


/** @def cap0
*   @brief Capture signal 0
*
*   Alias for capture signal 0
*/
#define cap0 0U

/** @def cap1
*   @brief Capture signal 1
*
*   Alias for capture signal 1
*/
#define cap1 1U

/** @def cap2
*   @brief Capture signal 2
*
*   Alias for capture signal 2
*/
#define cap2 2U

/** @def cap3
*   @brief Capture signal 3
*
*   Alias for capture signal 3
*/
#define cap3 3U

/** @def cap4
*   @brief Capture signal 4
*
*   Alias for capture signal 4
*/
#define cap4 4U

/** @def cap5
*   @brief Capture signal 5
*
*   Alias for capture signal 5
*/
#define cap5 5U

/** @def cap6
*   @brief Capture signal 6
*
*   Alias for capture signal 6
*/
#define cap6 6U

/** @def cap7
*   @brief Capture signal 7
*
*   Alias for capture signal 7
*/
#define cap7 7U

/** @def pwmEND_OF_DUTY
*   @brief Pwm end of duty
*
*   Alias for pwm end of duty notification
*/
#define pwmEND_OF_DUTY 2U

/** @def pwmEND_OF_PERIOD
*   @brief Pwm end of period
*
*   Alias for pwm end of period notification
*/
#define pwmEND_OF_PERIOD 4U

/** @def pwmEND_OF_BOTH
*   @brief Pwm end of duty and period
*
*   Alias for pwm end of duty and period notification
*/
#define pwmEND_OF_BOTH 6U

/** @struct nhetBase
*   @brief NHET Register Definition
*
*   This structure is used to access the NHET module egisters.
*/
/** @typedef nhetBASE_t
*   @brief NHET Register Frame Type Definition
*
*   This type is used to access the NHET Registers.
*/

enum nhetPinSelect
{
    PIN_NHET_0 = 0,
    PIN_NHET_1 = 1,
    PIN_NHET_2 = 2,
    PIN_NHET_3 = 3,
    PIN_NHET_4 = 4,
    PIN_NHET_5 = 5,
    PIN_NHET_6 = 6,
    PIN_NHET_7 = 7,
    PIN_NHET_8 = 8,
    PIN_NHET_9 = 9,
    PIN_NHET_10 = 10,
    PIN_NHET_11 = 11,
    PIN_NHET_12 = 12,
    PIN_NHET_13 = 13,
    PIN_NHET_14 = 14,
    PIN_NHET_15 = 15,
    PIN_NHET_16 = 16,
    PIN_NHET_17 = 17,
    PIN_NHET_18 = 18,
    PIN_NHET_19 = 19,
    PIN_NHET_20 = 20,
    PIN_NHET_21 = 21,
    PIN_NHET_22 = 22,
    PIN_NHET_23 = 23,
    PIN_NHET_24 = 24,
    PIN_NHET_25 = 25,
    PIN_NHET_26 = 26,
    PIN_NHET_27 = 27,
    PIN_NHET_28 = 28,
    PIN_NHET_29 = 29,
    PIN_NHET_30 = 30,
    PIN_NHET_31 = 31
};


typedef volatile struct nhetBase
{
    uint32_t GCR;     /**< 0x0000: Global control register              */
    uint32_t PFR;     /**< 0x0004: Prescale factor register             */
    uint32_t ADDR;    /**< 0x0008: Current address register             */
    uint32_t OFF1;    /**< 0x000C: Interrupt offset register 1          */
    uint32_t OFF2;    /**< 0x0010: Interrupt offset register 2          */
    uint32_t INTENAS; /**< 0x0014: Interrupt enable set register        */
    uint32_t INTENAC; /**< 0x0018: Interrupt enable clear register      */
    uint32_t EXC1;    /**< 0x001C: Exeption control register 1          */
    uint32_t EXC2;    /**< 0x0020: Exeption control register 2          */
    uint32_t PRY;     /**< 0x0024: Interrupt priority register          */
    uint32_t FLG;     /**< 0x0028: Interrupt flag register              */
    uint32_t AND;     /**< 0x002C: AND share control register         */
    uint32_t : 32U;   /**< 0x0030: Reserved                             */
    uint32_t HRSH;    /**< 0x0034: High resoltion share register        */
    uint32_t XOR;     /**< 0x0038: XOR share register                   */
    uint32_t REQENS;  /**< 0x003C: Request enable set register          */
    uint32_t REQENC;  /**< 0x0040: Request enable clear register        */
    uint32_t REQDS;   /**< 0x0044: Request destination select register  */
    uint32_t : 32U;   /**< 0x0048: Reserved                             */
    uint32_t DIR;     /**< 0x004C: Direction register                   */
    uint32_t DIN;     /**< 0x0050: Data input register                  */
    uint32_t DOUT;    /**< 0x0054: Data output register                 */
    uint32_t DSET;    /**< 0x0058: Data output set register             */
    uint32_t DCLR;    /**< 0x005C: Data output clear register           */
    uint32_t PDR;     /**< 0x0060: Open drain register                  */
    uint32_t PULDIS;  /**< 0x0064: Pull disable register                */
    uint32_t PSL;     /**< 0x0068: Pull select register                 */
    uint32_t : 32U;   /**< 0x006C: Reserved                             */
    uint32_t : 32U;   /**< 0x0070: Reserved                             */
    uint32_t PCREG;   /**< 0x0074: Parity control register              */
    uint32_t PAR;     /**< 0x0078: Parity address register              */
    uint32_t PPR;     /**< 0x007C: Parity pin select register           */
    uint32_t SFPRLD;  /**< 0x0080: Suppression filter preload register  */
    uint32_t SFENA;   /**< 0x0084: Suppression filter enable register   */
    uint32_t : 32U;   /**< 0x0088: Reserved                             */
    uint32_t LBPSEL;  /**< 0x008C: Loop back pair select register       */
    uint32_t LBPDIR;  /**< 0x0090: Loop back pair direction register    */
    uint32_t PINDIS;  /**< 0x0094: Pin disable register                 */
    uint32_t : 32U;   /**< 0x0098: Reserved                             */
    uint32_t HWAPINSEL;/**< 0x009C: HWAG Pin select register            */
    uint32_t HWAGCR0;  /**< 0x00A0: HWAG Global control register 0      */
    uint32_t HWAGCR1;  /**< 0x00A4: HWAG Global control register 1      */
    uint32_t HWAGCR2;  /**< 0x00A8: HWAG Global control register 2      */
    uint32_t HWAENASET;/**< 0x00AC: HWAG Interrupt enable set register  */
    uint32_t HWAENACLR;/**< 0x00B0: HWAG Interrupt enable clear register*/
    uint32_t HWALVLSET;/**< 0x00B4: HWAG Interrupt level set register   */
    uint32_t HWALVLCLR;/**< 0x00B8: HWAG Interrupt level clear register */
    uint32_t HWAFLG;   /**< 0x00BC: HWAG Interrupt flag register        */
    uint32_t HWAOFF1;  /**< 0x00C0: HWAG Interrupt offset 1 register    */
    uint32_t HWAOFF2;  /**< 0x00C4: HWAG Interrupt offset 2 register    */
    uint32_t HWAACNT;  /**< 0x00C8: HWAG Angle value register           */
    uint32_t HWAPCNT1; /**< 0x00CC: HWAG Period value register 1        */
    uint32_t HWAPCNT;  /**< 0x00D0: HWAG Period value register          */
    uint32_t HWASTWD;  /**< 0x00D4: HWAG Step width register            */
    uint32_t HWATHNB;  /**< 0x00D8: HWAG Teeth number register          */
    uint32_t HWATHVL;  /**< 0x00DC: HWAG Teeth Value register           */
    uint32_t HWAFIL;   /**< 0x00E0: HWAG Filter register                */
    uint32_t : 32U;    /**< 0x00E4: Reserved                            */
    uint32_t HWAFIL2;  /**< 0x00E8: HWAG Second filter register         */
    uint32_t : 32U;    /**< 0x00EC: Reserved                            */
    uint32_t HWAANGI;  /**< 0x00F0: HWAG Angle increment register       */
} nhetBASE_t;


/** @def nhetREG1
*   @brief NHET Register Frame Pointer
*
*   This pointer is used by the NHET driver to access the nhet module registers.
*/
#define nhetREG1 ((nhetBASE_t *)0xFFF7B800U)


/** @def nhetPORT1
*   @brief NHET GIO Port Register Pointer
*
*   Pointer used by the GIO driver to access I/O PORT of NHET1
*   (use the GIO drivers to access the port pins).
*/
#define nhetPORT1 ((gioPORT_t *)0xFFF7B84CU)


/** @def nhetREG2
*   @brief NHET2 Register Frame Pointer
*
*   This pointer is used by the NHET driver to access the nhet module registers.
*/
#define nhetREG2 ((nhetBASE_t *)0xFFF7B900U)


/** @def nhetPORT2
*   @brief NHET2 GIO Port Register Pointer
*
*   Pointer used by the GIO driver to access I/O PORT of NHET2
*   (use the GIO drivers to access the port pins).
*/
#define nhetPORT2 ((gioPORT_t *)0xFFF7B94CU)



/** @struct nhetInstructionBase
*   @brief NHET Instruction Definition
*
*   This structure is used to access the NHET RAM.
*/
/** @typedef nhetINSTRUCTION_t
*   @brief NHET Instruction Type Definition
*
*   This type is used to access a NHET Instruction.
*/
typedef volatile struct nhetInstructionBase
{
    uint32_t Program;
    uint32_t Control;
    uint32_t Data;
    uint32_t : 32U;
} nhetINSTRUCTION_t;


/** @struct nhetRamBase
*   @brief NHET RAM Definition
*
*   This structure is used to access the NHET RAM.
*/
/** @typedef nhetRAMBASE_t
*   @brief NHET RAM Type Definition
*
*   This type is used to access the NHET RAM.
*/
typedef volatile struct nhet1RamBase
{
    nhetINSTRUCTION_t Instruction[128U];
} nhetRAMBASE_t;


#define nhetRAM1 ((nhetRAMBASE_t *)0xFF460000U)

#define nhetRAM2 ((nhetRAMBASE_t *)0xFF440000U)


/** @struct nhetSignal
*   @brief NHET Signal Definition
*
*   This structure is used to define a pwm signal.
*/
/** @typedef nhetSIGNAL_t
*   @brief NHET Signal Type Definition
*
*   This type is used to access NHET Signal Information.
*/
typedef struct nhetSignal
{
	uint32_t duty;   /**< Duty cycle in % of the period  */
	double   period; /**< Period in us                   */
} nhetSIGNAL_t;


/* NHET Interface Functions */
void nhetInit(void);

/* PWM Interface Functions */
void        pwmStart(nhetRAMBASE_t * nhetRAM,uint32_t pwm);
void        pwmStop(nhetRAMBASE_t * nhetRAM,uint32_t pwm);
void        pwmSetDuty(nhetRAMBASE_t * nhetRAM,uint32_t pwm, uint32_t duty);
void        pwmSetSignal(nhetRAMBASE_t * nhetRAM,uint32_t pwm, nhetSIGNAL_t signal);
nhetSIGNAL_t pwmGetSignal(nhetRAMBASE_t * nhetRAM,uint32_t pwm);
void        pwmEnableNotification(nhetBASE_t * nhetREG,uint32_t pwm, uint32_t notification);
void        pwmDisableNotification(nhetBASE_t * nhetREG,uint32_t pwm, uint32_t notification);
void        pwmNotification(nhetBASE_t * nhetREG,uint32_t pwm, uint32_t notification);

/* Edge Interface Functions */
void     edgeResetCounter(nhetRAMBASE_t * nhetRAM,uint32_t edge);
uint32_t edgeGetCounter(nhetRAMBASE_t * nhetRAM,uint32_t edge);
void     edgeEnableNotification(nhetBASE_t * nhetREG,uint32_t edge);
void     edgeDisableNotification(nhetBASE_t * nhetREG,uint32_t edge);
void     edgeNotification(nhetBASE_t * nhetREG,uint32_t edge);

/* Captured Signal Interface Functions */
nhetSIGNAL_t capGetSignal(nhetRAMBASE_t * nhetRAM,uint32_t cap);

/* Timestamp Interface Functions */
void     nhetResetTimestamp(nhetRAMBASE_t * nhetRAM);
uint32_t nhetGetTimestamp(nhetRAMBASE_t * nhetRAM);

#endif
