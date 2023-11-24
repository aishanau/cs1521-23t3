


// & | ^ >> << 

// true && true = true ///// true && false === true 

// 1 & 1 = 1 /// 1 & 0 == 0

// 1 | 1 = 1 /// 1 | 0 = 1 //// 0 | 0 = 0



// 0x00001 << 2 = 0x00004 
// 0b00001 << 2 = 0b00100


// 0x00001 >> 2 = 0x00000
// 0b00001 >> 2 = 0b00000


// 0xFF = 0b 1111 1111

// we want use & operation to extract bits 

#include <stdio.h>
#include <stdint.h>

// given a uint32_t value,
// return 1 iff the least significant (bottom) byte
// is equal to the 2nd least significant byte; and
// return 0 otherwise
int practice_q2(uint32_t value) {
    // 0x12345678
    // 0xFF000000
    // 0x000000FF



    // step 1: grab last byte from number
    int last = value & 0xFF;

    // step 2: grab second last byte
    // 0x12345678 >> 8 = 0x00123456
    int second_last = (value >> 8) & 0xFF;

    if (last == second_last) return 1;
    return 0;
}


int main(int argc, char *argv[]) {

    printf("%d\n", practice_q2(0x12347878));

    return 0;
}