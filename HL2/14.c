/*
============================================================================
Name : 14.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
                the monitor.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];  
    int pid;
    char write_msg[] = "Hello from the pipe!";
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
        
        close(fd[0]);
        sleep(1);
        write(fd[1], write_msg, strlen(write_msg) + 1); 
        close(fd[1]);  
    } else {  
        close(fd[1]);  
        read(fd[0], read_msg, sizeof(read_msg)); 
        close(fd[0]); 

        printf("Message from pipe: %s\n", read_msg);
    }

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 14.c -o 14.o && ./14.o
Message from pipe: Hello from the pipe!
============================================================================
*/