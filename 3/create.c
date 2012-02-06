#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    int fd = open("/tmp/new", O_WRONLY | O_CREAT | O_TRUNC );
    off_t offset = lseek(fd, 1, SEEK_CUR);
    close(fd);

    printf("%lld\n", offset);
}
