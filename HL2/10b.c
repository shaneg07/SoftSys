/*
============================================================================
Name : 10b.c
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


void handle_sigint(int sig) {
    printf("Caught SIGINT: Interrupt from keyboard (Ctrl+C)\n");
    exit(0);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL); 

    while (1)
    {
        //Do nothing
    }
    return 0;
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 10b.c -o 10b.o && ./10b.o
^CCaught SIGINT: Interrupt from keyboard (Ctrl+C)
============================================================================
*/