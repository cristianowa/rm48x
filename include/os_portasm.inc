;/*
;    FreeRTOS V7.0.2 - Copyright (C) 2011 Real Time Engineers Ltd.
;	
;
;    ***************************************************************************
;     *                                                                       *
;     *    FreeRTOS tutorial books are available in pdf and paperback.        *
;     *    Complete, revised, and edited pdf reference manuals are also       *
;     *    available.                                                         *
;     *                                                                       *
;     *    Purchasing FreeRTOS documentation will not only help you, by       *
;     *    ensuring you get running as quickly as possible and with an        *
;     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
;     *    the FreeRTOS project to continue with its mission of providing     *
;     *    professional grade, cross platform, de facto standard solutions    *
;     *    for microcontrollers - completely free of charge!                  *
;     *                                                                       *
;     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
;     *                                                                       *
;     *    Thank you for using FreeRTOS, and thank you for your support!      *
;     *                                                                       *
;    ***************************************************************************
;
;
;    This file is part of the FreeRTOS distribution.
;
;    FreeRTOS is free software; you can redistribute it and/or modify it under
;    the terms of the GNU General Public License (version 2) as published by the
;    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
;    >>>NOTE<<< The modification to the GPL is included to allow you to
;    distribute a combined work that includes FreeRTOS without being obliged to
;    provide the source code for proprietary components outside of the FreeRTOS
;    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
;    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
;    more details. You should have received a copy of the GNU General Public
;    License and the FreeRTOS license exception along with FreeRTOS; if not it
;    can be viewed here: http://www.freertos.org/a00114.html and also obtained
;    by writing to Richard Barry, contact details for whom are available on the
;    FreeRTOS WEB site.
;
;    1 tab == 4 spaces!
;
;    http://www.FreeRTOS.org - Documentation, latest information, license and
;    contact details.
;
;    http://www.SafeRTOS.com - A version that is certified for use in safety
;    critical systems.
;
;    http://www.OpenRTOS.com - Commercial support, development, porting,
;    licensing and training services.
;*/

;
; Save Task Context 
;
portSAVE_CONTEXT macro
        stmfd   sp!, {r0}
        stmfd   sp,  {sp}^
        sub     sp,  sp, #4
        ldmfd   sp!, {r0}
        stmfd   r0!, {lr}
        mov	    lr,  r0
        ldmfd   sp!, {r0}
        stmfd   lr,  {r0-lr}^
        sub     lr,  lr, #0x3C
        fstmdbd lr!, {d0-d15}
        mrs	    r0,  spsr
        fmrx    r1,  fpscr
        stmfd   lr!, {r0,r1}
        ldr	    r0, critNest
        ldr	    r0, [r0]
        stmfd   lr!, {r0}
        ldr	    r0,  curTCB
        ldr	    r0,  [r0]
        str	    lr,  [r0]
        endm

;
; Restore Task Context
;
portRESTORE_CONTEXT macro
        ldr		r0,  curTCB
        ldr		r0,  [r0]
        ldr		lr,  [r0]
        ldr	    r0, critNest
        ldmfd	lr!, {r1}
        str	r1, [r0]
        ldmfd   lr!, {r0,r1}
        fldmiad lr!, {d0-d15}
        fmxr    fpscr, r1
        msr		spsr_csxf, r0
        ldmfd	lr, {r0-r14}^
        ldr		lr, [lr, #0x3C]
        subs	pc, lr, #4
        endm

        

;-------------------------------------------------------------------------------

