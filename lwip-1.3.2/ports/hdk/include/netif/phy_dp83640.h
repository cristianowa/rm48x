/*
 * DP83640.h
 */

/* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef _PHY_DP83640_H_
#define _PHY_DP83640_H_

#ifdef __cplusplus
extern "C" {
#endif
/* PHY register offset definitions */
#define PHY_BCR                           (0u)
#define PHY_BSR                           (1u)
#define PHY_ID1                           (2u)
#define PHY_ID2                           (3u)
#define PHY_AUTONEG_ADV                   (4u)
#define PHY_LINK_PARTNER_ABLTY            (5u)

/* PHY status definitions */
#define PHY_ID_SHIFT                      (16u)
#define PHY_SOFTRESET                     (0x8000)
#define PHY_AUTONEG_ENABLE                (0x1000u)
#define PHY_AUTONEG_RESTART               (0x0200u)
#define PHY_AUTONEG_COMPLETE              (0x0020u)
#define PHY_AUTONEG_INCOMPLETE            (0x0000u)
#define PHY_AUTONEG_STATUS                (0x0020u)
#define PHY_AUTONEG_ABLE                  (0x0008u)
#define PHY_LPBK_ENABLE                   (0x4000u)
#define PHY_LINK_STATUS                   (0x0004u)



/* PHY ID. The LSB nibble will vary between different phy revisions */
#define DP83640_PHY_ID                   (0x0007C0F0u)
#define DP83640_PHY_ID_REV_MASK          (0x0000000Fu)

/* Pause operations */
#define DP83640_PAUSE_NIL                (0x0000u)
#define DP83640_PAUSE_SYM                (0x0400u)
#define DP83640_PAUSE_ASYM               (0x0800u)
#define DP83640_PAUSE_BOTH_SYM_ASYM      (0x0C00u)

/* 100 Base TX Full Duplex capablity */
#define DP83640_100BTX_HD                (0x0000u)
#define DP83640_100BTX_FD                (0x0100u)

/* 100 Base TX capability */
#define DP83640_NO_100BTX                (0x0000u)
#define DP83640_100BTX                   (0x0080u)

/* 10 BaseT duplex capabilities */
#define DP83640_10BT_HD                  (0x0000u)
#define DP83640_10BT_FD                  (0x0040u)

/* 10 BaseT ability*/
#define DP83640_NO_10BT                  (0x0000u)
#define DP83640_10BT                     (0x0020u)

/**************************************************************************
                        API function Prototypes
**************************************************************************/
extern unsigned int Dp83640IDGet(unsigned int mdioBaseAddr,
                                  unsigned int phyAddr);
extern void Dp83640Reset(unsigned int mdioBaseAddr, 
                          unsigned int phyAddr);
extern unsigned int Dp83640LoopBackEnable(unsigned int mdioBaseAddr,
                                           unsigned int phyAddr);
extern unsigned int Dp83640LoopBackDisable(unsigned int mdioBaseAddr,
                                            unsigned int phyAddr);

extern unsigned int Dp83640Configure(unsigned int mdioBaseAddr, 
                                      unsigned int phyAddr,       
                                      unsigned short speed, 
                                      unsigned short dulplexMode);
extern unsigned int Dp83640AutoNegotiate(unsigned int mdioBaseAddr,
                                          unsigned int phyAddr,
                                          unsigned short advVal);
extern unsigned int Dp83640RegRead(unsigned int mdioBaseAddr, 
                                   unsigned int phyAddr,
                                   unsigned int regIdx, 
                                   unsigned short *regValAdr);
extern void Dp83640RegWrite(unsigned int mdioBaseAddr, 
                             unsigned int phyAddr,
                             unsigned int regIdx, 
                             unsigned short regVal);

extern unsigned int Dp83640PartnerAbilityGet(unsigned int mdioBaseAddr,
                                              unsigned int phyAddr,
                                              unsigned short *ptnerAblty);

unsigned int Dp83640LinkStatusGet(unsigned int mdioBaseAddr,
                                   unsigned int phyAddr,
                                   volatile unsigned int retries);
#ifdef __cplusplus
}
#endif
#endif
