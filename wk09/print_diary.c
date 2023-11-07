// print $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {


    char *home_path = getenv("HOME");

    printf("The value of $HOME: %s\n", home_path);

    // $HOME/.diary

    char *diary_name = ".diary";
    int diary_pathname_size = strlen(home_path) + strlen(diary_name) + 2;   
    char *diary_path = malloc(diary_pathname_size * sizeof(char));

    snprintf(diary_path, diary_pathname_size, "%s/%s", home_path, diary_name);

    printf("The diary pathname is: %s\n", diary_path);

    FILE *diary_stream = fopen(diary_path, "r");
    if (diary_stream == NULL) {
        perror("");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(diary_stream)) != EOF) 
        fputc(ch, stdout); // putchar(ch);

    free(diary_path);
    return 0;
}