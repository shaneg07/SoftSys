/*
============================================================================
Name : 10c.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void handle_sigfpe(int sig) {
    printf("Caught SIGFPE: Floating Point Exception\n");
    exit(1);  
}

int main() {
    struct sigaction sa;


    sa.sa_handler = handle_sigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGFPE, &sa, NULL); 

    int x = 1;
    int y = 0;
    int z = x / y; 

    return 0;
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 10c.c -o 10c.o && ./10c.o
Caught SIGFPE: Floating Point Exception
============================================================================
*/