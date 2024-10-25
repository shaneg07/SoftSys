/*
============================================================================
Name : 21b.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
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
    char message[] = "Hello from Program 2!";

    fd1 = open(FIFO1, O_RDONLY);
    if (fd1 == -1) {
        perror("open fifo1 for reading failed");
        exit(EXIT_FAILURE);
    }


    fd2 = open(FIFO2, O_WRONLY);
    if (fd2 == -1) {
        perror("open fifo2 for writing failed");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    if (read(fd1, buffer, sizeof(buffer)) == -1) {
        perror("read from fifo1 failed");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Message received from FIFO1: %s\n", buffer);

    if (write(fd2, message, sizeof(message)) == -1) {
        perror("write to fifo2 failed");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to FIFO2: %s\n", message);

    close(fd1);
    close(fd2);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:~$ gcc 21b.c -o 21b.o && ./21b.o
Message received from FIFO1: Hello from Program 1!
Message sent to FIFO2: Hello from Program 2!
============================================================================
*/