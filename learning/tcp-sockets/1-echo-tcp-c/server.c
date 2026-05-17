#include <stdio.h>          /* printf(), fprintf() */
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <io.h>             /* close() */
#include <windows.h>
#else
#include <sys/socket.h>     /* socket(), connect(), send(), recv() */
#include <netinet/in.h>
#include <arpa/inet.h>      /* sockaddr_in, inet_addr() */
#include <unistd.h>         /* close() */
#endif    
#include <stdlib.h>         /* atoi() */
#include <string.h>         /* memset() */

#define MAXPENDING 5        /* max outstanding connection reqs */
#define RCVBUFSIZE 32       /* size of receive buffer */

void die_with_error(char *message);
void handle_tcp_client(int clnt_sock);

int main(int argc, char **argv)
{
    /* windows garbage */
    #ifdef _WIN32
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        printf("WSAStartup failed with error: %i", iResult);
        return 1;
    }
    #endif

    /* variables */
    int server_socket;                          /* server socket descriptor */
    int client_socket;                          /* client socket descriptor */
    struct sockaddr_in echo_server_addr;        /* server address */
    struct sockaddr_in echo_client_addr;        /* client address */
    unsigned short echo_serv_port;              /* server port */
    unsigned int client_len;                    /* length of client address data structure */

    /* validate args */
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <Server Port> \n", argv[0]);
        exit(1);
    }

    /* load args */
    echo_serv_port = atoi(argv[1]);

    /* socket for incoming connections */
    if ((server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        die_with_error("socket() failed");
    }

    /* construct local address struct */
    memset(&echo_server_addr, 0, sizeof(echo_server_addr));
    echo_server_addr.sin_family = AF_INET;
    echo_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    echo_server_addr.sin_port = htons(echo_serv_port);

    /* bind to the local address */
    if (bind(server_socket, (struct sockaddr *) &echo_server_addr, sizeof(echo_server_addr)) < 0)
    {
        die_with_error("bind() failed");
    }

    /* mark the socket so it will listen for incoming connections */
    if (listen(server_socket, MAXPENDING) < 0)
    {
        die_with_error("listen() failed");
    }

    /* indicate that we're listening */
    printf("listening...\n");

    /* start the listening loop */
    for (;;)
    {
        /* determine size of in-out param */
        client_len = sizeof(echo_client_addr);

        /* wait for client */
        if ((client_socket = accept(server_socket, (struct sockaddr *) &echo_client_addr, &client_len)) < 0)
        {
            die_with_error("accept() failed");
        }

        /* handle the client */
        printf("handling client %s\n", inet_ntoa(echo_client_addr.sin_addr));
        handle_tcp_client(client_socket);
    }
}

void handle_tcp_client(int client_socket)
{
    /* variables */
    char echo_buffer[RCVBUFSIZE];       /* buffer for echo string */
    int recv_msg_size;                  /* size of rcvd message */

    /* receive message from client */
    if ((recv_msg_size = recv(client_socket, echo_buffer, RCVBUFSIZE, 0)) < 0)
    {
        die_with_error("recv() failed");
    }

    /* send received string back to client */
    while (recv_msg_size > 0)
    {
        printf("\techoing %i bytes: %s\n", recv_msg_size, echo_buffer);

        /* echo message back */
        if (send(client_socket, echo_buffer, recv_msg_size, 0) != recv_msg_size)
        {
            die_with_error("send() failed");
        }

        /* see if there's more data to recv */
        if ((recv_msg_size = recv(client_socket, echo_buffer, RCVBUFSIZE, 0)) < 0)
        {
            printf("\recv_msg_size=%i\n", recv_msg_size);
            perror("\trecv() failed");
            /*die_with_error("recv() failed");*/
        }
    }

    /* cleanup */
    close(client_socket);
}
