/*
============================================================================
Name : 34aa.c
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
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

#define SERVER_PORT 65432
#define DATA_BUFFER_SIZE 1024
#define MAX_PENDING_CONNECTIONS 10

void handle_sigchld(int signal) {
    (void)signal;
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

void process_client(int client_socket_fd, struct sockaddr_in client_address) {
    char data_buffer[DATA_BUFFER_SIZE];
    ssize_t received_data_size;

    printf("Connected to client: %s:%d\n", inet_ntoa(client_address.sin_addr),
           ntohs(client_address.sin_port));

    while (1) {
        memset(data_buffer, 0, DATA_BUFFER_SIZE);
        received_data_size = recv(client_socket_fd, data_buffer, DATA_BUFFER_SIZE - 1, 0);
        if (received_data_size < 0) {
            perror("recv");
            break;
        } else if (received_data_size == 0) {
            printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr),
                   ntohs(client_address.sin_port));
            break;
        }

        printf("Client %s:%d: %s\n", inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port), data_buffer);

        if (send(client_socket_fd, data_buffer, strlen(data_buffer), 0) < 0) {
            perror("send");
            break;
        }

        if (strcasecmp(data_buffer, "exit\n") == 0 || strcasecmp(data_buffer, "exit\r\n") == 0) {
            printf("Closing connection with client: %s:%d\n", inet_ntoa(client_address.sin_addr),
                   ntohs(client_address.sin_port));
            break;
        }
    }

    close(client_socket_fd);
    exit(EXIT_SUCCESS);
}

int main() {
    int server_socket_fd, new_client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length;
    struct sigaction signal_action;

    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int reuse_address_option = 1;
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_address_option, sizeof(int)) == -1) {
        perror("setsockopt");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_address.sin_zero), '\0', 8);

    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket_fd, MAX_PENDING_CONNECTIONS) == -1) {
        perror("listen");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    signal_action.sa_handler = handle_sigchld;
    sigemptyset(&signal_action.sa_mask);
    signal_action.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &signal_action, NULL) == -1) {
        perror("sigaction");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1) {
        address_length = sizeof(struct sockaddr_in);
        if ((new_client_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &address_length)) == -1) {
            perror("accept");
            continue;
        }

        pid_t fork_result = fork();
        if (fork_result < 0) {
            perror("fork");
            close(new_client_fd);
            continue;
        }

        if (fork_result == 0) { 
            close(server_socket_fd); 
            process_client(new_client_fd, client_address);
        } else { 
            close(new_client_fd); 
        }
    }

    close(server_socket_fd);
    return 0;
}

/*
shane-laptop@shane-laptop:/mnt/c/Users/shane/Desktop/HL2$ gcc 34aa.c -o 34aa.o && ./34aa.o
Server listening on port 65432
Connected to client: 127.0.0.1:58508
Client 127.0.0.1:58508: im client

Connected to client: 127.0.0.1:40128
Client 127.0.0.1:40128: im client2

Client 127.0.0.1:58508: exit

Closing connection with client: 127.0.0.1:58508
*/