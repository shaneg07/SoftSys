/*
============================================================================
Name : 32c.c
Author : Shane Gomes
Roll no : MT2024139
Description :Write a program to implement semaphore to protect any critical section.
                    c. protect multiple pseudo resources ( may be two) using counting semaphore
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_RESOURCE 2
sem_t semaphore;

void* access_resource(void* arg) {
    sem_wait(&semaphore);  
    printf("Resource accessed by thread %ld\n", (long)arg);
    sleep(2);
    sem_post(&semaphore); 
    return NULL;
}

int main() {
    pthread_t threads[5];

    sem_init(&semaphore, 0, NUM_RESOURCE);  

    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, access_resource, (void*)i);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore); 

    return 0;
}


/*
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 32c.c -o 32c.o && ./32c.o
Resource accessed by thread 0
Resource accessed by thread 1
Resource accessed by thread 2
Resource accessed by thread 3
Resource accessed by thread 4
*/
