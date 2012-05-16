;-------------------------------------------------------------------------------
; sys_intvecs.asm
;
; (c) Texas Instruments 2009-2012, All rights reserved.
;

    section .intvecs:CODE


;-------------------------------------------------------------------------------
; import reference for interrupt routines

    import _c_int00
    import vPortYieldProcessor
    import _isrStub


;-------------------------------------------------------------------------------
; interrupt vectors

        b   _c_int00
undefEntry
        b   undefEntry
        b   vPortYieldProcessor
prefetchEntry
        b   prefetchEntry
dataEntry
        b   dataEntry
reservedEntry
        b   reservedEntry
        b   _isrStub
        ldr pc,[pc,#-0x1b0]

    end
;-------------------------------------------------------------------------------
