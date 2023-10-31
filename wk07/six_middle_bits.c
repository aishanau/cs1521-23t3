#include <stdint.h>
#include <stdio.h>

// if we want to extract bits, then we use & 

uint32_t six_middle_bits(uint32_t value) {
    // 10011000 00000000 01011011 10100000 = 23456
    // 1>> 3 = 0001 
    // 1111
    // 0000 0000 0000 0111 1110 0000 0000 0000
    uint32_t mask = 0x7E000;
    // 00000000 00000000 01000000 00000000 >> 13
    // mask 

    // 000 010
    return ((value & mask) >> 13);
}

int main() {
    printf("the six middle bits are %x\n", six_middle_bits(23456));
}