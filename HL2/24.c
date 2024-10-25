/*
============================================================================
Name : 24.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to create a message queue and print the key and message queue id.
Date: 17 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MESSAGE_KEY 1234  


struct msg_buffer {
    long msg_type; 
    char msg_text[100];  
};

int main() {
    key_t key;
    int msgid;
    

    key = MESSAGE_KEY; 
    if (key == -1) {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 24.c -o 24.o && ./24.o
Message Queue Key: 1234
Message Queue ID: 0
============================================================================
*/