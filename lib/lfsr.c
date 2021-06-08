// #include "lfsr.h"
#include "../include/lfsr.h"

int extract_bit(int number, int position)
{
    int mask = 1 << position;
    int masked_number = number & mask;
    int bit = masked_number >> position;

    return bit;
}

int lfsr_16(int seed)
{
    int bit_16 = extract_bit(seed, 0);
    int bit_14 = extract_bit(seed, 2);
    int bit_13 = extract_bit(seed, 3);
    int bit_11 = extract_bit(seed, 5);

    int feedback = bit_16 ^ bit_14 ^ bit_13 ^ bit_11;
    feedback = feedback << 15;

    int new_number = feedback | (seed >> 1);

    return new_number;
}

void init_timer()
{
    FILE *fptr = fopen(timer_file, "w");

    if (fptr == NULL)
    {
        printf("Error reading /dev/timer\n");
        exit(1);
    }

    char *one = "1";
    fwrite(one, 1, 1, fptr);

    fclose(fptr);
}

void end_timer()
{
    FILE *fptr = fopen(timer_file, "w");

    if (fptr == NULL)
    {
        printf("Error reading /dev/timer\n");
        exit(1);
    }

    char *one = "0";
    fwrite(one, 1, 1, fptr);

    fclose(fptr);
}

int read_timer()
{
    FILE *fptr = fopen(timer_file, "r");

    // Number of bytes necessary to read the whole file
    fseek(fptr, 0, SEEK_END);
    long fsize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    // Memory allocation
    char *content = malloc(fsize + 1);

    // Reading
    fread(content, 1, fsize, fptr);

    fclose(fptr);

    int number = strtol(content, NULL, 10);
    free(content);

    return number;
}
