// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.

init_loop:
    int x = 24;
start_loop:
    if (x >= 42) goto end_loop;

        printf("%d", x);
        printf("\n");

        x += 3;
        goto start_loop;

end_loop:
    return 0;

}
