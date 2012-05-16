;-------------------------------------------------------------------------------
; sys_pmu.asm
;
; (c) Texas Instruments 2012, All rights reserved.
;

    section .text:CODE
    arm


;-------------------------------------------------------------------------------
; Initialize Pmu
; Note: It will reset all counters

    public     _pmuInit_
    

_pmuInit_

        stmfd sp!, {r0}
        ; set control register
        mrc   p15, #0, r0, c9, c12, #0 
        orr   r0,  r0, #(1 << 4) + 6 + 1
        mcr   p15, #0, r0, c9, c12, #0
        ; clear flags
		mov   r0,  #0
		mcr   p15, #0, r0, c9, c12, #3 
        ; select counter 0 event
        mcr   p15, #0, r0, c9, c12, #5 ; select counter
        mov   r0,  #0x11
        mcr   p15, #0, r0, c9, c13, #1 ; select event
        ; select counter 1 event
		mov   r0,  #1
        mcr   p15, #0, r0, c9, c12, #5 ; select counter
        mov   r0,  #0x11
        mcr   p15, #0, r0, c9, c13, #1 ; select event
        ; select counter 2 event
		mov   r0,  #2
        mcr   p15, #0, r0, c9, c12, #5 ; select counter
        mov   r0,  #0x11
        mcr   p15, #0, r0, c9, c13, #1 ; select event
        ldmfd sp!, {r0}
        bx    lr

    


;-------------------------------------------------------------------------------
; Enable Counters Global [Cycle, Event [0..2]]
; Note: It will reset all counters

    public     _pmuEnableCountersGlobal_
    

_pmuEnableCountersGlobal_

        stmfd sp!, {r0}
        mrc   p15, #0, r0, c9, c12, #0 
        orr   r0,  r0, #7
        mcr   p15, #0, r0, c9, c12, #0
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Disable Counters Global [Cycle, Event [0..2]]

    public     _pmuDisableCountersGlobal_
    

_pmuDisableCountersGlobal_

        stmfd sp!, {r0}
        mrc   p15, #0, r0, c9, c12, #0 
        bic   r0,  r0, #1
        mcr   p15, #0, r0, c9, c12, #0
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Reset Cycle Counter

    public     _pmuResetCycleCounter_
    

_pmuResetCycleCounter_

        stmfd sp!, {r0}
        mrc   p15, #0, r0, c9, c12, #0 
        orr   r0,  r0, #4
        mcr   p15, #0, r0, c9, c12, #0
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Reset Event Counters [0..2]

    public     _pmuResetEventCounters_
    

_pmuResetEventCounters_

        stmfd sp!, {r0}
        mrc   p15, #0, r0, c9, c12, #0 
        orr   r0,  r0, #2
        mcr   p15, #0, r0, c9, c12, #0
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Reset Cycle Counter abd Event Counters [0..2]

    public     _pmuResetCounters_
    

_pmuResetCounters_

        stmfd sp!, {r0}
        mrc   p15, #0, r0, c9, c12, #0 
        orr   r0,  r0, #6
        mcr   p15, #0, r0, c9, c12, #0
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Start Counters [Cycle, 0..2]

    public     _pmuStartCounters_
    

_pmuStartCounters_

        stmfd sp!, {r0}
        mcr   p15, #0, r0, c9, c12, #1
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Stop Counters [Cycle, 0..2]

    public     _pmuStopCounters_
    

_pmuStopCounters_

        stmfd sp!, {r0}
        mcr   p15, #0, r0, c9, c12, #2
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Set Count event

    public     _pmuSetCountEvent_
    

_pmuSetCountEvent_
 
        stmfd sp!, {r0}
        lsr   r0,  r0, #1
        mcr   p15, #0, r0, c9, c12, #5 ; select counter
        mcr   p15, #0, r1, c9, c13, #1 ; select event
        ldmfd sp!, {r0}		
        bx    lr

    

;-------------------------------------------------------------------------------
; Get Cycle Count

    public     _pmuGetCycleCount_
    

_pmuGetCycleCount_

        mrc   p15, #0, r0, c9, c13, #0
        bx    lr

    

;-------------------------------------------------------------------------------
; Get Event Counter Count Value

    public     _pmuGetEventCount_
    

_pmuGetEventCount_

        lsr   r0,  r0, #1
        mcr   p15, #0, r0, c9, c12, #5 ; select counter
        mrc   p15, #0, r0, c9, c13, #2 ; read event counter
        bx    lr

    

;-------------------------------------------------------------------------------
; Get Overflow Flags

    public     _pmuGetOverflow_
    

_pmuGetOverflow_

        mrc   p15, #0, r0, c9, c12, #3 ; read overflow
		mov   r1,  #0
		mcr   p15, #0, r1, c9, c12, #3 ; clear flags
        bx    lr

    

    end

;-------------------------------------------------------------------------------

