;-------------------------------------------------------------------------------
; sys_core.asm
;
; (c) Texas Instruments 2009-2012, All rights reserved.
;

    area |.text|, code, readonly
    arm

;-------------------------------------------------------------------------------
; Initialize CPU Registers

	export     _coreInitRegisters_
    
    

_coreInitRegisters_


	; After reset, the CPU is in the Supervisor mode (M = 10011)
	    mov r0, lr
	    mov r1, #0x0000
	    mov r2, #0x0000
	    mov r3, #0x0000
	    mov r4, #0x0000
	    mov r5, #0x0000
	    mov r6, #0x0000
	    mov r7, #0x0000
	    mov r8, #0x0000
	    mov r9, #0x0000
	    mov r10, #0x0000
	    mov r11, #0x0000
	    mov r12, #0x0000
	    mov r13, #0x0000
	    mrs r1, cpsr
	    msr spsr_cxsf, r1 
	    ; Switch to FIQ mode (M = 10001)
	    cps #17
	    mov lr, r0
	    mov r8, #0x0000
	    mov r9, #0x0000
	    mov r10, #0x0000
	    mov r11, #0x0000
	    mov r12, #0x0000
	    mrs r1, cpsr
	    msr spsr_cxsf, r1 
	    ; Switch to IRQ mode (M = 10010)
	    cps #18
	    mov lr, r0
	    mrs r1,cpsr
	    msr spsr_cxsf, r1 	    
	    ; Switch to Abort mode (M = 10111)
	    cps #23
	    mov lr, r0
	    mrs r1,cpsr
	    msr spsr_cxsf, r1 	    
	    ; Switch to Undefined Instruction Mode (M = 11011)
	    cps #27
	    mov lr, r0
	    mrs r1,cpsr
	    msr spsr_cxsf, r1 	    
	    ; Switch back to Supervisor Mode (M = 10011)
	    cps #19


        mrc   p15,     #0x00,      r2,       c1, c0, #0x02
        orr   r2,      r2,         #0xF00000
        mcr   p15,     #0x00,      r2,       c1, c0, #0x02
        mov   r2,      #0x40000000
        fmxr  fpexc,   r2

		fmdrr d0,         r1,     r1
        fmdrr d1,         r1,     r1
        fmdrr d2,         r1,     r1
        fmdrr d3,         r1,     r1
        fmdrr d4,         r1,     r1
        fmdrr d5,         r1,     r1
        fmdrr d6,         r1,     r1
        fmdrr d7,         r1,     r1
        fmdrr d8,         r1,     r1
        fmdrr d9,         r1,     r1
        fmdrr d10,        r1,     r1
        fmdrr d11,        r1,     r1
        fmdrr d12,        r1,     r1
        fmdrr d13,        r1,     r1
        fmdrr d14,        r1,     r1
        fmdrr d15,        r1,     r1
        bl    next1
next1
        bl    next2
next2
        bl    next3
next3
        bl    next4
next4
        bx    r0

    


;-------------------------------------------------------------------------------
; Initialize Stack Pointers

    export     _coreInitStackPointer_
    

_coreInitStackPointer_

        cps   #17
        ldr   sp,       fiqSp
        cps   #18
        ldr   sp,       irqSp
        cps   #23
        ldr   sp,       abortSp
        cps   #27
        ldr   sp,       undefSp
        cps   #31
        ldr   sp,       userSp
        cps   #19
        ldr   sp,       svcSp
        bx    lr

userSp  dcd 0x08000000+0x00001000
svcSp   dcd 0x08000000+0x00001000+0x00000100
fiqSp   dcd 0x08000000+0x00001000+0x00000100+0x00000100
irqSp   dcd 0x08000000+0x00001000+0x00000100+0x00000100+0x00000100
abortSp dcd 0x08000000+0x00001000+0x00000100+0x00000100+0x00000100+0x00000100
undefSp dcd 0x08000000+0x00001000+0x00000100+0x00000100+0x00000100+0x00000100+0x00000100

    


;-------------------------------------------------------------------------------
; Enable VFP Unit

    export     _coreEnableVfp_
    

_coreEnableVfp_

        stmfd sp!, {r0}
        mrc   p15,     #0x00,      r0,       c1, c0, #0x02
        orr   r0,      r0,         #0xF00000
        mcr   p15,     #0x00,      r0,       c1, c0, #0x02
        mov   r0,      #0x40000000
        fmxr  fpexc,   r0
        ldmfd sp!, {r0}
        bx    lr

    

;-------------------------------------------------------------------------------
; Enable Event Bus Export

    export     _coreEnableEventBusExport_
    

_coreEnableEventBusExport_

        stmfd sp!, {r0}
        mrc   p15, #0x00, r0,         c9, c12, #0x00
        orr   r0,  r0,    #0x10
        mcr   p15, #0x00, r0,         c9, c12, #0x00
        ldmfd sp!, {r0}
        bx    lr

    


;-------------------------------------------------------------------------------
; Disable Event Bus Export

    export     _coreDisableEventBusExport_
    

_coreDisableEventBusExport_

        stmfd sp!, {r0}
        mrc   p15, #0x00, r0,         c9, c12, #0x00
        bic   r0,  r0,    #0x10
        mcr   p15, #0x00, r0,         c9, c12, #0x00
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Enable RAM ECC Support

    export     _coreEnableRamEcc_
    

_coreEnableRamEcc_

        stmfd sp!, {r0}
        mrc   p15, #0x00, r0,         c1, c0,  #0x01
        orr   r0,  r0,    #0x0C000000
        mcr   p15, #0x00, r0,         c1, c0,  #0x01
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Disable RAM ECC Support

    export     _coreDisableRamEcc_
    

_coreDisableRamEcc_

        stmfd sp!, {r0}
        mrc   p15, #0x00, r0,         c1, c0,  #0x01
        bic   r0,  r0,    #0x0C000000
        mcr   p15, #0x00, r0,         c1, c0,  #0x01
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Enable Flash ECC Support

    export     _coreEnableFlashEcc_
    

_coreEnableFlashEcc_

        stmfd sp!, {r0}
        mrc   p15, #0x00, r0,         c1, c0,  #0x01
        orr   r0,  r0,    #0x02000000
        mcr   p15, #0x00, r0,         c1, c0,  #0x01
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Disable Flash ECC Support

    export     _coreDisableFlashEcc_
    

_coreDisableFlashEcc_

        stmfd sp!, {r0}
        mrc   p15, #0x00, r0,         c1, c0,  #0x01
        bic   r0,  r0,    #0x02000000
        mcr   p15, #0x00, r0,         c1, c0,  #0x01
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Enable Offset via Vic controller

    export     _coreEnableIrqVicOffset_
    

_coreEnableIrqVicOffset_

        stmfd sp!, {r0}
        mrc   p15, #0, r0,         c1, c0,  #0
        orr   r0,  r0,    #0x01000000
        mcr   p15, #0, r0,         c1, c0,  #0
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Get data fault status register

    export     _coreGetDataFault_
    

_coreGetDataFault_

        mrc   p15, #0, r0, c5, c0,  #0
        bx    lr

    


;-------------------------------------------------------------------------------
; Clear data fault status register

    export     _coreClearDataFault_
    

_coreClearDataFault_

        stmfd sp!, {r0}
        mov   r0,  #0
        mcr   p15, #0, r0, c5, c0,  #0
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Get instruction fault status register

    export     _coreGetInstructionFault_
    

_coreGetInstructionFault_

        mrc   p15, #0, r0, c5, c0, #1
        bx    lr

    


;-------------------------------------------------------------------------------
; Clear instruction fault status register

    export     _coreClearInstructionFault_
    

_coreClearInstructionFault_

        stmfd sp!, {r0}
        mov   r0,  #0
        mcr   p15, #0, r0, c5, c0, #1
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Get data fault address register

    export     _coreGetDataFaultAddress_
    

_coreGetDataFaultAddress_

        mrc   p15, #0, r0, c6, c0,  #0
        bx    lr

    


;-------------------------------------------------------------------------------
; Clear data fault address register

    export     _coreClearDataFaultAddress_
    

_coreClearDataFaultAddress_

        stmfd sp!, {r0}
        mov   r0,  #0
        mcr   p15, #0, r0, c6, c0,  #0
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Get instruction fault address register

    export     _coreGetInstructionFaultAddress_
    

_coreGetInstructionFaultAddress_

        mrc   p15, #0, r0, c6, c0, #2
        bx    lr

    


;-------------------------------------------------------------------------------
; Clear instruction fault address register

    export     _coreClearInstructionFaultAddress_
    

_coreClearInstructionFaultAddress_

        stmfd sp!, {r0}
        mov   r0,  #0
        mcr   p15, #0, r0, c6, c0, #2
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Get auxiliary data fault status register

    export     _coreGetAuxiliaryDataFault_
    

_coreGetAuxiliaryDataFault_

        mrc   p15, #0, r0, c5, c1, #0
        bx    lr

    


;-------------------------------------------------------------------------------
; Clear auxiliary data fault status register

    export     _coreClearAuxiliaryDataFault_
    

_coreClearAuxiliaryDataFault_

        stmfd sp!, {r0}
        mov   r0,  #0
        mcr   p15, #0, r0, c5, c1, #0
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Get auxiliary instruction fault status register

    export     _coreGetAuxiliaryInstructionFault_
    

_coreGetAuxiliaryInstructionFault_

        mrc   p15, #0, r0, c5, c1, #1
        bx    lr

    

;-------------------------------------------------------------------------------
; Clear auxiliary instruction fault status register

    export     _coreClearAuxiliaryInstructionFault_
    

_coreClearAuxiliaryInstructionFault_

        stmfd sp!, {r0}
        mov   r0,  #0
        mrc   p15, #0, r0, c5, c1, #1
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Disable interrupts - R4 IRQ & FIQ

        export _disable_interrupt_
        
		
_disable_interrupt_

        cpsid if
        bx    lr
		
        

;-------------------------------------------------------------------------------
; Disable FIQ interrupt

        export _disable_FIQ_interrupt_
        
		
_disable_FIQ_interrupt_

        cpsid f
        bx    lr
		
        

;-------------------------------------------------------------------------------
; Disable FIQ interrupt

        export _disable_IRQ_interrupt_    
        
		
_disable_IRQ_interrupt_

        cpsid i
        bx    lr
		
        
		
;-------------------------------------------------------------------------------
; Enable interrupts - R4 IRQ & FIQ

       export _enable_interrupt_
       

_enable_interrupt_

        cpsie if
        bx    lr
		
        

		
;-------------------------------------------------------------------------------
; Clear ESM CCM errorss

       export _esmCcmErrorsClear_
       

_esmCcmErrorsClear_

        stmfd sp!, {r0-r2}		
        ldr   r0, ESMSR1_REG	; load the ESMSR1 status register address
        ldr   r2, ESMSR1_ERR_CLR
        str   r2, [r0]	 	; clear the ESMSR1 register

        ldr   r0, ESMSR2_REG	; load the ESMSR2 status register address
        ldr   r2, ESMSR2_ERR_CLR
        str   r2, [r0]	 	; clear the ESMSR2 register

        ldr   r0, ESMSSR2_REG	; load the ESMSSR2 status register address
        ldr   r2, ESMSSR2_ERR_CLR
        str   r2, [r0]	 	    ; clear the ESMSSR2 register

        ldr   r0, ESMKEY_REG	; load the ESMKEY register address
        mov   r2, #0x5             ; load R2 with 0x5
        str   r2, [r0]	 	    ; clear the ESMKEY register

        ldr   r0, VIM_INTREQ	; load the INTREQ register address
        ldr   r2, VIM_INT_CLR
        str   r2, [r0]	 	; clear the INTREQ register
        ldr   r0, CCMR4_STAT_REG	; load the CCMR4 status register address
        ldr   r2, CCMR4_ERR_CLR
        str   r2, [r0]	 	; clear the CCMR4 status register
        ldmfd sp!, {r0-r2}        
        bx    lr

ESMSR1_REG        dcd 0xFFFFF518
ESMSR2_REG        dcd 0xFFFFF51C
ESMSR3_REG        dcd 0xFFFFF520
ESMKEY_REG        dcd 0xFFFFF538
ESMSSR2_REG       dcd 0xFFFFF53C
CCMR4_STAT_REG    dcd 0xFFFFF600
ERR_CLR_WRD       dcd 0xFFFFFFFF
CCMR4_ERR_CLR     dcd 0x00010000
ESMSR1_ERR_CLR    dcd 0x80000000
ESMSR2_ERR_CLR    dcd 0x00000004
ESMSSR2_ERR_CLR   dcd 0x00000004
VIM_INT_CLR       dcd 0x00000001
VIM_INTREQ        dcd 0xFFFFFE20

        	
		


    end

;-------------------------------------------------------------------------------

