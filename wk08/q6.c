// print the first line of a file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // validate our commandline args 
    if (argc != 2) {
        fprintf(stderr, "incorrect number of args given\n");
        return 1;
    }

    FILE *stream = fopen(argv[1], "r");
    if (stream == NULL) {
        perror(argv[0]);
    }


    // fgetc 
    int ch;
    while ((ch = fgetc(stream)) != EOF) {
        fputc(ch, stdout);
        if (ch == '\n') break;

    }


    return 0;
}