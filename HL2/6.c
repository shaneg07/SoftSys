/*
============================================================================
Name : 6.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a simple program to create three threads.
============================================================================
*/

#include <stdio.h>      
#include <pthread.h>   


void* thread_function(void* arg) {
    int thread_num = *(int*)arg;  
    printf("Thread %d is running\n", thread_num);  
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
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 6.c -o 6.o && ./6.o
Thread 1 is running
Thread 2 is running
Thread 3 is running
All threads completed
============================================================================
*/