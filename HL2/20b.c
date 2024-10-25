/*
============================================================================
Name : 20b.c
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

#define FIFO_NAME "shane_fifo"
#define BUFFER_SIZE 100

int main() {
    int fd;
    char buffer[BUFFER_SIZE];


    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }


    if (read(fd, buffer, sizeof(buffer)) == -1) {
        perror("read failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Message received from FIFO: %s\n", buffer);

    close(fd);

    return 0;
}


/*
============================================================================
shane-laptop@shane-laptop:~$ gcc 20b.c -o 20b.o && ./20b.o
Message received from FIFO: Hello from the writer!
============================================================================
*/