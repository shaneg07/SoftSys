/*
============================================================================
Name : 13b.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                will send the signal (using kill system call). Find out whether the first program is able to catch
                the signal or not.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }


    int target_pid = atoi(argv[1]);

    if (kill(target_pid, SIGSTOP) == 0) {
        printf("SIGSTOP signal sent to process %d\n", target_pid);
    } else {
        perror("Failed to send SIGSTOP");
        return 1;
    }

    return 0;
}