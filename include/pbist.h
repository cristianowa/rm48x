/** @file pbist.h
*   @brief PBIST Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __PBIST_H__
#define __PBIST_H__

/** @struct pbistBase
*   @brief PBIST Base Register Definition
*
*   This structure is used to access the PBIST module registers.
*/
typedef volatile struct pbistBase
{
	unsigned VAR0;       //0x00
    unsigned VAR1;       //0x04
	unsigned VAR2;       //0x08
	unsigned VAR3;       //0x0C
    unsigned VLCR0;       //0x10
	unsigned VLCR1;       //0x14
    unsigned VLCR00;       //0x18
	unsigned VLCR11;       //0x1C
	unsigned DD0D1;       //0x020
	unsigned DE0E1;       //0x24
	unsigned int:32;       //0x028
	unsigned int:32;       //0x02C
	unsigned CARA0;       //0x030
	unsigned CARA1;       //0x034
	unsigned CARA2;       //0x038
	unsigned CARA3;       //0x03C
	unsigned CLCRL0;       //0x040
	unsigned CLCRL1;       //0x044
	unsigned CLCRL2;       //0x048
	unsigned CLCRL3;       //0x04C
	unsigned CIRIO;       //0x050
	unsigned CIRI1;       //0x054
	unsigned CIRI2;       //0x058
	unsigned CIRI3;       //0x05C
	unsigned RAM;       //0x060
	unsigned DLR;       //0x064
	unsigned CMS;       //0x068
	unsigned STR;       //0x06C
	unsigned int:32;       //0x070
	unsigned int:32;       //0x074
	unsigned CSR;       //0x078
	unsigned FDLY;       //0x07C
	unsigned PACT;       //0x080
	unsigned PBISTID;       //0x084
	unsigned PBISTOVERRRIDE;       //0x088
	unsigned int:32;       //0x08C
	unsigned FSRFO;       //0x090
	unsigned FSRF1;       //0x094
	unsigned FSRC0;       //0x098
	unsigned FSRC1;       //0x09C
	unsigned FSRA0;       //0x0A0
	unsigned FSRA1;       //0x0A4
	unsigned FSRDL0;       //0x0A8
	unsigned int:32;       //0x0AC
	unsigned FSRDL1;       //0x0B0
	unsigned int:32;       //0x0B4
	unsigned int:32;       //0x0B8
	unsigned int:32;       //0x0BC
	unsigned ROM;       //0x0C0
	unsigned ALGO;       //0x0C4
	unsigned RINFOL;       //0x0C8
	unsigned RINFOU;       //0x0CC  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	
} pbistBASE_t;

/** @def pbistREG
*   @brief PBIST Register Frame Pointer
*
*   This pointer is used by the PBIST driver to access the pbist module registers.
*/
#define pbistREG   ((pbistBASE_t *)0xFFFFE500U) /* Actual Frame starts from 400 but 400 to 500 we do not have header definition */

/* PBIST Interface Functions */
void pbistInit(unsigned int RAM_GRP_SEL);
void pbistStartSelfTest(void);
void pbistDisableSelfTest(void);
void pbist_test(void);



/* PBIST RAM Algo select */
unsigned const int RAM_GRP_ALGO_SEL[16]=
					{
						0x0000FFFF,			/* ALL RAM SELCTED TOGETHER */
						0x00000003,			/* PBIST ROM */
						0x00000003,			/* STC ROM */
						0x00001554,			/* DCAN1 RAM */ 
						0x00001554,			/* DCAN2 RAM */
						0x00001554,			/* DCAN3 RAM */
						0x00001554,			/* ESRAM */
						0x00001554,			/* MIBSPI RAM */
						0x00001554,			/* VIM RAM */
						0x00002AA8,			/* MIBADC RAM */
						0x0000CAA8,			/* DMA RAM */
						0x00002AA8,			/* NHET RAM */
						0x00002AA8,			/* HTU RAM */
						0x00002AA8,			/* RTP RAM */
						0x00001554,			/* FLEXRAY RAM */
						0x00002AA8			/* ESRAM */
					};

enum RAM_GRP
{
	RAM_GRP_ALL = 0,
	RAM_GRP1 = 1,
	RAM_GRP2 = 2,
	RAM_GRP3 = 3,
	RAM_GRP4 = 4,
	RAM_GRP5 = 5,
	RAM_GRP6 = 6,
	RAM_GRP7 = 7,
	RAM_GRP8 = 8,
	RAM_GRP9 = 9,
	RAM_GRP10 = 10,
	RAM_GRP11 = 11,
	RAM_GRP12 = 12,
	RAM_GRP13 = 13,
	RAM_GRP14 = 14,
	RAM_GRP15 = 15
};

#define ALGO_SEL_RAM_GRP1	0x00000003			/* PBIST ROM */
#define ALGO_SEL_RAM_GRP2	0x00000003			/* STC ROM */
#define ALGO_SEL_RAM_GRP3	0x00001554			/* DCAN1 RAM */ 
#define ALGO_SEL_RAM_GRP4	0x00001554			/* DCAN2 RAM */
#define ALGO_SEL_RAM_GRP5	0x00001554			/* DCAN3 RAM */
#define ALGO_SEL_RAM_GRP6	0x00001554			/* ESRAM */
#define ALGO_SEL_RAM_GRP7	0x00001554			/* MIBSPI RAM */
#define ALGO_SEL_RAM_GRP8	0x00001554			/* VIM RAM */
#define ALGO_SEL_RAM_GRP9	0x00002AA8			/* MIBADC RAM */
#define ALGO_SEL_RAM_GRP10	0x0000CAA8			/* DMA RAM */
#define ALGO_SEL_RAM_GRP11	0x00002AA8			/* NHET RAM */
#define ALGO_SEL_RAM_GRP12	0x00002AA8			/* HTU RAM */
#define ALGO_SEL_RAM_GRP13	0x00002AA8			/* RTP RAM */
#define ALGO_SEL_RAM_GRP14	0x00001554			/* FLEXRAY RAM */
#define ALGO_SEL_RAM_GRP15	0x00002AA8			/* ESRAM */

#endif
