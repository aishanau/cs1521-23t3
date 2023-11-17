#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
    while (true) {
        printf("Feed me input!\n");
        sleep(1);
    }
    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    char line[1024];
    while (fgets(line, sizeof line, stdin)) {
        printf("you entered: %s", line);
    }

    // pthread_cancel(thread);


    printf("After our input loop\n");
    sleep(3);
    // more code 
    return 0;
}