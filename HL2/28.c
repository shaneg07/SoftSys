/*
============================================================================
Name : 28.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>


#define MESSAGE_KEY 12345

int main() {
    int msgid;  
    struct msqid_ds mq_ds;  

    msgid = msgget(MESSAGE_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {  
        perror("msgget failed");  
        exit(EXIT_FAILURE); 
    }

   
    if (msgctl(msgid, IPC_STAT, &mq_ds) == -1) {
        perror("msgctl IPC_STAT failed");  
        exit(EXIT_FAILURE);  
    }

    printf("Current permissions: %o\n", mq_ds.msg_perm.mode);


    mq_ds.msg_perm.mode = 6666 | IPC_CREAT | IPC_EXCL;

    if (msgctl(msgid, IPC_SET, &mq_ds) == -1) {
        perror("msgctl IPC_SET failed");  
        exit(EXIT_FAILURE);  
    }

    printf("Updated permissions: %o\n", mq_ds.msg_perm.mode);

    return 0; 
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 28.c -o 28.o && ./28.o
Current permissions: 666
Updated permissions: 17012
============================================================================
*/