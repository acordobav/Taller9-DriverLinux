#include "lfsr.h"

int extract_bit(int number, int position)
{
    int mask = 1 << position;
    int masked_number = number & mask;
    int bit = masked_number >> position;

    return bit;
}

int lfsr_16(int number)
{
    int bit_16 = extract_bit(number, 0);
    int bit_14 = extract_bit(number, 2);
    int bit_13 = extract_bit(number, 3);
    int bit_11 = extract_bit(number, 5);

    int feedback = bit_16 ^ bit_14 ^ bit_13 ^ bit_11;
    feedback = feedback << 15;

    int new_number = feedback | (number >> 1);

    return new_number;
}
