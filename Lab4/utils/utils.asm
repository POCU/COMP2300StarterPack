    ; assert
    .MACRO assert ; (addr,value)
        .IFCONST POBS
		    .BYTE $FF
		    .WORD {1}
		    .BYTE {2}
        .ELSE
            lda {1}
            cmp {2}
            bne .success
.fail:
            lda $BAAD
            jmp .fail
.success:
        .ENDIF
    .ENDM

    ; terminate program
    .MACRO termin
end:
        jmp end
    .ENDM
