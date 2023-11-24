#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num_to_remove = atoi(argv[1]);

    char *existing_file = argv[2];
    char *new_file = argv[3];


    // read the existing file until the end
    // count all bytes in the file 
    FILE *input_stream = fopen(existing_file, "r");

    int ch;
    fseek(input_stream, 0, SEEK_END);
    int input_file_length = ftell(input_stream);

    // while ((ch = fgetc(input_stream)) != EOF) 
    //     input_file_length++;

    // print into new file byte by byte with total - num_to_remove 
    FILE *output_stream = fopen(new_file, "w");
    // fseek input file back to the beginning
    fseek(input_stream, 0, SEEK_SET);

    for (int i = 0; i < (input_file_length - num_to_remove); i++) 
        fputc(fgetc(input_stream), output_stream);

    
    fclose(input_stream);
    fclose(output_stream);


    return 0;
}