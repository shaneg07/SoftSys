/*
============================================================================
Name : 21.c
Author : Shane Gomes
Description : Write a program, call fork and print the parent and child process id.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h> 
int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("=====================================================\n");
        printf("Child process:\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        printf("=====================================================\n");
    } else {
        printf("=====================================================\n");
        printf("Parent process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        printf("=====================================================\n");
    }

    return 0;
}

/*

shane-laptop@shane-laptop:~/SoftSys$ ./21.o
=====================================================
Parent process:
Parent PID: 26516
Child PID: 26517
=====================================================
=====================================================
Child process:
Child PID: 26517
Parent PID: 356
=====================================================

*/