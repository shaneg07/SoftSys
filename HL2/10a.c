/*
============================================================================
Name : 10a.c
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

void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1); 
}

int main() {
    struct sigaction sa;


    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask); 
    sa.sa_flags = 0; 
    sigaction(SIGSEGV, &sa, NULL);  


    int *ptr = NULL;
    *ptr = 42; 

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 10a.c -o 10a.o && ./10a.o
Caught SIGSEGV: Segmentation Fault
============================================================================
*/