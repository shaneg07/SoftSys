/*
============================================================================
Name : 22.c
Author : Shane Gomes
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>  
#include <fcntl.h>   
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>  

#define FILE_PATH "output.txt"
#define BUFFER_SIZE 256

int main() {
    int fd;
    pid_t pid;
    char *parent_message = "Parent process writes this line.\n";
    char *child_message = "Child process writes this line.\n";

    fd = open(FILE_PATH, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        ssize_t len = strlen(child_message);
        ssize_t written = write(fd, child_message, len);
        if (written != len) {   
            perror("write (child)");
        }
        close(fd);
    } else {
        ssize_t len = strlen(parent_message);
        ssize_t written = write(fd, parent_message, len);
        if (written != len) {
            perror("write (parent)");
        }
        close(fd);
    }

    return 0;
}

/*

shane-laptop@shane-laptop:~/SoftSys/22$ ./22.o

shane-laptop@shane-laptop:~/SoftSys/22$ cat output.txt
Parent process writes this line.
Child process writes this line.

*/