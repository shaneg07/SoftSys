/*
============================================================================
Name : 1c.c
Author : Shane Gomes
Description : Create the following types of a files using system call
    c. FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if(argc == 2) {
        char* filename = argv[1];
        
        int retval = mkfifo(filename, S_IRWXU);

        if(retval != 0)
            perror("Error:");
    } else {
        printf("Usage: [executable] [filename1]\nfilename1: fifo_filename\n");
    }

    return 0;
}
