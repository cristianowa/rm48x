;-------------------------------------------------------------------------------
; sys_memory.asm
;
; (c) Texas Instruments 2009-2012, All rights reserved.
;

    section .text:CODE
    arm


;-------------------------------------------------------------------------------
; Initialize memory

    public     _memoryInit_
    

_memoryInit_

        stmfd sp!, {r0-r2}        
        ldr   r2, regMinitGcr    ; MINITGCR register pointer 
        mov   r0, #0xA
        str   r0, [r2]
        ldr   r0, ramInitMask     ; load RAM initialization mask
        str   r0, [r2, #4]
mloop
        ldr   r1, [r2, #12]
        tst   r1, #0x100
        beq   mloop
        mov   r0, #5
        str   r0, [r2]
        ldmfd sp!, {r0-r2}		
        bx    lr
    
ramInitMask   dcd 0x1C57F
regMinitGcr   dcd 0xFFFFFF5C

    


    end

;-------------------------------------------------------------------------------

