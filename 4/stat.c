#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    struct stat  statbuf;

    stat("./actual", &statbuf);
    printf("%lld\n", statbuf.st_size);
    printf("%ld\n",  statbuf.st_atime);
}
