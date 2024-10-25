/*
============================================================================
Name : 11.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
                use sigaction system call.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ignore_sigint(int sig) {
    printf("SIGINT signal (Ctrl+C) is currently ignored.\n");
}

int main() {
    struct sigaction sa;

    sa.sa_handler = ignore_sigint;  
    sigemptyset(&sa.sa_mask); 
    sa.sa_flags = 0; 


    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is being ignored for the next 10 seconds. Try pressing Ctrl+C now.\n");
    sleep(10);

    sa.sa_handler = SIG_DFL; 
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT action has been reset to default. Press Ctrl+C again to terminate the program.\n");
    sleep(10);

    return 0;
}


/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 11.c -o 11.o && ./11.o
SIGINT is being ignored for the next 10 seconds. Try pressing Ctrl+C now.
^CSIGINT signal (Ctrl+C) is currently ignored.
SIGINT action has been reset to default. Press Ctrl+C again to terminate the program.
^C
============================================================================
*/