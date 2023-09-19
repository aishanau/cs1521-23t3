#include <stdio.h>


// 0! = 1
// n! = n * (n - 1)!


// factorial(4) = 4 *  3 *  2 * 1 * 1
// factorial(3) = 3 *  2 * 1 * 1
// factorial(2) = 2 * 1 * 1
// factorial(1) = 1 * 1
int factorial(int n) {

    // if n == 0 then return 1

    // otherwise return n * factorial(n - 1)

    if (n == 0) return 1;

    return n * factorial(n - 1);
}

int main(void)
{
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    printf("%d\n", factorial(n)); 
    return 0;
}
