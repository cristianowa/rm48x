#include "mac.h"
#include "phy_dp83640.h"
#include "sys_common.h"
#include "mdio.h"
#include "emac.h"
#include "sci_print.h"

#define MDIO_0_BASE               0xFCF78900
#define MDIO_FREQ_INPUT           32000000
#define MDIO_FREQ_OUTPUT          1000000

#define SIZE_EMAC_CTRL_RAM        0x2000




#define EMAC_DSC_FLAG_SOP 0x80000000
#define EMAC_DSC_FLAG_EOP 0x40000000
#define EMAC_DSC_FLAG_OWNER 0x20000000
#define EMAC_DSC_FLAG_EOQ 0x10000000
#define EMAC_DSC_FLAG_TDOWNCMPLT 0x08000000
#define EMAC_DSC_FLAG_PASSCRC 0x04000000


uint8_t		__mac__emacAddress[6] 	= 	{0x1, 0x2, 0x3, 0x4, 0x5, 0x6};
uint32_t 	__mac__emacPhyAddress	=	1;


void smallDelay(void) {
	  static volatile unsigned int delayval;
	  delayval = 10000;   // 100000 are about 10ms
	  while(delayval--);
}
/* EMAC TX Buffer descriptor data structure */

struct emac_tx_bd {
  volatile struct emac_tx_bd *next;
  volatile uint8_t *bufptr;
  volatile uint32_t bufoff_len;
  volatile uint32_t flags_pktlen;
};

typedef struct emac_tx_bd mac_tx_bd_t;
/* EMAC RX Buffer descriptor data structure */

struct emac_rx_bd {
  volatile struct emac_rx_bd *next;
  volatile uint8_t *bufptr;
  volatile uint32_t bufoff_len;
  volatile uint32_t flags_pktlen;
};

typedef struct emac_rx_bd mac_rx_bd_t;

//volatile char *portptr = (char*)MYPORT;
volatile mac_rx_bd_t tx_buffer[SIZE_EMAC_CTRL_RAM / 2] = (mac_rx_bd_t*)EMAC_CTRL_RAM_BASE; 
volatile mac_rx_bd_t rx_buffer[SIZE_EMAC_CTRL_RAM / 2] = (mac_rx_bd_t*)(EMAC_CTRL_RAM_BASE + SIZE_EMAC_CTRL_RAM / 2);

uint8_t buffer[5000];
uint8_t * buf_ptr;

int initialize_CPPI()
{
  uint32_t num_bd;
  volatile mac_tx_bd_t *curr_txbd;
 // tx_buffer =  (volatile mac_rx_bd_t*)(EMAC_CTRL_RAM_BASE); - static
  //inicialize half of the CPPI with tx buffers
  //for now we don't have any data struct to handle it
  num_bd = (SIZE_EMAC_CTRL_RAM >> 1) / sizeof(mac_rx_bd_t);
  curr_txbd = (void*) tx_buffer;
   while(num_bd--) {
     //the CPPI contains lines indexed by the "next" filed with 24 bytes each
    curr_txbd->next = curr_txbd + 1;
    curr_txbd->flags_pktlen = 0;
    curr_txbd = curr_txbd->next;
  } 
  
  //  rx_buffer = ((void*)curr_txbd->next); - static
    rx_buffer->bufptr = buf_ptr;
    rx_buffer->bufoff_len = 0;
    rx_buffer->next = NULL;
    rx_buffer->flags_pktlen = EMAC_MACCONTROL_RXOWNERSHIP;
  
  //TODO inicialize RX buffer.
  
  
  return 0;
}

int link_setup()
{
    uint16_t partnr_ablty;
    uint32_t phyduplex = EMAC_DUPLEX_HALF;
          if(Dp83640AutoNegotiate(MDIO_0_BASE, __mac__emacPhyAddress,
                             (DP83640_100BTX | DP83640_100BTX_FD
                              | DP83640_10BT | DP83640_10BT_FD)) == TRUE) 
          {
               //OK
              Dp83640PartnerAbilityGet(MDIO_0_BASE, __mac__emacPhyAddress,
                                &partnr_ablty);
      
      /* Check for 100 Mbps and duplex capability */
      if(partnr_ablty & DP83640_100BTX_FD) {
        phyduplex = EMAC_DUPLEX_FULL;
      }
    }
    else 
    {
      return -1;
    }  
 
  /* Set the EMAC with the negotiation results if it is successful */ 
    EMACDuplexSet(EMAC_BASE, phyduplex); 
  
  /* Wait for the MII to settle down */
   smallDelay();
   

    return 0;
  
}

int enable_transmission()
{
   /* Acknowledge receive and transmit interrupts for proper interrupt pulsing*/
  EMACCoreIntAck(EMAC_BASE, EMAC_INT_CORE0_RX);
  EMACCoreIntAck(EMAC_BASE, EMAC_INT_CORE0_TX);
  
  EMACRxUnicastSet(EMAC_BASE, 0);
  EMACNumFreeBufSet(EMAC_BASE, 0, 1);
  EMACTxEnable(EMAC_BASE);
  EMACRxEnable(EMAC_BASE);

  /* Write the RX HDP for channel 0 */
  EMACRxHdrDescPtrWrite(EMAC_BASE, (uint32_t)tx_buffer, 0);
 
  EMACMIIEnable(EMAC_BASE); 

  
  /**
  * Enable the Transmission and reception, enable the interrupts for
  * channel 0 and for control core 0
  */
  EMACTxIntPulseEnable(EMAC_BASE, EMAC_CTRL_BASE, 0, 0);
  EMACRxIntPulseEnable(EMAC_BASE, EMAC_CTRL_BASE, 0, 0);

  
  return 0;
}

int macInit()
{
          uint32_t channel;
          volatile uint32_t phyID=0;
          volatile uint32_t phyIdReadCount = 0xFFFF;

          EMACInit( EMAC_CTRL_BASE, EMAC_BASE);

          MDIOInit(MDIO_0_BASE,MDIO_FREQ_INPUT,MDIO_FREQ_OUTPUT );

          smallDelay();smallDelay();

          EMACRxBroadCastEnable(EMAC_BASE,0);

          EMACMACSrcAddrSet(EMAC_BASE, __mac__emacAddress);

          for(channel = 0; channel < 8; channel++) 
          {
                 
              EMACMACAddrSet(EMAC_BASE, channel,__mac__emacAddress, EMAC_MACADDR_MATCH);
 
          }
          while ((phyID == 0) && (phyIdReadCount > 0)) 
          {
	      phyID = Dp83640IDGet(MDIO_0_BASE, __mac__emacPhyAddress);
              phyIdReadCount--;	
          }

          if (0 != phyID)   
              print_line("    Phy ID Readed");
          else 
          {
              print_line("    Error reading Phy ID, aborting");
              return -1;    
          }

          if(!((MDIOPhyAliveStatusGet(MDIO_0_BASE) >> __mac__emacPhyAddress) & 0x01 )) 
          {
              print_line("    Error reading Phy Status, aborting");
              return -1;
          } 
          else 
 	      print_line("    Phy Status Readed");

          if(!Dp83640LinkStatusGet(MDIO_0_BASE, 1, 0xFFFF)) {
              print_line("    Error reading Phy Link Status, aborting");
              return -1;
          }
          else 
 	       print_line("    Phy Link Status Readed");
          if ( link_setup() )
          {
                print_line("    Failure setting Link, aborting");            
                return -1;
          }
          else
                print_line("    Link Set");

          
          if(!initialize_CPPI())
                print_line("    CPPI Initialized Set");
          else
          { 
                print_line("    Failure Initializing CPPI, aborting");            
                return -1;
          }
          
          if(!enable_transmission())
             print_line("    Transmission Enabled");
          else
          { 
                print_line("    Failure Enabling Transmission, aborting");            
                return -1;
          }
      

          
          print_line("");
          return 0;
}



int eth_transmit(uint8_t* buf,uint32_t length)
{
  if( length > 1500 )

    return -1;
  else
  {
      
      tx_buffer[0].next = NULL;
      tx_buffer[0].bufptr = buf;
      tx_buffer[0].bufoff_len = length;
      tx_buffer[0].flags_pktlen = length;
      tx_buffer[0].flags_pktlen |= EMAC_DSC_FLAG_EOP | EMAC_DSC_FLAG_SOP;
    
      EMACTxHdrDescPtrWrite(MDIO_0_BASE, (unsigned int)(tx_buffer), 1);
  
      return 0;
  }
}

uint8_t vec[80] = { 0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,                    
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,                    
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,                    
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,
                    0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,                    
                    };

int eth_dummy_send()
{
  eth_transmit(vec,80);
  return 0;
}