    .PROCESSOR 6502
    .ORG $8000

end:
	jmp end

    .ORG $FFFC,0
    .WORD $8000
    .WORD $0000