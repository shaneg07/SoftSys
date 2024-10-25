/*
============================================================================
Name : 34ab.c
Author : Shane Gomes
Roll no : MT2024139
Description : Write a program to create a concurrent server.
    a. use fork
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 65432
#define MSG_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket_fd;
    struct sockaddr_in server_socket_addr;
    char msg_buffer[MSG_BUFFER_SIZE];
    ssize_t sent_bytes, received_bytes;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <SERVER_IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_socket_addr.sin_family = AF_INET;
    server_socket_addr.sin_port = htons(SERVER_PORT);
    memset(&(server_socket_addr.sin_zero), '\0', 8);

    if (inet_pton(AF_INET, argv[1], &server_socket_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(client_socket_fd);
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket_fd, (struct sockaddr *)&server_socket_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        close(client_socket_fd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server %s:%d\n", argv[1], SERVER_PORT);
    printf("Type messages to send to the server. Type 'exit' to quit.\n");

    while (1) {
        printf("Client: ");
        fflush(stdout);
        memset(msg_buffer, 0, MSG_BUFFER_SIZE);

        if (fgets(msg_buffer, MSG_BUFFER_SIZE, stdin) == NULL) {
            perror("fgets");
            break;
        }

        sent_bytes = send(client_socket_fd, msg_buffer, strlen(msg_buffer), 0);
        if (sent_bytes < 0) {
            perror("send");
            break;
        }

        if (strcasecmp(msg_buffer, "exit\n") == 0 || strcasecmp(msg_buffer, "exit\r\n") == 0) {
            printf("Closing connection.\n");
            break;
        }

        memset(msg_buffer, 0, MSG_BUFFER_SIZE);
        received_bytes = recv(client_socket_fd, msg_buffer, MSG_BUFFER_SIZE - 1, 0);
        if (received_bytes < 0) {
            perror("recv");
            break;
        } else if (received_bytes == 0) {
            printf("Server disconnected.\n");
            break;
        }

        printf("Server: %s\n", msg_buffer);
    }

    close(client_socket_fd);
    return 0;
}

/*
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 34ab.c -o 34ab.o && ./34ab.o 127.0.0.1
Connected to server 127.0.0.1:65432
Type messages to send to the server. Type 'exit' to quit.
Client: im client
Server: im client

Client: exit
Closing connection.

-----------------------------------------------------------------------------------------------------------

shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ ./34ab.o 127.0.0.1
Connected to server 127.0.0.1:65432
Type messages to send to the server. Type 'exit' to quit.
Client: im client2
Server: im client2

Client:

*/