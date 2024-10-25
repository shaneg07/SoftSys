/*
============================================================================
Name : 18.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to find out total number of directories on the pwd.
                execute ls -l | grep ^d | wc ? Use only dup2.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    int pipefd[2], pipefd2[2];
    int cid, cid2;

    if (pipe(pipefd) == -1)
    {
        printf("ERROR");
    }
    if (pipe(pipefd2) == -1)
    {
        printf("ERROR");
    }
    else
    {
        cid = fork();
        if (cid == 0)
        {
            cid2 = fork();
            if (cid2 == 0)
            {
                close(pipefd[0]);  
                close(pipefd[1]);  
                close(pipefd2[1]); 


                close(0);

    
                dup2(pipefd2[0], 0);
                execlp("wc", "wc", NULL);
            }
            else
            {
                close(pipefd[1]);  
                close(pipefd2[0]);

                close(0);
               
                dup2(pipefd[0], 0);

          
                close(1);
        
                dup2(pipefd2[1], 1);
                execlp("grep", "grep", "^d", NULL);
            }
        }
        else
        {
            close(pipefd2[0]); 
            close(pipefd2[1]); 
            close(pipefd[0]); 
            close(1); 
           
            dup2(pipefd[1], 1);
            execlp("ls", "ls", "-l", NULL);
        }
    }
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 18.c -o 18.o && ./18.o
      0       0       0
============================================================================
*/