/*
============================================================================
Name : 34ba.c
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
#include<pthread.h>

void communicate(int *connectionfd)
{

    char buf[100];
    // write fron server to connection fd
    write(*connectionfd, "Hello from server\n", 19);

    read(*connectionfd, buf, 100);
    printf("Data from client : %s\n", buf);

    close(*connectionfd);
}

void main()
{
    int socktd = socket(AF_INET, SOCK_STREAM, 0);
    if (socktd == -1)
    {
        perror("Error when creating socket");
    }
    printf("server Socket created\n");

    // server info
    struct sockaddr_in server, client;
    server.sin_addr.s_addr = htonl(INADDR_ANY); // host to network long
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    int bindS = bind(socktd, (struct sockaddr *)&server, sizeof(server));
    if (bindS == -1)
    {
        perror("Error while binding name to socket!");
        _exit(0);
    }
    printf("Binding to server socket was successful!\n");

    // listen for connection
    int listenS = listen(socktd, 2);
    if (listenS == -1)
    {
        perror("Error while trying to listen to Connections");
        _exit(0);
    }
    printf("Listning from Connection \n");

    while (1)
    {
        int client_size = (int)sizeof(client);
        int connectionfd = accept(socktd, (struct sockaddr *)&client, &client_size);
        if (connectionfd == -1)
        {
            perror("Error while accepting Connection\n");
            _exit(0);
        }
        else
        {
            pthread_t threadID;
            if (pthread_create(&threadID, NULL, (void *)communicate, &connectionfd))
                perror("Error while creating thread");
        }
    }
    // closing socket
    close(socktd);
}

/*
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 34ba.c -o 34ba.o && ./34ba.o
server Socket created
Binding to server socket was successful!
Listning from Connection
Data from client : im client
Data from client : im client2
Data from client : im client 1
*/