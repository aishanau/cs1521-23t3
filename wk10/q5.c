#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>


void *thread_run(void *data) {
    while (true)
        printf("%s", (char *)data);

    return NULL;
}

int main(void) {
// Write a C program that creates a thread that infinitely prints some message 
// provided by main (eg. "Hello\n"), while the main (default) thread infinitely 
// prints a different message (eg. "there!\n").

    pthread_t thread;
    pthread_create(&thread, NULL, thread_run, "hello\n");

    while (true)
        printf("there\n");




    return 0;
}
