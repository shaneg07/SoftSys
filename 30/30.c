/*
============================================================================
Name : 30.c
Author : Shane Gomes
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 31st Aug, 2024.
============================================================================
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void run_as_daemon()
{
    pid_t pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE); 
    if (pid > 0)
        exit(EXIT_SUCCESS);

    if (setsid() < 0)
        exit(EXIT_FAILURE); 
    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
        exit(EXIT_SUCCESS);  

    umask(0); 
    chdir("/");  

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

void wait_until(int hour, int minute)
{
    while (1)
    {
        time_t now = time(NULL);
        struct tm *current_time = localtime(&now);

        if (current_time->tm_hour == hour && current_time->tm_min == minute)
        {
            system("./test.sh");
            break;
        }
        sleep(60); 
    }
}

int main()
{
    run_as_daemon();

    int hour = 23;    
    int minute = 23;  

    wait_until(hour, minute);

    return 0;
}

/*

shane-laptop@shane-laptop:~/SoftSys/30$ sudo chmod a+x test.sh 
shane-laptop@shane-laptop:~/SoftSys/30$ ./test.sh
Shane Gomes - IIITB

shane-laptop@shane-laptop:~/SoftSys/30$ gcc 30.c -o 30.o

shane-laptop@shane-laptop:~/SoftSys/30$ ./30.o 

shane-laptop@shane-laptop:~/SoftSys/30$ pgrep 30.o
45947

*/