;-------------------------------------------------------------------------------
; sys_intvecs.asm
;
; (c) Texas Instruments 2009-2012, All rights reserved.
;

    area intvecs, code, readonly


;-------------------------------------------------------------------------------
; import reference for interrupt routines

    import _c_int00
    import _undef
    import _prefetch
    import _data


;-------------------------------------------------------------------------------
; interrupt vectors

        b   _c_int00
        b   _undef
_svc		
        b   _svc
        b   _prefetch
        b   _data
reservedEntry
        b   reservedEntry
        ldr pc,[pc,#-0x1b0]
        ldr pc,[pc,#-0x1b0]

    end
;-------------------------------------------------------------------------------
