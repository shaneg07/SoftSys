/*
============================================================================
Name : 27a.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to receive messages from the message queue.
                a. with 0 as a flag
                b. with IPC_NOWAIT as a flag
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct msg_buffer
{
    long msg_type;
    char msg_text[100];
} msg_buffer;
int main()
{
    msg_buffer message;

    key_t key = 1234; 
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("enter msgtype:\n");
    scanf("%ld", &message.msg_type);
    int size_s = msgrcv(msgid, &message, sizeof(message), message.msg_type, 0); 
    if (size_s <= 0)
    {
        perror("No message in queue\n");
    }
    else
    {
        printf("Message: %s\n", message.msg_text);
    }
    return 0;
}
/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 27a.c -o 27a.o && ./27a.o
enter msgtype:
1
Message: Message 1
============================================================================
*/