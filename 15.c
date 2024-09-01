/*
============================================================================
Name : 15.c
Author : Shane Gomes
Description : Write a program to display the environmental variable of the user (use environ).
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>

extern char **environ;

int main() {
    while(*environ != NULL) {
        printf("%s\n", *environ);
        environ++;
    }
    return 0;
}


/*

shane-laptop@shane-laptop:~/SoftSys$ gcc 15.c -o 15.o

shane-laptop@shane-laptop:~/SoftSys$ ./15.o
SHELL=/bin/bash
COLORTERM=truecolor
WSL2_GUI_APPS_ENABLED=1
TERM_PROGRAM_VERSION=1.92.2
WSL_DISTRO_NAME=Ubuntu
SSH_AUTH_SOCK=/tmp/ssh-XXXXXX1gbIKJ/agent.369
SSH_AGENT_PID=373
NAME=shane-laptop
...

*/