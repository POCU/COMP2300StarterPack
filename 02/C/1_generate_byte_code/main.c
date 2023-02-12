#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SIZE (0x8000)

int main()
{
    const char* FILENAME = "program.bin";
    FILE* outfile;
    char bin_out[SIZE] = { 0, };
    size_t program_size;

    /* This is your program */
    const char program[] = {
        0xEA,
        0x4C, 0x00, 0x80
    };

    program_size = sizeof(program) / sizeof(char);

    assert(program_size < 0x7FFC);

    memcpy(bin_out, program, program_size);

    bin_out[0x7FFC] = 0x00;
    bin_out[0x7FFD] = 0x80;

    outfile = fopen(FILENAME, "wb");
    
    if (outfile == NULL) {
        fprintf(stderr, "cannot open outfile");

        return -1;
    }
    
    fwrite(bin_out, sizeof(char), SIZE, outfile);
    
    fclose(outfile);
    
    return 0;
}