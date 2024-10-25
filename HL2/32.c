/*
============================================================================
Name : 32a.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore
                b. protect shared memory from concurrent write access
                c. protect multiple pseudo resources ( may be two) using counting semaphore
                d. remove the created semaphore
============================================================================
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>

typedef union semun
{
    int val;                 
    struct semid_ds *buf;      
    unsigned short int *array; 
    struct seminfo *__buf;    
} semun;
int main(int argc, char *argv[])
{

    semun arg;
    key_t key = ftok(".", 331);
    int semid = semget(key, 1, 0); 
    if (semid == -1)
    {
        semid = semget(key, 1, IPC_CREAT | 0700);
        arg.val = 1;                  
        semctl(semid, 0, SETVAL, arg); 
    }

    struct sembuf sem_op; 
    sem_op.sem_num = 0;
    sem_op.sem_flg = 0;

    printf("Entering critical zone\n");


    sem_op.sem_op = -1;
    semop(semid, &sem_op, 1);

 
    printf("inside Critical section");
    getchar();
    int data;
    int fd = open("./17_ticket.txt", O_RDWR | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        perror("Error while opening file!");
        return 0;
    }

    int n = read(fd, &data, sizeof(data));
    if (n == 0)
    {
        data = 1;
    }
    else
    {
        data += 1;
        lseek(fd, 0, SEEK_SET); 
    }
    write(fd, &data, sizeof(data));
    printf("ticket number is : %d\t \n", data);
    printf("ticket number is stored in file\n");

    printf("out of critical zone\n");

    sem_op.sem_op = 1;
    semop(semid, &sem_op, 1);
    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 32.c -o 32.o && ./32.o
Entering critical zone
inside Critical sections
ticket number is : 1
ticket number is stored in file
out of critical zone
============================================================================
*/