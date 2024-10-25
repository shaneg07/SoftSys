/*
============================================================================
Name : 16.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to send and receive data from parent to child vice versa. Use two way
                communication.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int parent_to_child[2]; 
    int child_to_parent[2]; 
    pid_t pid;
    char parent_msg[] = "Message from parent to child";
    char child_msg[] = "Message from child to parent";
    char read_msg[100];


    if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {  
        close(parent_to_child[1]); 
        close(child_to_parent[0]);


        read(parent_to_child[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);


        write(child_to_parent[1], child_msg, strlen(child_msg) + 1);

        close(parent_to_child[0]); 
        close(child_to_parent[1]);
    } else {  
        close(parent_to_child[0]);  
        close(child_to_parent[1]); 

        write(parent_to_child[1], parent_msg, strlen(parent_msg) + 1);

        read(child_to_parent[0], read_msg, sizeof(read_msg));
        printf("Parent received: %s\n", read_msg);

        close(parent_to_child[1]);  
        close(child_to_parent[0]); 
    }

    return 0;
}


/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 16.c -o 16.o && ./16.o
Child received: Message from parent to child
Parent received: Message from child to parent
============================================================================
*/