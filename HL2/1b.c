/*
============================================================================
Name : 1b.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
                10micro second
                b. ITIMER_VIRTUAL
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>   // For signal handling
#include <sys/time.h> // For timers

// Signal handler for SIGVTALRM
void handle_virtual_alarm(int signum) {
    printf("Timer expired (ITIMER_VIRTUAL)\n");
}

int main() {
    struct itimerval timer; 

    
    signal(SIGVTALRM, handle_virtual_alarm);

    
    timer.it_value.tv_sec = 10;   
    timer.it_value.tv_usec = 10;  
    timer.it_interval.tv_sec = 10; 
    timer.it_interval.tv_usec = 10;


    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error setting ITIMER_VIRTUAL");
        exit(EXIT_FAILURE);
    }

    while (1) {
        while(1){
            int i = 0;
            i++;
        }
    }

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ ./1b.o
Timer expired (ITIMER_VIRTUAL)
Timer expired (ITIMER_VIRTUAL)
============================================================================
*/
