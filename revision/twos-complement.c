#include <stdio.h>
#include <stdint.h>


// write a program that takes in a signed 1 byte number
// -15 = 15
// 15 = -15

int8_t twos_complement(uint8_t num) {
    // subtract 1 from num
    // flip all bits
    return ~(num - 1);
    // return -num;
}

int main(void) {
    uint8_t num = 15; // 11111111
    printf("the original number is: %d and positive version is this: %d\n", num, twos_complement(num));
    return 0;
}