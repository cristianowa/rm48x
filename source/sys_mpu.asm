;-------------------------------------------------------------------------------
; sys_mpu.asm
;
; (c) Texas Instruments 2012, All rights reserved.
;

    section .text:CODE
    arm


;-------------------------------------------------------------------------------
; Initalize Mpu

    public     _mpuInit_
    

_mpuInit_
        stmfd sp!, {r0}
        ; Disable mpu
        mrc   p15, #0, r0, c1, c0, #0
        bic   r0,  r0, #1
        dsb
        mcr   p15, #0, r0, c1, c0, #0
        isb
        ; Disable background region
        mrc   p15, #0, r0,      c1, c0, #0
        bic   r0,  r0, #0x20000
        mcr   p15, #0, r0,      c1, c0, #0
        ; Setup region 1
        mov   r0,  #0
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r1Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0008
        orr   r0,  r0,    #0x1000
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((1 << 15) + (1 << 14) + (1 << 13) + (1 << 12) + (1 << 11) + (1 << 10) + (1 <<  9) + (1 <<  8) + (0x1F << 1) + (1)) 
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 2
        mov   r0,  #1
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r2Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0008
        orr   r0,  r0,    #0x0600
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x15 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region  
        mov   r0,  #2
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r3Base
        mcr   p15, #0,    r0, c6, c1, #0    
        mov   r0,  #0x0008
        orr   r0,  r0,    #0x0300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x11 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 4
        mov   r0,  #3
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r4Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0008
        orr   r0,  r0,    #0x0300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x11 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 5
        mov   r0,  #4
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r5Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0000
        orr   r0,  r0,    #0x0300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((1 << 15) + (1 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x19 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 6
        mov   r0,  #5
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r6Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0000
        orr   r0,  r0,    #0x0300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x1A << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 7
        mov   r0,  #6
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r7Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0008
        orr   r0,  r0,    #0x1200
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x16 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 8
        mov   r0,  #7
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r8Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0010
        orr   r0,  r0,    #0x1300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x17 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 9
        mov   r0,  #8
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r9Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0010
        orr   r0,  r0,    #0x1300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x08 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 10
        mov   r0,  #9
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r10Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0010
        orr   r0,  r0,    #0x1300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((0 << 15) + (0 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x17 << 1) + (1))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 11
        mov   r0,  #10
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r11Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0008
        orr   r0,  r0,    #0x1100
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((1 << 15) + (1 << 14) + (1 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x0A << 1) + (0))
        mcr   p15, #0,    r0, c6, c1, #2
        ; Setup region 12
        mov   r0,  #11
        mcr   p15, #0,    r0, c6, c2, #0
        ldr   r0,  r12Base
        mcr   p15, #0,    r0, c6, c1, #0
        mov   r0,  #0x0008
        orr   r0,  r0,    #0x1300
        mcr   p15, #0,    r0, c6, c1, #4
        movw  r0,  #((1 << 15) + (1 << 14) + (0 << 13) + (0 << 12) + (0 << 11) + (0 << 10) + (0 <<  9) + (0 <<  8) + (0x15 << 1) + (0))
        mcr   p15, #0,    r0, c6, c1, #2


        ; Enable mpu background region
        mrc   p15, #0, r0,      c1, c0, #0
        orr   r0,  r0, #0x20000
        mcr   p15, #0, r0,      c1, c0, #0
        ; Enable mpu
        mrc   p15, #0, r0, c1, c0, #0
        orr   r0,  r0, #1
        dsb
        mcr   p15, #0, r0, c1, c0, #0
        isb
        ldmfd sp!, {r0}
        bx    lr

r1Base  dcd 0x00000000  
r2Base  dcd 0x00000000  
r3Base  dcd 0x08000000  
r4Base  dcd 0x08400000  
r5Base  dcd 0x60000000  
r6Base  dcd 0x80000000  
r7Base  dcd 0xF0000000  
r8Base  dcd 0xFC000000  
r9Base  dcd 0xFE000000  
r10Base  dcd 0xFF000000  
r11Base  dcd 0x08001000  
r12Base  dcd 0x20000000  

    


;-------------------------------------------------------------------------------
; Enable Mpu

    public     _mpuEnable_
    

_mpuEnable_

        stmfd sp!, {r0}
        mrc   p15, #0, r0, c1, c0, #0
        orr   r0,  r0, #1
        dsb
        mcr   p15, #0, r0, c1, c0, #0
        isb
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Disable Mpu

    public     _mpuDisable_
    

_mpuDisable_

        stmfd sp!, {r0}
        mrc   p15, #0, r0, c1, c0, #0
        bic   r0,  r0, #1
        dsb
        mcr   p15, #0, r0, c1, c0, #0
        isb
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Enable Mpu background region

    public     _mpuEnableBackgroundRegion_
    

_mpuEnableBackgroundRegion_

        stmfd sp!, {r0}
        mrc   p15, #0, r0,      c1, c0, #0
        orr   r0,  r0, #0x20000
        mcr   p15, #0, r0,      c1, c0, #0
        ldmfd sp!, {r0}		
        bx    lr

    


;-------------------------------------------------------------------------------
; Disable Mpu background region

    public     _mpuDisableBackgroundRegion_
    

_mpuDisableBackgroundRegion_

        stmfd sp!, {r0}
        mrc   p15, #0, r0,      c1, c0, #0
        bic   r0,  r0, #0x20000
        mcr   p15, #0, r0,      c1, c0, #0
        ldmfd sp!, {r0}
        bx    lr

    


;-------------------------------------------------------------------------------
; Returns number of implemented Mpu regions

    public     _mpuGetNumberOfRegions_
    

_mpuGetNumberOfRegions_

        mrc   p15, #0, r0,      c0, c0, #4
        uxtb  r0,  r0, ROR #8
        bx    lr

    


;-------------------------------------------------------------------------------
; Returns the type of the implemented mpu regions

    public     _mpuAreRegionsSeparate_
    

_mpuAreRegionsSeparate_

        mrc   p15, #0, r0,      c0, c0, #4
        uxtb  r0,  r0
        bx    lr

    


;-------------------------------------------------------------------------------
; Set mpu region number

    public     _mpuSetRegion_
    

_mpuSetRegion_

        mcr   p15, #0, r0, c6, c2, #0
        bx    lr

    


;-------------------------------------------------------------------------------
; Get mpu region number

    public     _mpuGetRegion_
    

_mpuGetRegion_

        mrc   p15, #0, r0, c6, c2, #0
        bx    lr

    


;-------------------------------------------------------------------------------
; Set base address

    public     _mpuSetRegionBaseAddress_
    

_mpuSetRegionBaseAddress_

        mcr   p15, #0, r0, c6, c1, #0
        bx    lr

    


;-------------------------------------------------------------------------------
; Get base address

    public     _mpuGetRegionBaseAddress_
    

_mpuGetRegionBaseAddress_

        mrc   p15, #0, r0, c6, c1, #0
        bx    lr

    


;-------------------------------------------------------------------------------
; Set type and permission

    public     _mpuSetRegionTypeAndPermission_
    

_mpuSetRegionTypeAndPermission_

        orr   r0,  r0, r1
        mcr   p15, #0, r0, c6, c1, #4
        bx    lr

    


;-------------------------------------------------------------------------------
; Get type

    public     _mpuGetRegionType_
    

_mpuGetRegionType_

        mrc   p15, #0, r0,     c6, c1, #4
        bic   r0,  r0, #0xFF00
        bx    lr

    


;-------------------------------------------------------------------------------
; Get permission

    public     _mpuGetRegionPermission_
    

_mpuGetRegionPermission_

        mrc   p15, #0, r0,   c6, c1, #4
        bic   r0,  r0, #0xFF
        bx    lr

    


;-------------------------------------------------------------------------------
; Set region size register value

    public     _mpuSetRegionSizeRegister_
    

_mpuSetRegionSizeRegister_

        mcr   p15, #0, r0, c6, c1, #2
        bx    lr

    

    end

;-------------------------------------------------------------------------------

