
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {

    char *filename = argv[1];

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        printf("No file :(");
        return 1;
    }

    uint32_t bytes_1_mask = 0b10000000;
    uint32_t bytes_1_val =  0b00000000;

    uint32_t bytes_2_mask = 0b11100000;
    uint32_t bytes_2_val =  0b11000000;
    
    uint32_t bytes_3_mask = 0b11110000;
    uint32_t bytes_3_val =  0b11100000;
    
    uint32_t bytes_4_mask = 0b11111000;
    uint32_t bytes_4_val =  0b11110000;

    uint32_t byte_cont_mask = 0b11000000; // 10xxxxxx
    uint32_t byte_cont_val = 0b10000000; // 10xxxxxx

    int count = 0;

    int ch = fgetc(fp);
    while (ch != -1) {
        if (ch & bytes_1_mask == bytes_1_val) {
            ch = fgetc(fp); // Next byte please!
            count += 1;
        } else if (ch & bytes_2_mask == bytes_2_val) {
            ch = fgetc(fp);
            if (ch & byte_cont_mask != byte_cont_val) {
                printf("%s: invalid UTF-8 after %d valid UTF-8 characters\n", filename, count);
                return 1;
            }
            ch = fgetc(fp);
            count += 1;
        } else if (ch & bytes_3_mask == bytes_3_val) {
            for (int i = 0; i < 2; i++) {
                ch = fgetc(fp);
                if (ch & byte_cont_mask != byte_cont_val) {
                    printf("%s: invalid UTF-8 after %d valid UTF-8 characters\n", filename, count);
                    return 1;
                }
            }
            ch = fgetc(fp);
            count += 1;
        } else if (ch & bytes_4_mask == bytes_4_val) {
            for (int i = 0; i < 3; i++) {
                ch = fgetc(fp);
                if (ch & byte_cont_mask != byte_cont_val) {
                    printf("%s: invalid UTF-8 after %d valid UTF-8 characters\n", filename, count);
                    return 1;
                }
            }
            ch = fgetc(fp);
            count += 1;
        } else {
            printf("%s: invalid UTF-8 after %d valid UTF-8 characters\n", filename, count);
            return 1;
        }
    }

    return 0;
}





///








/////// 2^0 2^1 2^2 ... 
//////   1   0   1












