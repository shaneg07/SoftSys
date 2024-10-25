/*
============================================================================
Name : 33a.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to communicate between two machines using socket.
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
    }
    printf("server Socket created\n");

    struct sockaddr_in server, client;
    server.sin_addr.s_addr = htonl(INADDR_ANY); 
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    int bindS = bind(socktd, (struct sockaddr *)&server, sizeof(server));
    if (bindS == -1)
    {
        perror("Error while binding name to socket!");
        _exit(0);
    }
    printf("Binding to server socket was successful!\n");

    int listenS = listen(socktd, 2);
    if (listenS == -1)
    {
        perror("Error while trying to listen to Connections");
        _exit(0);
    }
    printf("Listening from Connection ");

    int client_size = (int)sizeof(client);
    int connectionfd = accept(socktd, (struct sockaddr *)&client, &client_size);
    if (connectionfd == -1)
    {
        perror("Error while accepting Connection");
        _exit(0);
    }
    else
    {
        char buf[100];
        printf("Write message form server to client: ");
        scanf("%[^\n]", buf);
        write(connectionfd, buf, sizeof(buf));

        read(connectionfd, buf, 100);
        printf("Data from client: %s\n", buf);
    }


    close(socktd);
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 33a.c -o 33a.o && ./33a.o
server Socket created
Binding to server socket was successful!
Listening from Connection Write massage form server to client: hi im server
Data from client: hi im client
============================================================================
*/