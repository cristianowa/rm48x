;-------------------------------------------------------------------------------
; Initialize Stack Pointers


    SECTION .text:CODE:NOROOT(2)
    
    
    PUBLIC  _coreBackupStackPointer_
    PUBLIC  _coreRestoreStackPointer_
    PUBLIC _svc_entry_
    PUBLIC _svc_exit_
    PUBLIC _svc

  import     ccm_enable_error_cont

_coreBackupStackPointer_:

        ldr   r0,       r1_bkup        
        str   r1,       [r0]
        ldr   r0,       r2_bkup        
        str   r2,       [r0]

        msr   cpsr_c,   #0xD1
        ldr   r0,       fiq_bkup        
        str   sp,       [r0]
        msr   cpsr_c,   #0xD2
        ldr   r0,       irq_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xD7
        ldr   r0,       abort_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xDB
        ldr   r0,       undef_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xDF
        ldr   r0,       user_bkup
        str   sp,       [r0]
        msr   cpsr_c,   #0xD3
        ldr   r0,       svc_bkup
        str   sp,       [r0]
        bx    lr


;-------------------------------------------------------------------------------
; Recover Stack Pointers

;    .global  _coreRestoreStackPointer_
;    .asmfunc

_coreRestoreStackPointer_:

        ldr   r0,       r1_bkup        
        ldr   r1,       [r0]
        ldr   r0,       r2_bkup        
        ldr   r2,       [r0]

        msr   cpsr_c,   #0xD1
        ldr   r0,       fiq_bkup        
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xD2
        ldr   r0,       irq_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xD7
        ldr   r0,       abort_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xDB
        ldr   r0,       undef_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xDF
        ldr   r0,       user_bkup
        ldr   sp,       [r0]
        msr   cpsr_c,   #0xD3
        ldr   r0,       svc_bkup
        ldr   sp,       [r0]
;
        bx    lr

_svc_entry_:
        swi _svc

_svc:
  ;      stmfd       sp!, {r0-r12,lr} 
  ;      ldrb         r0, [lr,#-1]  
        blx ccm_enable_error_cont

_svc_exit_:
   ;     ldmfd   sp!, {r0-r12,pc}
        bx    lr

user_bkup:   DCD 0x08001000
svc_bkup:    DCD 0x08001004
fiq_bkup:    DCD 0x08001008
irq_bkup:    DCD 0x0800100C
abort_bkup:  DCD 0x08001010
undef_bkup:  DCD 0x08001014
r0_bkup:     DCD 0x08001018
r1_bkup:     DCD 0x0800101C
r2_bkup:     DCD 0x08001020


    END
    
    