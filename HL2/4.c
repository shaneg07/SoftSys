/*
============================================================================
Name : 4.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
                system call. Use time stamp counter.
============================================================================
*/

#include <stdio.h>    
#include <stdint.h>    
#include <x86intrin.h> 
#include <unistd.h>   

int main() {
    uint64_t start, end;
    int i;


    start = __rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = __rdtsc();

    printf("Time taken for 100 getppid() calls: %lu clock cycles\n", (end - start));

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 4.c -o 4.o && ./4.o
Time taken for 100 getppid() calls: 14674 clock cycles
============================================================================
*/