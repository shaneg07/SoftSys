/*
============================================================================
Name : 1a.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
                10micro second
                a. ITIMER_REAL
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>   
#include <sys/time.h> 
#include <unistd.h>  


void handle_alarm(int signum) {
    printf("Timer expired (ITIMER_REAL)\n");
}

int main() {
    struct itimerval timer; 

    
    signal(SIGALRM, handle_alarm);

  
    timer.it_value.tv_sec = 10;    
    timer.it_value.tv_usec = 10;   
    timer.it_interval.tv_sec = 10; 
    timer.it_interval.tv_usec = 10;

   
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting ITIMER_REAL");
        exit(EXIT_FAILURE);
    }

   
    while (1) {
        pause(); 
}
return 0;
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ ./1a.o
Timer expired (ITIMER_REAL)
Timer expired (ITIMER_REAL)
============================================================================
*/
