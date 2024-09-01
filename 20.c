/*
============================================================================
Name : 20.c
Author : Shane Gomes
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = getpid();
    printf("PID: %d\n", pid);
    while(1);
}


/*

shane-laptop@shane-laptop:~/SoftSys$ ./20.o
PID: 24065
^C

shane-laptop@shane-laptop:~$ ps -o pid,ni,comm -p 24065
    PID  NI COMMAND
  24065   0 20.o

shane-laptop@shane-laptop:~/SoftSys$ sudo nice -n -10 ./20.o
PID: 24755

shane-laptop@shane-laptop:~/SoftSys$ ps -o pid,ni,comm -p 24755
    PID  NI COMMAND
  24755 -10 20.o

shane-laptop@shane-laptop:~/SoftSys$ sudo renice -n -5 -p 24755
24755 (process ID) old priority -10, new priority -5

shane-laptop@shane-laptop:~/SoftSys$ ps -o pid,ni,comm -p 24755
    PID  NI COMMAND
  24755  -5 20.o

*/