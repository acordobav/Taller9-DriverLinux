#include <lfsr.h>


int main() {
    int number = 5030;
    printf("Seed: %d\n", number);

    for (int i = 0; i < 15; i++)
    {
        number = lfsr_16(number);
        printf("%d - Random: %d\n", i, number);
    }
    
    return 0;
}