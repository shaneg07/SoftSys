/*
============================================================================
Name : 13a.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                will send the signal (using kill system call). Find out whether the first program is able to catch
                the signal or not.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void signal_handler() {

    printf("Caught SIGTSTP (Ctrl+Z)\n");
}

int main() {

    signal(SIGSTOP, signal_handler);

    printf("%d\n", getpid());
    printf("Waiting for signals (SIGSTOP cannot be caught)\n");
    while (1) {
        sleep(30);
    }

    return 0;
}

// I dont understand...