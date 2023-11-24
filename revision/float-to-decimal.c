#include <stdio.h>
#include <stdint.h>
#include <math.h>


int32_t float_to_decimal(uint32_t num) {

    // print sign bit 

    uint32_t sign_bit = ((1 << 31) & num) >> 31;
    printf("sign bit: %d\n", sign_bit);
    
    // print exponent
    uint32_t exponent_bit = ((0xFF << 23) & num) >> 23;
    printf("exponent bits: %d\n", exponent_bit);

    // print frac
    uint32_t fractional_bit = 0x7FFFFF & num;
    printf("fractional bits: %d\n", fractional_bit);

    // bit by bit 
    uint32_t fractional_mask = 1 << 23;
    float fractional_component = 0;
    for (int i = 1; i < 24; i++) {
        // check if a bit in a position is set 
        if (fractional_mask & fractional_bit) {
            // if bit is set, add 2^(-X)
            fractional_component += (1.0 / (1 << i));
        }

        fractional_mask >>= 1;
    }

    printf("fractional component: %f\n", fractional_component);

    // 0111 1111 1111 1111 1111 1111
    // 7FFFFF

    return num;
}

int main(void) {
    uint32_t num = 0b00111111110000000000000000000000; // 0 01111111 100000000000000000

    // printf("0b\n", (unsigned int)num);
    float_to_decimal(num);
    // printf("the original number is: %d and positive version is this: %d\n", num, float_to_decimal(num));
    return 0;
}