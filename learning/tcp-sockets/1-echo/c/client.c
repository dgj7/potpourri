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
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        printf("WSAStartup failed with error: %i", iResult);
        return 1;
    }
    #endif

    /* variables */
    int sock;                               /* socket descriptor */
    struct sockaddr_in echoServAddr;        /* echo server addr */
    unsigned short echoServPort;            /* echo server port */
    char *servIP;                           /* server ip addr (dotted quad) */
    char *echoString;                       /* string to send to echo server */
    char echoBuffer[RCVBUFSIZE];            /* buffer for echo string */
    unsigned int echoStringLen;             /* length of string to echo */
    int bytesRcvd, totalBytesRcvd;          /* bytes read in single recv() and total by tes read */

    /* validate input */
    if ((argc < 3) || (argc > 4))
    {
        fprintf(stderr, "usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }

    /* load args */
    servIP = argv[1];                       /* server ip addr (dotted quad) */
    echoString = argv[2];                   /* string to echo */

    /* get the port */
    if (argc == 4)
    {
        echoServPort = atoi(argv[3]);
    }
    else
    {
        echoServPort = 7;
    }

    /* create socket */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        die_with_error("socket() failed");
    }

    /* server addr structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);
    echoServAddr.sin_port = htons(echoServPort);

    /* establish connection with server */
    if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
    {
        die_with_error("connect() failed");
    }

    /* send the string */
    echoStringLen = strlen(echoString);
    if (send(sock, echoString, echoStringLen, 0) != echoStringLen)
    {
        die_with_error("send() sent a different number of bytes than expected");
    }

    /* recv the same string back from the server */
    totalBytesRcvd = 0;
    printf("Received: ");
    while (totalBytesRcvd < echoStringLen)
    {
        /* recv up to buffer size, minus 1 for str terminator */
        if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
        {
            die_with_error("recv() failed or connection closed prematurely");
        }
        totalBytesRcvd += bytesRcvd;
        echoBuffer[bytesRcvd] = '\0';
        printf(echoBuffer);
    }

    /* print final linefeed for readability */
    printf("\n");

    /* cleanup */
    #ifdef _WIN32
    WSACleanup();
    #endif
    close(sock);

    /* done */
    return 0;
}
