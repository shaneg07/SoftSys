/*
============================================================================
Name : 26.c
Author : Shane Gomes
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31st Aug, 2024.
============================================================================
*/  

#include <stdio.h>
#include <unistd.h>  

int main() {
    execl("./a.o", "a.o", "pass", "an", "argor4", (char *) NULL);

    perror("execl");
    return 1;
}


/*

shane-laptop@shane-laptop:~/SoftSys/26$ gcc 26.c -o 26.o

shane-laptop@shane-laptop:~/SoftSys/26$ gcc tmp.c -o a.o

shane-laptop@shane-laptop:~/SoftSys/26$ ./26.o 
pass
an
argor4

*/