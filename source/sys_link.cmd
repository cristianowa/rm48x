/*----------------------------------------------------------------------------*/
/* sys_link.cmd                                                               */
/*                                                                            */
/* (c) Texas Instruments 2009-2010, All rights reserved.                      */
/*                                                                            */


FLASH 0x00000000 0x00200000  
{
  VECTORS 0x00000000 0x00000020  
  {
   *.o (intvecs, +First)
  }
  FLASH0 0x00000020 0x0017FFE0  
  {
   *.o (reset, +First)
   *(InRoot$$Sections)
   .ANY3 (+RO)
  }
  FLASH1 0x00180000 0x00180000  
  {
   .ANY2 (+RO)
  }
  ARM_LIB_STACK 0x08000000 EMPTY 0x00001500
  {
  }
  RAM 0x08001500 0x00026B00  
  {
   .ANY (+RW +ZI)
  }
}

/*----------------------------------------------------------------------------*/

