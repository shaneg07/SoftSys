/*
============================================================================
Name : 9.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 10 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("SIGINT received, but currently ignored. Press Ctrl+C again to terminate the program.\n");
}

int main() {

    signal(SIGINT, handle_sigint);

    printf("SIGINT is currently ignored. Try pressing Ctrl+C now.\n");
    sleep(10);  


    signal(SIGINT, SIG_DFL);


    printf("SIGINT action reset to default. Press Ctrl+C again to terminate the program.\n");
    sleep(10);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 9.c -o 9.o && ./9.o
SIGINT is currently ignored. Try pressing Ctrl+C now.
^CSIGINT received, but currently ignored. Press Ctrl+C again to terminate the program.
SIGINT action reset to default. Press Ctrl+C again to terminate the program.
^C
============================================================================
*/