/*
============================================================================
Name : 27.c
Author : Shane Gomes
Description : Write a program to execute ls -Rl by the following system calls
    a. execl
    b. execlp
    c. execle
    d. execv
    e. execvp
Date: 31st Aug, 2024.
============================================================================
*/  

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void execute_using_execl() {
    printf("Executing `ls -Rl` using execl:\n");
    int retval = execl("/bin/ls", "ls", "-Rl", (char *) NULL);

    if(retval == -1) 
        perror("Error");
}

void execute_using_execlp() {
    printf("Executing `ls -Rl` using execlp:\n");
    int retval = execlp("ls", "ls", "-Rl", (char *) NULL);

    if(retval == -1) 
        perror("Error");
}

void execute_using_execle() {
    printf("Executing `ls -Rl` using execle:\n");
    char *envp[] = { "PATH=/bin:/usr/bin", NULL };

    int retval = execle("/bin/ls", "ls", "-Rl", (char *) NULL, envp);

    if(retval == -1) 
        perror("Error");
}

void execute_using_execv() {
    printf("Executing `ls -Rl` using execv:\n");
    char *args[] = { "ls", "-Rl", NULL };

    int retval = execv("/bin/ls", args);

    if(retval == -1) 
        perror("Error");
}

void execute_using_execvp() {
    printf("Executing `ls -Rl` using execvp:\n");
    char *args[] = { "ls", "-Rl", NULL };

    int retval = execvp("ls", args);

    if(retval == -1) 
        perror("Error");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <1|2|3|4|5>\n", argv[0]);
        return 1;
    }

    int choice = atoi(argv[1]);

    switch (choice) {
        case 1:
            execute_using_execl();
            break;
        case 2:
            execute_using_execlp();
            break;
        case 3:
            execute_using_execle();
            break;
        case 4:
            execute_using_execv();
            break;
        case 5:
            execute_using_execvp();
            break;
        default:
            printf("Invalid choice: %d. Please choose 1, 2, 3, 4, or 5.\n", choice);
            return 1;
    }

    return 0;
}

/*

shane-laptop@shane-laptop:~/SoftSys/27$ ./27.o 1
Executing `ls -Rl` using execl:
.:
total 24
-rw-r--r-- 1 shane-laptop shane-laptop  3552 Sep  1 20:43 27.c
-rwxr-xr-x 1 shane-laptop shane-laptop 16568 Sep  1 22:56 27.o

shane-laptop@shane-laptop:~/SoftSys/27$ ./27.o 2
Executing `ls -Rl` using execlp:
.:
total 24
-rw-r--r-- 1 shane-laptop shane-laptop  3552 Sep  1 20:43 27.c
-rwxr-xr-x 1 shane-laptop shane-laptop 16568 Sep  1 22:56 27.o

shane-laptop@shane-laptop:~/SoftSys/27$ ./27.o 3
Executing `ls -Rl` using execle:
.:
total 24
-rw-r--r-- 1 shane-laptop shane-laptop  3552 Sep  1 20:43 27.c
-rwxr-xr-x 1 shane-laptop shane-laptop 16568 Sep  1 22:56 27.o

shane-laptop@shane-laptop:~/SoftSys/27$ ./27.o 4
Executing `ls -Rl` using execv:
.:
total 24
-rw-r--r-- 1 shane-laptop shane-laptop  3552 Sep  1 20:43 27.c
-rwxr-xr-x 1 shane-laptop shane-laptop 16568 Sep  1 22:56 27.o

shane-laptop@shane-laptop:~/SoftSys/27$ ./27.o 5
Executing `ls -Rl` using execvp:
.:
total 24
-rw-r--r-- 1 shane-laptop shane-laptop  3552 Sep  1 20:43 27.c
-rwxr-xr-x 1 shane-laptop shane-laptop 16568 Sep  1 22:56 27.o

shane-laptop@shane-laptop:~/SoftSys/27$ ./27.o 6
Invalid choice: 6. Please choose 1, 2, 3, 4, or 5.

*/