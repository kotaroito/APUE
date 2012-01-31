#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("%ld\n", sysconf(_SC_OPEN_MAX));
}
