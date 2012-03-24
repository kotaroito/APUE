#include <stdio.h>
#include <fcntl.h>
#include "error.h"

int main(int argc, char* argv[])
{
    int fd;

    fd = open("/tmp/kotaro", (O_WRONLY | O_CREAT));
    close(fd);
}
