    .PROCESSOR 6502
    .ORG $8000

    .INCLUDE "utils/utils.asm"

    .ORG $FFFC,0
    .WORD $8000
    .WORD $0000