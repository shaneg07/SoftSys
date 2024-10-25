/*
============================================================================
Name : 32d.c
Author : Shane Gomes
Roll no : MT2024139
Description :Write a program to implement semaphore to protect any critical section.
                    d. remove the created semaphore
============================================================================
*/

#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t semaphore;

    sem_init(&semaphore, 0, 1);  

    sem_destroy(&semaphore);  
    printf("Semaphore destroyed.\n");

    return 0;
}


/*
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 32d.c -o 32d.o && ./32d.o
Semaphore destroyed.
*/
