#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;


// function which spawns a process and waits for it to finish
int spawn_and_wait(char *argv[]) {

    // spawn the process
    pid_t pid;
    posix_spawn(&pid, argv[0], NULL, NULL, argv, environ);

    // wait for the process to finish 
    int exit_status;
    waitpid(pid, &exit_status, 0);
    // return with status code

    return exit_status;
}


int main(int argc, char* argv[]) {
    // date +%d-%m-%Y
    char *args[] = { "/bin/date", "+%d-%m-%Y", NULL };
    spawn_and_wait(args);

    char *args1[] = { "/bin/date", "+%T", NULL };
    spawn_and_wait(args1);

    char *args2[] = { "/usr/bin/whoami", NULL };
    spawn_and_wait(args2);

    char *args3[] = { "/bin/hostname", "-f", NULL };
    spawn_and_wait(args3);
    return 0;
}