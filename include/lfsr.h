#include <stdio.h>
#include <stdlib.h>

char* timer_file = "../dev/timer";

/**
 * Extracts de value of a specific bit in a number
**/
int extract_bit(int number, int position);

/**
 * Apply LSFR pseudo-random algorithm for numbers of 16 bits
**/
int lfsr_16(int number);

/**
 * Writes 1 in /dev/timer file
**/
void init_timer();

/**
 * Writes 0 in /dev/timer file
**/
void end_timer();


int read_timer();

