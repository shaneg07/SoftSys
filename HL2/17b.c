/*
============================================================================
Name : 17b.c
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

void main(){
    int pipefd[2];
    pid_t cid;

    if(pipe(pipefd)==-1){
        printf("ERROR");
    }else{
        cid=fork();
        if(cid==0){
 
            close(0);

            dup2(pipefd[0],0);
            close(pipefd[1]);
            execlp("wc", "wc", NULL);
        }else{
            close(1);
            dup2(pipefd[1],1);
            close(pipefd[0]);

            execlp("ls", "ls -l", "-l", NULL);
        }
    }
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 17b.c -o 17b.o && ./17b.o
     88     785    5517
============================================================================
*/