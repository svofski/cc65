;
; clock_t clock (void);
;

        .include        "pce.inc"
        .include        "extzp.inc"

        .export         _clock
        .forceimport    ticktock
        .importzp       sreg
        .constructor    initclock


.proc   _clock

        lda     tickcount+3
        sta     sreg+1
        lda     tickcount+2
        sta     sreg
        ldx     tickcount+1
        lda     tickcount
        rts

.endproc

        .segment        "INIT"
initclock:
        lda     #0
        ldx     #3
@lp:    sta     tickcount,x
        dex
        bpl     @lp
        rts
