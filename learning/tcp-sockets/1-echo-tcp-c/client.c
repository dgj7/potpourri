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

#define RCVBUFSIZE 32

void die_with_error(char *message);

int main(int argc, char **argv)
{
    /* windows garbage */
    #ifdef _WIN32
    WSADATA wsa_data;
    int i_wsa_result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (i_wsa_result != 0)
    {
        printf("WSAStartup failed with error: %i", i_wsa_result);
        return 1;
    }
    #endif

    /* variables */
    int socket_desc;                                 /* socket descriptor */
    struct sockaddr_in echo_server_address;     /* echo server addr */
    unsigned short echo_server_port;            /* echo server port */
    char *server_ip;                            /* server ip addr (dotted quad) */
    char *echo_string;                          /* string to send to echo server */
    char echo_buffer[RCVBUFSIZE];               /* buffer for echo string */
    unsigned int echo_string_length;            /* length of string to echo */
    int bytes_rcvd, total_bytes_rcvd;           /* bytes read in single recv() and total by tes read */

    /* validate input */
    if ((argc < 3) || (argc > 4))
    {
        fprintf(stderr, "usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }

    /* load args */
    server_ip = argv[1];                        /* server ip addr (dotted quad) */
    echo_string = argv[2];                      /* string to echo */

    /* get the port */
    if (argc == 4)
    {
        echo_server_port = atoi(argv[3]);
    }
    else
    {
        echo_server_port = 7;
    }

    /* create socket */
    if ((socket_desc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        die_with_error("socket() failed");
    }

    /* server addr structure */
    memset(&echo_server_address, 0, sizeof(echo_server_address));
    echo_server_address.sin_family = AF_INET;
    echo_server_address.sin_addr.s_addr = inet_addr(server_ip);
    echo_server_address.sin_port = htons(echo_server_port);

    /* establish connection with server */
    if (connect(socket_desc, (struct sockaddr *) &echo_server_address, sizeof(echo_server_address)) < 0)
    {
        die_with_error("connect() failed");
    }

    /* send the string */
    echo_string_length = strlen(echo_string);
    if (send(socket_desc, echo_string, echo_string_length, 0) != echo_string_length)
    {
        die_with_error("send() sent a different number of bytes than expected");
    }

    /* recv the same string back from the server */
    total_bytes_rcvd = 0;
    printf("Received: ");
    while (total_bytes_rcvd < echo_string_length)
    {
        /* recv up to buffer size, minus 1 for str terminator */
        if ((bytes_rcvd = recv(socket_desc, echo_buffer, RCVBUFSIZE - 1, 0)) <= 0)
        {
            die_with_error("recv() failed or connection closed prematurely");
        }
        total_bytes_rcvd += bytes_rcvd;
        echo_buffer[bytes_rcvd] = '\0';
        printf(echo_buffer);
    }

    /* print final linefeed for readability */
    printf("\n");

    /* cleanup */
    #ifdef _WIN32
    WSACleanup();
    #endif
    close(socket_desc);

    /* done */
    return 0;
}
