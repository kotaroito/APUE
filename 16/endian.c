#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
    int i, ic;
    char *cp; 
    
    // since Macbook Air uses Intel... little endian
    i  = 0x0a0b0c0d;
    ic = i;
    cp = (char*)&ic;

    ic = i;
    printf("raw\n");
    printf("%02x\n", *cp);     // 0d
    printf("%02x\n", *(cp+1)); // 0c
    printf("%02x\n", *(cp+2)); // 0b
    printf("%02x\n", *(cp+3)); // 0a

    ic = htonl(i);
    printf("network byte order\n");
    printf("%02x\n", *cp);     // 0a
    printf("%02x\n", *(cp+1)); // 0b
    printf("%02x\n", *(cp+2)); // 0c
    printf("%02x\n", *(cp+3)); // 0d

    ic = ntohl(htonl(0x0a0b0c0d));
    printf("host byte order\n");
    printf("%02x\n", *cp);     // 0d
    printf("%02x\n", *(cp+1)); // 0c
    printf("%02x\n", *(cp+2)); // 0b
    printf("%02x\n", *(cp+3)); // 0a



    return(EXIT_SUCCESS);
}
