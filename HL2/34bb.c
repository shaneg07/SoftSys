/*
============================================================================
Name : 34bb.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to create a concurrent server.
b. use pthread_create
============================================================================
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
void main()
{
    int socktd = socket(AF_INET, SOCK_STREAM, 0);
    if (socktd == -1)
    {
        perror("Error when creating socket");
        _exit(0);
    }
    printf("Socket created\n");

    // assigning server info
    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(INADDR_ANY); // host to network short
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    // make connection to the server
    int connectionS = connect(socktd, (struct sockaddr *)&address, sizeof(address));

    if (connectionS == -1)
    {
        perror("Error while establishing Connection\n");
        _exit(0);
    }

    printf("Connection with server established\n");

    char buf[100];
    // read fron server
    read(socktd, buf, 100);
    printf("Data from server: %s\n", buf);

    printf("Write message for server: \n");
    scanf("%[^\n]", buf);

    write(socktd, buf, sizeof(buf));
    printf("Data sent to server\n");

    // closing socket
    close(socktd);
}

/*

shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 34bb.c -o 34bb.o && ./34bb.o
Socket created
Connection with server established
Data from server: Hello from server

Write message for server:
im client 1
Data sent to server

--------------------------------------------------------------------------------------------

shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 34bb.c -o 34bb.o && ./34bb.o
Socket created
Connection with server established
Data from server: Hello from server

Write message for server:
im client2
Data sent to server
*/