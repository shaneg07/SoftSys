/*
============================================================================
Name : 25.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

int main() {
    key_t key = 1234; 
    int msgid;
    struct msqid_ds msg_info;

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgid, IPC_STAT, &msg_info) == -1) {
        perror("msgctl failed");
        exit(EXIT_FAILURE);
    }

    printf("Access Permissions: %o\n", msg_info.msg_perm.mode & 0777);

    printf("UID: %u\n", msg_info.msg_perm.uid);
    printf("GID: %u\n", msg_info.msg_perm.gid);

    printf("Time of Last Message Sent: %s", ctime(&msg_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msg_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&msg_info.msg_ctime));

    printf("Current Size of Queue (in bytes): %ld\n", msg_info.__msg_cbytes);

    printf("Number of Messages in Queue: %ld\n", msg_info.msg_qnum);

    printf("Maximum Number of Bytes Allowed: %ld\n", msg_info.msg_qbytes);

    printf("PID of Last msgsnd: %d\n", msg_info.msg_lspid);
    printf("PID of Last msgrcv: %d\n", msg_info.msg_lrpid);

    return 0;
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 25.c -o 25.o && ./25.o
Access Permissions: 666
UID: 1000
GID: 1000
Time of Last Message Sent: Thu Jan  1 05:30:00 1970
Time of Last Message Received: Thu Jan  1 05:30:00 1970
Time of Last Change: Fri Oct 25 16:03:45 2024
Current Size of Queue (in bytes): 0
Number of Messages in Queue: 0
Maximum Number of Bytes Allowed: 16384
PID of Last msgsnd: 0
PID of Last msgrcv: 0
============================================================================
*/