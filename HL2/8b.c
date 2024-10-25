/*
============================================================================
Name : 8b.c
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


void handle_sigint(int sig) {
    printf("Caught SIGINT: Interrupt from keyboard (Ctrl+C)\n");
    exit(0);  
}

int main() {
    if(signal(SIGINT, handle_sigint) == SIG_ERR){
        printf("Error in setting sig");
    }

    while (1);

    return 0;
}


/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 8b.c -o 8b.o && ./8b.o
^CCaught SIGINT: Interrupt from keyboard (Ctrl+C)
============================================================================
*/
