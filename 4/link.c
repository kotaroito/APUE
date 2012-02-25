#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"

int main(int argc, char *argv[])
{
    int  fd;
    char buf[] = "test";

    if ( fd = open("/tmp/1", O_WRONLY | O_CREAT | O_TRUNC) < 0 ) {
        err_sys("fail open");
    }

    if ( write(fd, buf, 4) != 4 ) {
        err_sys("fail write"); 
    }

    if ( link("/tmp/1", "/tmp/2") < 0 ) {
        err_sys("link error");
    }
    
    if ( unlink("/tmp/2") < 0 ) {
        err_sys("unlink error");
    }
}
