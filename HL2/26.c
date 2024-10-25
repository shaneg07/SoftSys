/*
============================================================================
Name : 26.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to send messages to the message queue. Check $ipcs -q
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
    int msgid;  
    struct msg_buffer msg; 
    int i;

    msgid = msgget(MESSAGE_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {  
        perror("msgget failed"); 
        exit(EXIT_FAILURE);  
    }

    for (i = 1; i <= 5; i++) {
        msg.msg_type = 1; 
        
        snprintf(msg.msg_text, sizeof(msg.msg_text), "Message %d", i);
        

        if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd failed");  
            exit(EXIT_FAILURE);  
        }
        
       
        printf("Sent: %s\n", msg.msg_text);
    }

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 26.c -o 26.o && ./26.o
Sent: Message 1
Sent: Message 2
Sent: Message 3
Sent: Message 4
Sent: Message 5
============================================================================
*/