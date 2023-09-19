#include <stdio.h>

char s1[4] = "abc";
// [a][b][c][\0]

char *s3 = "abc";
// [] <--ptr 
int main(void) {
    char *s2 = "def";

    s1[0] = 'x';

    printf("%s is the string\n", s1);

    return 0;
}
