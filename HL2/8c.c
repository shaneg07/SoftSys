/*
============================================================================
Name : 8c.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a separate program using signal system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
                d. SIGALRM (use alarm system call)
                e. SIGALRM (use setitimer system call)
                f. SIGVTALRM (use setitimer system call)
                g. SIGPROF (use setitimer system call)
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig) {
    printf("Caught SIGFPE: Floating Point Exception\n");
    exit(1);  
}

int main() {
   
    signal(SIGFPE, handle_sigfpe);

    int x = 1;
    int y = 0;
    int z = x / y;  

    printf("This line will not be printed.\n");

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 8c.c -o 8c.o && ./8c.o
Caught SIGFPE: Floating Point Exception
============================================================================
*/
