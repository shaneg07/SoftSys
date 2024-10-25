/*
============================================================================
Name : 31.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to implement semaphore to protect any critical section.
                    b. protect shared memory from concurrent write access
============================================================================
*/


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

sem_t semaphore;

void* write_to_shared_memory(void* arg) {
    sem_wait(&semaphore);  
    int shmid = *((int*)arg);
    char* data = (char*)shmat(shmid, NULL, 0);
    strcpy(data, "Shared Memory Data");
    printf("Data written: %s\n", data);
    shmdt(data);  
    sem_post(&semaphore); 
    return NULL;
}

int main() {
    pthread_t threads[2];
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    sem_init(&semaphore, 0, 1); 

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, write_to_shared_memory, &shmid);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);  
    shmctl(shmid, IPC_RMID, NULL);  

    return 0;
}
/*
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 32b.c -o 32b.o && ./32b.o
Data written: Shared Memory Data
Data written: Shared Memory Data
*/