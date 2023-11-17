
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Write a C program, chmod_if_public_write.c, 
// which is given 1+ command-line arguments 
// which are the pathnames of files or directories
// If the file or directory is publically-writeable, 
// it should change it to be not publically-writeable, 
// leaving other permissions unchanged

int main(int argc, char *argv[]) {

    // assume the first arg we get is a pathname 

    struct stat s;
    if (stat(argv[1], &s)) {
        perror("");
        exit(EXIT_FAILURE);
    }

    mode_t permissions = s.st_mode;


    // EXAMPLE, only considering last 9 permission bits.
    // SI_IWOTH = 0b000000010
    
    
    // mode =     0b010101010 (This is currently publicly writeable)
    //            0b111111101
    // mode =     0b010101000 (This is currently publicly writeable)

    
    //               rwx rwx rwx                       
    // SI_IWOTH = 0b 000 000 010
    // mode =     0b 010 101 000 (This is not currently publicly writeable)
    //            0b 000 000 000  
    // if file is publically writeable, 
    if ((permissions & S_IWOTH) != 0) {
        // then remove the permission
        mode_t new_permission = permissions & ~S_IWOTH;
        if (chmod(argv[1], new_permission)) {
            perror("");
            exit(EXIT_FAILURE);
        }
        printf("removing public write from %s\n", argv[1]);

    } else {
        // do nothing, print out message
        printf("%s is not publically writable", argv[1]);
    }


    return 0;
}