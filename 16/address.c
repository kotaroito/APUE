#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include "error.h"

void print_type(struct addrinfo *aip);

int main(int argc, char* argv[])
{
    struct addrinfo     *ailist, *aip;
    struct addrinfo     hint;
    struct sockaddr_in  *sinp;
    const  char         *addr;
    int                  err;
    char                 abuf[INET_ADDRSTRLEN];

    if (argc != 3)
        err_quit("usage: %s nodename service", argv[0]);

    hint.ai_flags = AI_CANONNAME;
    hint.ai_family = 0;
    hint.ai_socktype = 0;
    hint.ai_protocol = 0;
    hint.ai_addrlen = 0;
    hint.ai_canonname = NULL;
    hint.ai_addr = NULL;
    hint.ai_next = NULL;
    if((err = getaddrinfo(argv[1], argv[2], &hint, &ailist)) != 0)
        err_quit("getaddrinfo error: %s", gai_strerror(err));

    for (aip = ailist; aip != NULL; aip = aip->ai_next) {
        print_type(aip);
        printf("host[%s]\t", aip->ai_canonname ? aip->ai_canonname : "-");
        if (aip->ai_family == AF_INET) {
            sinp = (struct sockaddr_in *)aip->ai_addr;
            addr = inet_ntop(AF_INET, &sinp->sin_addr, abuf, INET_ADDRSTRLEN);
            printf("address[%s]\t", addr ? addr : "unknown");
            printf("port[%d]", ntohs(sinp->sin_port));
        }
        printf("\n");
    }

    freeaddrinfo(ailist);
    return EXIT_SUCCESS;
}

void
print_type(struct addrinfo *aip)
{
    switch (aip->ai_socktype) {
    case SOCK_STREAM:
        printf("type[stream]\t");
        break;
    case SOCK_DGRAM:
        printf("type[datagram]\t");
        break;
    case SOCK_SEQPACKET:
        printf("type[seqpacket]\t");
        break;
    case SOCK_RAW:
        printf("type[raw]\t");
        break;
    defaul:
        printf("unkonow (%d) ", aip->ai_socktype);
    }
}
