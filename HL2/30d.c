/*
============================================================================
Name : 30d.c
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
#include <fcntl.h>
int main()
{
    key_t key = 12345;

    int shmid = shmget(key, 1024, IPC_CREAT | 0744);

    char *data_pointer;
    data_pointer = shmat(shmid, (void *)0, 0);
    if (data_pointer == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }
    printf("Shared memory attached press any key to delete shared memory\n");
    getchar();
    printf("Deleting shared memory\n");
    shmctl(key, IPC_RMID, NULL);
    return 1;
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 30d.c -o 30d.o && ./30d.o
Shared memory attached press any key to delete shared memory
s
Deleting shared memory
============================================================================
*/