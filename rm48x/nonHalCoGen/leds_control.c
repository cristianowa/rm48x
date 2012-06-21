

#include "nhet.h"
#include "leds_control.h"


void leds_init(void)
{
	  /** - NHET is configured as Master 
     *  - NHET is turned On */    
   	nhetREG1->GCR     	= 0x01000001; 
	
	/** - PULL functinality is enabled */
	nhetREG1->PULDIS	= 0x00000000;
	/** - Configure NHET pins as output */
   	nhetREG1->DIR   	= 0xAA178035; 
	/** - Turn all LEDs off */
	nhetREG1->DOUT   	= 0x0;   //0x08110034;
	
}

void led_on(led ledIndex)
{
	int idxValue;
	int dout; 
	nhetREG1->DOUT = 0xFFFFFFFF;
//	idxValue = 0|1<<((int)ledIndex);
	//dout = nhetREG1->DOUT & ~idxValue;
	//nhetREG1->DOUT   	= dout | (1 << idxValue) ;
}

void led_off(led ledIndex)
{
		int idxValue;
	int dout; 
	idxValue = 0|1<<((int)ledIndex);
	dout = nhetREG1->DOUT & ~idxValue;
	nhetREG1->DOUT   	= dout | (0 << idxValue) ;
}

