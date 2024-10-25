/*
============================================================================
Name : 33b.c
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
    int socktd=socket(AF_INET,SOCK_STREAM,0);
    if(socktd==-1){
        perror("Error when creating socket");
    }
    printf("Socket created\n");

    struct sockaddr_in address;
    address.sin_addr.s_addr=htonl(INADDR_ANY);
    address.sin_family=AF_INET;
    address.sin_port=htons(8080);


    int connectionS = connect(socktd, (struct sockaddr *)&address, sizeof(address));

    if(connectionS==-1){
        perror("Error while establishing Connection");
    }
    
    printf("Connection with server established\n");

    char buf[100];
    read(socktd,buf,100);
    printf("Data from server: %s\n",buf);

    printf("Write message for server: ");
    scanf("%[^\n]",buf);

    write(socktd,buf,sizeof(buf));
    printf("Data sent to server\n");

    close(socktd);
}

/*
============================================================================
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 33b.c -o 33b.o && ./33b.o
Socket created
Connection with server established
Data from server: hi im server
Write message for server: hi im client
Data sent to server
============================================================================
*/