/*
============================================================================
Name : 1c.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
                10micro second
                c. ITIMER_PROF
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>   
#include <sys/time.h> 


void handle_prof_alarm(int signum) {
    printf("Timer expired (ITIMER_PROF)\n");
}

int main() {
    struct itimerval timer; 

  
    signal(SIGPROF, handle_prof_alarm);

   
    timer.it_value.tv_sec = 10;    
    timer.it_value.tv_usec = 10; 
    timer.it_interval.tv_sec = 10; 
    timer.it_interval.tv_usec = 10;

   
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error setting ITIMER_PROF");
        exit(EXIT_FAILURE);
    }

    
    while (1) {
        //usermode      
    }

    return 0;
}

/*
============================================================================
Command line: cc 1c.c && ./a.out
Output: 
Timer expired (ITIMER_PROF)
Timer expired (ITIMER_PROF)
...
(every 10 sec 10 usec)
============================================================================
*/
