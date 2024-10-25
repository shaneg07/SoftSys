/*
============================================================================
Name : 8a.c
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


void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1);  
}

int main() {
   
    signal(SIGSEGV, handle_sigsegv);

    int *ptr = NULL;
    *ptr = 42; 

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 8a.c -o 8a.o && ./8a.o
Caught SIGSEGV: Segmentation Fault
============================================================================
*/
