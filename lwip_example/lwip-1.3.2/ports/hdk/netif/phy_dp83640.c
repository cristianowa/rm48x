/**
 *  \file   phy_dp83640.c
 *
 *  \brief  APIs for configuring DP83640.
 *
 *   This file contains the device abstraction APIs for PHY DP83640.
 */

/* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "sys_common.h"
#include "mdio.h"
#include "netif\phy_dp83640.h"


/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/
/**
 * \brief   Reads the PHY ID.
 *
 * \param   mdioBaseAddr  Base Address of the MDIO Module Registers.
 * \param   phyAddr       PHY Adress.
 *
 * \return  32 bit PHY ID (ID1:ID2)
 *
 **/
unsigned int Dp83640IDGet(unsigned int mdioBaseAddr, unsigned int phyAddr)
{
    unsigned int id = 0;
    unsigned short data = 0;

    /* read the ID1 register */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_ID1, &data);

    /* update the ID1 value */
    id = data << PHY_ID_SHIFT;
 
    /* read the ID2 register */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_ID2, &data);

    /* update the ID2 value */
    id |= data; 

    /* return the ID in ID1:ID2 format */
    return id;
}

/**
 * \brief   Reads the link status of the PHY.
 *
 * \param   mdioBaseAddr  Base Address of the MDIO Module Registers.
 * \param   phyAddr       PHY Adress.
 * \param   retries       The number of retries before indicating down status
 *
 * \return  link status after reading \n
 *          TRUE if link is up
 *          FALSE if link is down \n
 *
 * \note    This reads both the basic status register of the PHY and the
 *          link register of MDIO for double check
 **/
unsigned int Dp83640LinkStatusGet(unsigned int mdioBaseAddr,
                                   unsigned int phyAddr,
                                   volatile unsigned int retries)
{
    volatile unsigned short linkStatus;
    volatile unsigned int retVal = TRUE;

    while (retVal == TRUE)
    {
        /* First read the BSR of the PHY */
        MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_BSR, &linkStatus);

        if(linkStatus & PHY_LINK_STATUS)
        {
            /* Check if MDIO LINK register is updated */
            linkStatus = MDIOPhyLinkStatusGet(mdioBaseAddr);

            if(linkStatus & (1 << phyAddr))
            {
               break;
            }
            else
            {
                (retries != 0) ? retries-- : (retVal = FALSE);
            }
        }
        else
        {
            (retries != 0) ? retries-- : (retVal = FALSE);
        }
    }

    return retVal;
}

/**
 * \brief   This function does Autonegotiates with the EMAC device connected
 *          to the PHY. It will wait till the autonegotiation completes.
 *
 * \param   mdioBaseAddr  Base Address of the MDIO Module Registers.
 * \param   phyAddr       PHY Adress.
 * \param   advVal        Autonegotiation advertisement value
 *          advVal can take the following any OR combination of the values \n
 *               DP83640_100BTX - 100BaseTX
 *               DP83640_100BTX_FD - Full duplex capabilty for 100BaseTX 
 *               DP83640_10BT - 10BaseT
 *               DP83640_10BT_FD - Full duplex capability for 10BaseT
 *
 * \return  status after autonegotiation \n
 *          TRUE if autonegotiation successful
 *          FALSE if autonegotiation failed
 *
 **/
unsigned int Dp83640AutoNegotiate(unsigned int mdioBaseAddr,
                                   unsigned int phyAddr, unsigned short advVal)
{
    volatile unsigned short data, anar;

    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_BCR, &data) != TRUE )
    {
        return FALSE;
    }
   
    data |= PHY_AUTONEG_ENABLE; 
   
    /* Enable Auto Negotiation */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, PHY_BCR, data);

    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_BCR, &data) != TRUE )
    {
        return FALSE;
    }

    /* Write Auto Negotiation capabilities */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_AUTONEG_ADV, &anar);
    anar &= ~0xff10;
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, PHY_AUTONEG_ADV, (anar |advVal));

    data |= PHY_AUTONEG_RESTART;

    /* Start Auto Negotiation */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, PHY_BCR, data);

    /* Get the auto negotiation status*/
    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_BSR, &data) != TRUE)
    {
         return FALSE;
    }
    
    /* Wait till auto negotiation is complete */
    while(PHY_AUTONEG_INCOMPLETE == (data & PHY_AUTONEG_STATUS))
    {
         MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_BSR, &data);
    }

    /* Check if the PHY is able to perform auto negotiation */
    if(data & PHY_AUTONEG_ABLE)
    {
         return TRUE;
    }
  
    return FALSE;
}


/**
 * \brief   Reads the Link Partner Ability register of the PHY.
 *
 * \param   mdioBaseAddr  Base Address of the MDIO Module Registers.
 * \param   phyAddr       PHY Adress.
 * \param   ptnerAblty    The partner abilities of the EMAC
 *
 * \return  status after reading \n
 *          TRUE if reading successful
 *          FALSE if reading failed
 **/
unsigned int Dp83640PartnerAbilityGet(unsigned int mdioBaseAddr, 
                                       unsigned int phyAddr,
                                       unsigned short *ptnerAblty)
{
    return (MDIOPhyRegRead(mdioBaseAddr, phyAddr, PHY_LINK_PARTNER_ABLTY,
                           ptnerAblty));
}

/**************************** End Of File ***********************************/
