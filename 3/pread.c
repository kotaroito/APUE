#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "error.h"

int main(int argc, char* argv[])
{
    int fd;
    ssize_t size;
    off_t offset; 
    char buf[1024];


    if (argc != 2)
        err_sys("invalid arg");


    if((fd = open(argv[1], O_RDONLY)) < 0)
        err_sys("open");

    offset = 0;
    while (1) {
       size = pread(fd, buf, 1, offset);

       if (size < 0) {
           err_sys("pread");
       }
       else if (size == 0) {
           break;
       }
       else {
           printf("%s", buf);
           offset += size;
       }
    }

    close(fd);

    return EXIT_SUCCESS;
}
