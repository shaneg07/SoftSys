/*
============================================================================
Name : 1a.c
Author : Shane Gomes
Description : Create the following types of a files using system call
    a. soft link (symlink system call)
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h> 

int main(int argc, char** argv) {
    if(argc == 3) {
        char* target = argv[1];
        char* linkpath = argv[2];

        int retval = symlink(target, linkpath);
        if(retval == 0)
            printf("Symlink created successfully!\n");
        else 
            perror("Error");
    } else {
        printf("Usage: [executable] [filename1] [filename2]\nfilename1: target file\nfilename2: linkpath\n");
    }

    return 0;
}
