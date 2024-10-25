/*
============================================================================
Name : 23.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to print the maximum number of files can be opened within a process and
                size of a pipe (circular buffer).
============================================================================
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

void main()
{
    long maxFiles;  
    long sizeOfPipe; 

    char *s = "23fifo";
    mkfifo(s, S_IRWXU);

    maxFiles = sysconf(_SC_OPEN_MAX);

    printf("Maximum number of files that can be opened is: %ld\n", maxFiles);


    printf("Maximum size of pipe: %d\n", _PC_PIPE_BUF);
    
}

/*
============================================================================
shane-laptop@shane-laptop:~$ gcc 23.c -o 23.o && ./23.o
Maximum number of files that can be opened is: 1024
Maximum size of pipe: 5
============================================================================
*/