/*
============================================================================
Name : 22.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
                system call with FIFO.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <errno.h>

#define FIFO_NAME "22fifo"
#define BUFFER_SIZE 100

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    fd_set readfds;
    struct timeval timeout;
    int retval;

    if (mkfifo(FIFO_NAME, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo failed");
        exit(EXIT_FAILURE);
    }

    fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;  
    timeout.tv_usec = 0; 

    retval = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select failed");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (retval == 0) {

        printf("No data received within 10 seconds.\n");
    } else {

        if (FD_ISSET(fd, &readfds)) {
            ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_read == -1) {
                perror("read failed");
                close(fd);
                exit(EXIT_FAILURE);
            }
            buffer[bytes_read] = '\0'; 
            printf("Data received: %s\n", buffer);
        }
    }

    close(fd);

    return 0;
}


/*
============================================================================
shane-laptop@shane-laptop:~$ gcc 22.c -o 22.o && ./22.o
Data received: shane

============================================================================
*/