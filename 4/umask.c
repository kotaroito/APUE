#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR |S_IWUSR |S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char** argv)
{
    int fd;

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    fd = open("/tmp/umask_test", (O_WRONLY|O_CREAT|O_TRUNC), RWRWRW);

    close(fd);
}
