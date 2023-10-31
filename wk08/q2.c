// Print lines containing  specified substring from the files specified as arguments

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


void search_string(FILE* stream, char *string_to_search_for) {
    char current_string[1024]; 
    while (fgets(current_string, 1024, stream) != NULL) {
        // strstr() will return NULL if string was not found in the line 
        if (strstr(current_string, string_to_search_for) != NULL)
            printf("%s", current_string);
    }
}

int main(int argc, char *argv[]) {

    // validate our commandline args 
    if (argc < 2) {
        fprintf(stderr, "incorrect number of args given\n");
        return 1;
    }

    char *string_to_search_for = argv[1];

    if (argc == 2) {
        // read from stdin
            // loop through stream 
        search_string(stdin, string_to_search_for);

    } else {
        // read from all the files from remaining args 
    
        for (int i = 2; i < argc; i++) {
            // assume we only have one more file given argv[2]
            FILE *stream = fopen(argv[i], "r");
            if (stream == NULL) {
                perror(argv[0]);
                continue;
            }
            // loop through stream 
            search_string(stream, string_to_search_for);

            fclose(stream);
        }

    }

    return 0;
}
