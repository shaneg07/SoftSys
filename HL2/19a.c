/*
============================================================================
Name : 19.c
Author : Shane Gomes
Roll no : MT2024139
Description : Create a FIFO file by
                a. mknod command
                b. mkfifo command
                c. use strace command to find out, which command (mknod or mkfifo) is better.
                d. mknod system call
                e. mkfifo library function
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {

    if (mknod("my_fifo", __S_IFIFO | 0666, 0) == -1) {
        perror("mknod failed");
        return 1;
    }
    printf("FIFO 'my_fifo' created using mknod system call.\n");


    if (mkfifo("my__fifo", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }
    printf("FIFO 'my_fifo' created using mkfifo library function.\n");
    return 0;
}


/*
============================================================================
shane-laptop@shane-laptop:~$ gcc 19.c -o 19.o && ./19.o
FIFO 'my_fifo' created using mknod system call.
FIFO 'my_fifo' created using mkfifo library function.
============================================================================
*/