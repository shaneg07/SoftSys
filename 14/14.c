/*
============================================================================
Name : 14.c
Author : Shane Gomes
Description : Write a program to find the type of a file.
    a. Input should be taken from command line.
    b. program should be able to identify any type of a file.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

const char* file_type_to_string(mode_t mode) {
    if (S_ISREG(mode)) return "Regular file";
    if (S_ISDIR(mode)) return "Directory";
    if (S_ISCHR(mode)) return "Character device";
    if (S_ISBLK(mode)) return "Block device";
    if (S_ISFIFO(mode)) return "FIFO/pipe";
    if (S_ISLNK(mode)) return "Symbolic link";
    if (S_ISSOCK(mode)) return "Socket";
    return "Unknown";
}   

int main(int argc, char *argv[]) {
    if (argc == 2) {
        struct stat file_stat;

        if (stat(argv[1], &file_stat) != 0) {
            perror("stat");
            return -1;
        }

        printf("File: %s\n", argv[1]);
        printf("Type: %s\n", file_type_to_string(file_stat.st_mode));

    } else {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
    }
    return 0;
}


/*

shane-laptop@shane-laptop:~/SoftSys/14$ ls -la
total 28
drwxr-xr-x 2 shane-laptop shane-laptop  4096 Sep  1 21:53 .
drwxrwxrwx 9 root         root          4096 Sep  1 21:52 ..
-rw-r--r-- 1 shane-laptop shane-laptop  1696 Sep  1 20:43 14.c
-rwxr-xr-x 1 shane-laptop shane-laptop 16208 Sep  1 21:52 14.o
-rw-r--r-- 1 shane-laptop shane-laptop     0 Sep  1 21:52 file1
prw-r--r-- 1 shane-laptop shane-laptop     0 Sep  1 21:53 file2

shane-laptop@shane-laptop:~/SoftSys/14$ ./14.o file1
File: file1
Type: Regular file

shane-laptop@shane-laptop:~/SoftSys/14$ ./14.o file2
File: file2
Type: FIFO/pipe

*/