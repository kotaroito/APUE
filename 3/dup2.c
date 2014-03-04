#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define FD 100

void print_cur_pos(int fd)
{
    int pos;
    pos = lseek(fd, 0, SEEK_CUR);
    printf("pos[%d]\n", (int)pos);
}

int inc_pos(int fd)
{
    int pos = lseek(fd, 1, SEEK_CUR);
    return pos;
}

int main(void)
{
    int fd, fd2;
    off_t pos;

    fd  = open("/tmp/test", O_RDONLY);
    fd2 = dup2(fd, FD);
    print_cur_pos(fd2); // 0

    inc_pos(fd);
    print_cur_pos(fd2); // 1

    return EXIT_SUCCESS;
}
