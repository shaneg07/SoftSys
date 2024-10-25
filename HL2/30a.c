/*
============================================================================
Name : 30a.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to create a shared memory.
                a. write some data to the shared memory
                b. attach with O_RDONLY and check whether you are able to overwrite.
                c. detach the shared memory
                d. remove the shared memory
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
void main()
{
    key_t key = 12345;

    int shmid = shmget(key, 1024, IPC_CREAT | 0744);

    char *data;
    data = shmat(shmid, (void *)0, 0);
    printf("write in shared memory\n");
    scanf("%[^\n]", data);

    printf("data from shared memory : %s\n", data);
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 30a.c -o 30a.o && ./30a.o
write in shared memory
shane
data from shared memory : shane
============================================================================
*/