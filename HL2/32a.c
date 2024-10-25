/*
============================================================================
Name : 32a.c
Author : Shane Gomes
Roll no : MT2024139
Description :Write a program to implement semaphore to protect any critical section.
                    a. rewrite the ticket number creation program using semaphore
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int ticket_number = 0;
sem_t semaphore;

void* generate_ticket(void* arg) {
    sem_wait(&semaphore); 
    ticket_number++;
    printf("Generated Ticket Number: %d\n", ticket_number);
    sem_post(&semaphore);  
    return NULL;
}

int main() {
    pthread_t threads[5];

    sem_init(&semaphore, 0, 1); 

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, generate_ticket, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);  

    return 0;
}

/*
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 32a.c -o 32a.o && ./32a.o
Generated Ticket Number: 1
Generated Ticket Number: 2
Generated Ticket Number: 3
Generated Ticket Number: 4
Generated Ticket Number: 5
*/
