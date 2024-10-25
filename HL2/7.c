/*
============================================================================
Name : 7.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a simple program to print the created thread ids.
============================================================================
*/

#include <stdio.h>     
#include <pthread.h>   


void* thread_function(void* arg) {
    long thread_id = pthread_self();  
    printf("Thread %d: ID = %lu\n", *(int*)arg, thread_id); 
    return NULL;  
}

int main() {
    long threads[3];  
    int thread_args[3];    


    for (int i = 0; i < 3; i++) {
        thread_args[i] = i + 1; 
        int ret = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);  
        if (ret != 0) {
            printf("Error creating thread %d\n", i + 1); 
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);  
    }

    printf("All threads completed\n"); 
    return 0; 
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 7.c -o 7.o && ./7.o
Thread 1: ID = 140647088711232
Thread 2: ID = 140647080318528
Thread 3: ID = 140647071925824
All threads completed
============================================================================
*/