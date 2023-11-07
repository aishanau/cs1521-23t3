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

    int array[10];

    array === int*

    char** ret = (char**) malloc(10)
    char ret[MAX_LISTING][MAX_PATJ_LENTH];

    strdup(de.d_name);
    free()

    ret[0]; 
    ret[0] = malloc()


    ret === char**


    return 0;
}