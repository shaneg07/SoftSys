/*
============================================================================
Name : 24.c
Author : Shane Gomes
Description : Write a program to create an orphan process.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child process (PID: %d) is running.\n", getpid());
        printf("Child process will sleep for 30 seconds to become an orphan.\n");
        sleep(30); 

        printf("Child process (PID: %d) is now orphaned.\n", getpid());
    } else {
        printf("Parent process (PID: %d) is terminating.\n", getpid());
        exit(0);
    }

    return 0;
}

/*

shane-laptop@shane-laptop:~/SoftSys$ ./24.o
Parent process (PID: 28625) is terminating.
Child process (PID: 28626) is running.
Child process will sleep for 30 seconds to become an orphan.

shane-laptop@shane-laptop:~/SoftSys$ Child process (PID: 28626) is now orphaned.

*/