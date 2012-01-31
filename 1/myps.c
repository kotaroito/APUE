#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("self:%d\n",   getpid());
    printf("parent:%d\n", getppid());
}
