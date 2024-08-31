/*
============================================================================
Name : 5.c
Author : Jerome Joseph
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pid = getpid();
    printf("PID: %d\n", pid);

    int fd[100];
    int file_num = 0;
    while(1) {
        char filename[100];
        printf("Enter the filename for file %d: ", file_num + 1);
        fgets(filename, 100, stdin);

        int file_descriptor = creat(filename, S_IRWXU);

        if(file_descriptor != -1) {
            fd[file_num++] = file_descriptor;
            printf("File created: %s", filename);
            printf("File descriptors: %d\n", file_descriptor);
        }
    }

    return 0;
}
