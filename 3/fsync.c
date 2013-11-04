/*
 * =====================================================================================
 *
 *       Filename:  fsync.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/11/04 16時56分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
    int fd;
    char buff[1024];
    int i;

    sprintf(buff, "test%d\r\n", getpid());

    fd = open("/tmp/kotaro", (O_WRONLY | O_CREAT));
    for (i = 0; i < 10000; i++) {
        write(fd, buff, strlen(buff));
        if ( argc > 1 ) {
            fsync(fd);
        }
    }
    close(fd);
}
