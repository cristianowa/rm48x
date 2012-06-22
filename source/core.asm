;-------------------------------------------------------------------------------
; Initialize Stack Pointers


   ; SECTION .text:CODE:NOROOT(2)
     area |.text|, code
    
    export  _coreBackupStackPointer_
    export  _coreRestoreStackPointer_
    export _svc_entry_
    export _svc_exit_
    export _svc
	export _wfi

  import     ccm_enable_error_cont

_svc_entry_
        swi _svc

_svc
  ;      stmfd       sp!, {r0-r12,lr} 
  ;      ldrb         r0, [lr,#-1]  
        blx ccm_enable_error_cont

_svc_exit_
   ;     ldmfd   sp!, {r0-r12,pc}
        bx    lr
		
_wfi
		wfi

user_bkup   DCD 0x08001000
svc_bkup    DCD 0x08001004
fiq_bkup    DCD 0x08001008
irq_bkup    DCD 0x0800100C
abort_bkup  DCD 0x08001010
undef_bkup  DCD 0x08001014
r0_bkup     DCD 0x08001018
r1_bkup     DCD 0x0800101C
r2_bkup     DCD 0x08001020


    END
    
    