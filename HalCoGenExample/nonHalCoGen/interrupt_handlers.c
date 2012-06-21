/** @file sci.h
*   @brief interrupt handlers file
*   @date 20.february.2012
*   
*/

/* (c) Cristiano W. Araújo 2012 */

#include "dcan.h"
#include "dcc.h"
#include "nhet.h"
#include "spi.h"
#include "sys_esm.h"
#include "i2c.h"
#include "gio.h"
#include "sci.h"
#include "mibadc.h"
#include "mibspi.h"
#include "mibspi.h"

void dcanErrorNotification(dcanBASE_t *node, uint32_t notification)
{
	return;
}

void dcanMessageNotification(dcanBASE_t *node, uint32_t messageBox)
{
	return;
}

void dccNotification(dccBASE_t  *dcc,uint32_t flags)
{
	return;
}

void  edgeNotification(nhetBASE_t * nhetREG,uint32_t edge)
{
	return;	
}

void spiNotification(spiBASE_t *spi, uint32_t flags)
{
	return;
}

void esmGroup1Notification(uint32_t channel)
{
	return;	
}

void i2cNotification(i2cBASE_t *i2c, uint32_t flags)
{
	return;	
}

void gioNotification(int bit)
{
	return;	
}

void mibadcNotification(mibadcBASE_t *mibadc, uint32_t group)
{
	return;	
}

void mibspiNotification(mibspiBASE_t *mibspi, uint32_t flags)
{
	return;	
}

void mibspiGroupNotification(mibspiBASE_t *mibspi, uint32_t group)
{
	return;	
}

void pwmNotification(nhetBASE_t * nhetREG,uint32_t pwm, uint32_t notification)
{
	return;
}

void esmGroup2Notification(uint32_t channel)
{
	return;
}

void rtiNotification(uint32_t notification)
{
	return;
}

void sciNotification(sciBASE_t *sci, uint32_t flags)
{
	return;	
}	
