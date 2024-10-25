/*
============================================================================
Name : 12.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
                the parent process from the child process.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int pid = fork();  

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {

        printf("Child process (PID: %d) created. Parent process PID: %d\n", getpid(), getppid());


        sleep(2);


        printf("Child process is sending SIGKILL to parent (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL); 

        sleep(5);
        printf("Child process (PID: %d) is now an orphan, adopted by init/systemd (new parent PID: %d)\n", getpid(), getppid());
    } else {

        printf("Parent process (PID: %d) is running.\n", getpid());


        sleep(10);
    }

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 12.c -o 12.o && ./12.o
Parent process (PID: 8316) is running.
Child process (PID: 8317) created. Parent process PID: 8316
Child process is sending SIGKILL to parent (PID: 8316)
Killed
$ Child process (PID: 8317) is now an orphan, adopted by init/systemd (new parent PID: 434)
============================================================================
*/