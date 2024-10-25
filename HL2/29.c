/*
============================================================================
Name : 29.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to remove the message queue.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MESSAGE_KEY 1234

int main() {
    int msgid; 

    msgid = msgget(MESSAGE_KEY, 0666);
    if (msgid == -1) {  
        perror("msgget failed");  
        exit(EXIT_FAILURE); 
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID failed"); 
        exit(EXIT_FAILURE); 
    }

    printf("Message queue removed successfully.\n");

    return 0; 
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 29.c -o 29.o && ./29.o
Message queue removed successfully.
============================================================================
*/