/*----------------------------------------------------------------------------*/
/* sys_link.cmd                                                               */
/*                                                                            */
/* (c) Texas Instruments 2009-2010, All rights reserved.                      */
/*                                                                            */


define memory mem with size = 4G;

define region VECTORS = mem:[from 0x00000000 size 0x00000020];
define region FLASH   = mem:[from 0x00000020 size 0x0017FFE0]
                      | mem:[from 0x00180000 size 0x00180000];
define region STACK   = mem:[from 0x08000000 size 0x00001500];
define region RAM     = mem:[from 0x08001500 size 0x00026B00];

initialize by copy {readwrite};
do not initialize  {section .noinit};

place in VECTORS {readonly section .intvecs};
place in FLASH   {readonly};
place in RAM     {readwrite};

/*----------------------------------------------------------------------------*/

