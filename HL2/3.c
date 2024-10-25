/*
============================================================================
Name : 3.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
============================================================================
*/

#include <stdio.h>     
#include <stdlib.h>   
#include <sys/resource.h>

int main() {
    struct rlimit limit; 

 
    limit.rlim_cur = 256 * 1024 * 1024;

    limit.rlim_max = 256 * 1024 * 1024; 


    if (setrlimit(RLIMIT_AS, &limit) == -1) {
        perror("Error setting RLIMIT_AS");
        printf("rlim_cur: %ld, rlim_max: %ld\n", limit.rlim_cur, limit.rlim_max);
        return EXIT_FAILURE;
    }

    printf("Virtual memory limit set to 256 MB.\n");
    printf("rlim_cur: %ld, rlim_max: %ld\n", limit.rlim_cur, limit.rlim_max);

    while (1)

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ ./3.o
Virtual memory limit set to 256 MB.
rlim_cur: 268435456, rlim_max: 268435456
============================================================================
*/