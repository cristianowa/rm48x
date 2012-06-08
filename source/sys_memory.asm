;-------------------------------------------------------------------------------
; sys_memory.asm
;
; (c) Texas Instruments 2009-2012, All rights reserved.
;

    section .text:CODE
    arm


;-------------------------------------------------------------------------------
; Run Memory Test

    public     _memoryTest_
    import     memoryPort0TestFailNotification
    import     memoryPort1TestFailNotification
    

_memoryTest_

        stmfd sp!, {r0-r12}
        ldr   r12, regPbist    ; Pbist register frame base pointer 
        ldr   r11, palgo       ; Algo array pointer
        ldr   r10, prinfo      ; Rinfo array pointer
        ldr   r9,  regMstGcr   ; MstGcr register pointer 
        mov   r8,  #17         ; Algo loop counter
aloop 
        subs  r8, r8, #1
        beq   pbistEnd
        ldr   r4, [r11], #4    ; load current algo selection
        ldr   r5, [r10], #4    ; load current info selection
        cmp   r4, #0
        beq   aloop
        mov   r7, #1
        str   r7, [r9, #8]    ; enable BIST controller
        movw  r7, #0x10A
        str   r7, [r9]        ; set ROMCLK divider and enable PBIST Test
        nop                   ; wait for 32 VBUS cycles
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mov   r7, #3
        str   r7, [r12, #0x80] ; Pbist PACT register
        str   r4, [r12, #0xC4] ; Select algorithm    
        str   r5, [r12, #0xC8] ; Select test Rams   
        mov   r6, #0
        str   r6, [r12, #0xCC] ; Select test Rams    
        str   r6, [r12, #0x88] ; Disable override    
        str   r7, [r12, #0xC0] ; Use algorithm and rinfo from ROM 
        mov   r7, #1
        str   r7, [r9,  #0x10] ; Clear Pbist done flag
        mov   r6, #0x14
        str   r6, [r12, #0x64] ; Enable ROM based testing and start test  
dloop  
        ldr   r6, [r9, #0x10] ; Load Pbist done flag
        cmp   r6, #0
        beq   dloop        
        ldr   r4, [r12, #0x90] ; read Pbist FSRF0
        ldr   r5, [r12, #0x94] ; read Pbist FSRF1
        adds  r6, r4, r5, lsl #1
        beq   dTest
        ldrb  r0, [r12, #0x60] ; read Pbist RAMT 
        ldrb  r1, [r12, #0x61] ; read Pbist RAMT 
        tst   r4, #1
port0          
        ldr   r2, [r12, #0xA0] ; read Pbist FSRA0 
        ldr   r3, [r12, #0xA8] ; read Pbist FSRDL0 
        beq   port1
        stmfd sp!, {r0-r12, lr}
        blx   memoryPort0TestFailNotification
        ldmfd sp!, {r0-r12, lr}
port1
        ldr   r2, [r12, #0xA4] ; read Pbist FSRA1 
        ldr   r3, [r12, #0xB0] ; read Pbist FSRDL1 
        tst   r5, #1
        beq   resume
        stmfd sp!, {r0-r12, lr}
        blx   memoryPort1TestFailNotification
        ldmfd sp!, {r0-r12, lr}
resume
        mov   r7, #1
        str   r7, [r9,  #0x10] ; Clear Pbist done flag
        mov   r6, #2
        str   r6, [r12, #0x6C] ; resume Pbist test
        bne   dloop
dTest        
        movw  r4, #0x105
        str   r4, [r9]        ; disable PBIST Test
        b     aloop
pbistEnd
        mov   r7, #0
        str   r7, [r12, #0x80] ; Disable Pbist and ROM slock in PACT register
        ldmfd sp!, {r0-r12}
        bx    lr

regMstGcr     dcd 0xFFFFFF58
regPbist      dcd 0xFFFFE500

algo
              dcd 1<<0
              dcd 1<<1
              dcd 1<<2
              dcd 1<<3
              dcd 1<<4
              dcd 1<<5
              dcd 1<<6
              dcd 1<<7
              dcd 1<<8
              dcd 1<<9
              dcd 1<<10
              dcd 1<<11
              dcd 1<<12
              dcd 1<<13
              dcd 1<<14
              dcd 1<<15
palgo         dcd algo

rinfo
	          dcd 0x00000003
	          dcd 0x00000003
	          dcd 0x02CEFFDC
	          dcd 0x0D310020
	          dcd 0x02CEFFDC
	          dcd 0x0D310020
	          dcd 0x02CEFFDC
	          dcd 0x0D310020
	          dcd 0x02CEFFDC
	          dcd 0x0D310020
	          dcd 0x02CEFFDC
	          dcd 0x0D310020
	          dcd 0x028AE5DC
	          dcd 0x0D310020
	          dcd 0x00441A00
	          dcd 0x00441A00
prinfo        dcd rinfo    	

    


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

