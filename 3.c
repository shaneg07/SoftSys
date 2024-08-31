/*
============================================================================
Name : 3.c
Author : Jerome Joseph
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {                      
    if(argc == 2) {
        char* filename = argv[1];

        int fd = creat(filename, S_IRWXU | S_IRGRP | S_IROTH);
        if(-1 != fd) {
            printf("File created successfully!\n");
            printf("File Descriptor: %d\n", fd);
        } else {
            perror("Error");
        }
    } else {
        printf("Usage: [executable] [filename]\nfilename: the file to be created.\n");
    }
}
