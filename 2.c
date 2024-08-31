/*
============================================================================
Name : 2.c
Author : Shane Gomes
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {                    
    int pid = getpid();

    printf("PID - %d\n", pid);
    
    while(1);

    return 0;
}

