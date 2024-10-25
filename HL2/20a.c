/*
============================================================================
Name : 20a.c
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

#define FIFO_NAME "fifo_shane"

int main() {
    int fd;
    char message[] = "Hello from the writer!";

    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo failed");
        exit(EXIT_FAILURE);
    }

    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    if (write(fd, message, sizeof(message)) == -1) {
        perror("write failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Message sent to FIFO: %s\n", message);

    close(fd);

    return 0;
}



/*
============================================================================
shane-laptop@shane-laptop:~$ gcc 20a.c -o 20a.o && ./20a.o
Message sent to FIFO: Hello from the writer!
============================================================================
*/