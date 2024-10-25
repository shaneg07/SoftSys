/*
============================================================================
Name : 17c.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to execute ls -l | wc.
                a. use dup
                b. use dup2
                c. use fcntl
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void main(){
    int pipefd[2];
    pid_t cid;

    if(pipe(pipefd)==-1){
        printf("ERROR");
    }else{
        cid=fork();
        if(cid==0){

            close(0);

            fcntl(pipefd[0], F_DUPFD, 0);
            close(pipefd[1]);
            execlp("wc", "wc", NULL);
        }else{
            close(1);
            fcntl(pipefd[1], F_DUPFD, 1);
            close(pipefd[0]);

            execlp("ls", "ls -l", "-l", NULL);
        }
    }
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 17c.c -o 17c.o && ./17c.o
     89     794    5581
============================================================================
*/