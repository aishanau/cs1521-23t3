#include <stdio.h>

// translate this program into simple c 
// using "goto statements" and labels

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);


    if (x <= 100) goto small_big;
    if (x >= 1000) goto small_big;


medium:
        printf("medium\n");
        goto end_if;

small_big:
        printf("small/big\n");

end_if:
return_zero:
    return 0;
    
}