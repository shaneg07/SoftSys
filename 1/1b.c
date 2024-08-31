/*
============================================================================
Name : 1b.c
Author : Shane Gomes
Description : Create the following types of a files using system call
    b. hard link (link system call)
Date: 31st Aug, 2024.
=========================   ===================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if(argc == 3) {
        char* oldpath = argv[1];
        char* newpath = argv[2];

        int retval = link(oldpath, newpath);
        if(retval == 0)
            printf("Hard link created successfully!\n");
        else 
            perror("Error");
    } else {
        printf("Usage: [executable] [filename1] [filename2]\nfilename1: oldpath\nfilename2: newpath\n");
    }

    return 0;
}
