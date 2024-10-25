/*
============================================================================
Name : 15.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a simple program to send some data from parent to the child process.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];  
    int pid;
    char write_msg[] = "Message from parent to child";
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        close(fd[1]); 
        read(fd[0], read_msg, sizeof(read_msg));  
        close(fd[0]);  

        printf("Child received: %s\n", read_msg);
    } else {
        close(fd[0]); 
        write(fd[1], write_msg, strlen(write_msg) + 1);  
        close(fd[1]);  
    }

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 15.c -o 15.o && ./15.o
Child received: Message from parent to child
============================================================================
*/