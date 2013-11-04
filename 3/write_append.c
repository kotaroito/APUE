#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "error.h"

#define BUFFSIZE 4096

int main(int argc, char* argv[])
{
    int fd;
    char buff[BUFFSIZE];
    int i;

    fd = open("/tmp/kotaro", (O_WRONLY | O_CREAT | O_APPEND) );
    for (i = 0; i < 1000000; i++ ) {
        sprintf(buff, "%d\r\n", getpid());
        write(fd, buff, strlen(buff)); 
    }
    close(fd);
}
