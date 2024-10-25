/*
============================================================================
Name : 8f.c
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

void handle_sigvtalrm(int sig) {
    printf("Caught SIGVTALRM: Virtual timer expired (using setitimer())\n");
    exit(0);  
}

int main() {
    struct itimerval timer;


    signal(SIGVTALRM, handle_sigvtalrm);

    timer.it_value.tv_sec = 2; 
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  
    timer.it_interval.tv_usec = 0; 


    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 8f.c -o 8f.o && ./8f.o
Caught SIGVTALRM: Virtual timer expired (using setitimer())
============================================================================
*/
