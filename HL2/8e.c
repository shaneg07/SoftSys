/*
============================================================================
Name : 8e.c
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
#include <sys/time.h>
#include <unistd.h>

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM: Timer expired (using setitimer())\n");
    exit(0);  
}

int main() {
    struct itimerval timer;


    signal(SIGALRM, handle_sigalrm);


    timer.it_value.tv_sec = 2;  
    timer.it_value.tv_usec = 0; 
    timer.it_interval.tv_sec = 0;  
    timer.it_interval.tv_usec = 0; 


    setitimer(ITIMER_REAL, &timer, NULL);


    while (1);

    return 0;
}


/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 8e.c -o 8e.o && ./8e.o
Caught SIGALRM: Timer expired (using setitimer())
============================================================================
*/
