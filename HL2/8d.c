/*
============================================================================
Name : 8d.c
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
#include <unistd.h>


void handle_sigalrm(int sig) {
    printf("Caught SIGALRM: Timer expired (using alarm())\n");
    exit(0); 
}

int main() {
 
    signal(SIGALRM, handle_sigalrm);


    alarm(2);

    while (1);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 8d.c -o 8d.o && ./8d.o
Caught SIGALRM: Timer expired (using alarm())
============================================================================
*/
