/**
 * @file - hdkif.h
 * Prototypes for HDK Ethernet interface.
 *
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/*
 * Copyright (c) 2010 Texas Instruments Incorporated
 *
 */


#ifndef __HDKIF_H__
#define __HDKIF_H__
#include "sys_common.h"
#include "sys_core.h"

/* HALCoGen DriverLib Header & PHY files required for this interface driver. */
#include "emac.h"
#include "mdio.h"
#include "phy_dp83640.h"
h/* Number of EMAC Instances */
#define MAX_EMAC_INSTANCE         1
#define ETHARP_HWADDR_LEN     6

/* Pbuf type defintion */
typedef struct pbuf pbuf_t;

/* EMAC TX Buffer descriptor data structure */
struct emac_tx_bd {
  volatile struct emac_tx_bd *next;
  volatile uint32_t bufptr;
  volatile uint32_t bufoff_len;
  volatile uint32_t flags_pktlen;
  
  /* helper to know which pbuf this tx bd corresponds to */
  volatile struct pbuf *pbuf;
}emac_tx_bd;


/* EMAC RX Buffer descriptor data structure */
struct emac_rx_bd {
  volatile struct emac_rx_bd *next;
  volatile uint32_t bufptr;
  volatile uint32_t bufoff_len;
  volatile uint32_t flags_pktlen;

  /* helper to know which pbuf this rx bd corresponds to */
  volatile pbuf_t *pbuf;
}emac_rx_bd;

/**
 * Helper struct to hold the data used to operate on a particular 
 * receive channel 
 */
typedef struct rxch_t {
  volatile struct emac_rx_bd *free_head;
  volatile struct emac_rx_bd *active_head;
  volatile struct emac_rx_bd *active_tail;
  uint32_t freed_pbuf_len;
}rxch_t;

/**
 * Helper struct to hold the data used to operate on a particular 
 * transmit channel 
 */
typedef struct txch_t {
  volatile struct emac_tx_bd *free_head;
  volatile struct emac_tx_bd *active_tail;
  volatile struct emac_tx_bd *next_bd_to_process;
}txch_t;
 
/**
 * Helper struct to hold private data used to operate the ethernet interface.
 */
typedef struct hdkif_t {
  /* emac instance number */
  uint32_t inst_num;

  uint8_t mac_addr[6];

  /* emac base address */
  uint32_t emac_base;

  /* emac controller base address */
  volatile uint32_t emac_ctrl_base;
  volatile uint32_t emac_ctrl_ram;

  /* mdio base address */
  volatile uint32_t mdio_base;

  /* phy parameters for this instance - for future use */
  uint32_t phy_addr;
  uint32_t (*phy_autoneg)(uint32_t, uint32_t, uint16_t);
  uint32_t (*phy_partnerability)(uint32_t, uint32_t, uint16_t*);
 
  /* The tx/rx channels for the interface */
  txch_t txch;
  rxch_t rxch;
}hdkif_t;

typedef struct netif_t  {
  hdkif_t *state;
  uint32_t hwaddr_len;
  uint32_t   hwaddr[ETHARP_HWADDR_LEN];
  uint32_t   mtu;
  uint32_t   flags;
  uint8_t  name[2];
  uint8_t num ;
  int *  output;
  int * linkoutput;
  
}netif_t;

extern int hdkif_netif_status(netif_t *netif);
extern int hdkif_link_status(netif_t *netif);
extern int hdkif_init(netif_t *netif);
extern void hdkif_rx_inthandler(netif_t *netif);
extern void hdkif_tx_inthandler(netif_t *netif);

#endif // _HDKIF_H__
