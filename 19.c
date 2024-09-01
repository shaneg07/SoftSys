/*
============================================================================
Name : 19.c
Author : Shane Gomes
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <x86intrin.h>

int main() {
    uint64_t start, end;
    pid_t pid;

    start = __rdtsc();

    pid = getpid();

    end = __rdtsc();

    uint64_t cycles = end - start;

    printf("Process ID: %d\n", pid);
    printf("Time taken for getpid(): %lu cycles\n", cycles);

    return 0;
}


/*

shane-laptop@shane-laptop:~/SoftSys$ ./19.o
Process ID: 18638
Time taken for getpid(): 6136 cycles

*/