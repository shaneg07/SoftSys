/*
============================================================================
Name : 21a.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO1 "21fifo1"  
#define FIFO2 "21fifo2" 
#define BUFFER_SIZE 100

int main() {
    int fd1, fd2;
    char buffer[BUFFER_SIZE];
    char message[] = "Hello from Program 1!";
    

    fd1 = open(FIFO1, O_WRONLY);
    if (fd1 == -1) {
        perror("open fifo1 for writing failed");
        exit(EXIT_FAILURE);
    }

    fd2 = open(FIFO2, O_RDONLY);
    if (fd2 == -1) {
        perror("open fifo2 for reading failed");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    if (write(fd1, message, sizeof(message)) == -1) {
        perror("write to fifo1 failed");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to FIFO1: %s\n", message);

 
    if (read(fd2, buffer, sizeof(buffer)) == -1) {
        perror("read from fifo2 failed");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Message received from FIFO2: %s\n", buffer);

    close(fd1);
    close(fd2);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:~$ gcc 21a.c -o 21a.o && ./21a.o
Message sent to FIFO1: Hello from Program 1!
Message received from FIFO2: Hello from Program 2!
============================================================================
*/