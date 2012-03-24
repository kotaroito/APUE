#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "error.h"

int main(int argc, char* argv[])
{
    struct stat buf;

    if ( argc < 2 ) {
        err_quit("no args");
    }

    if ( stat(argv[1], &buf) < 0 ) {
        err_sys("stat err");
    }

    if ( buf.st_mode & S_ISUID ) {
        printf("set-user-ID: ON\n");
    }

    if ( buf.st_mode & S_ISVTX ) {
        printf("Sticky Bit: ON\n");
    }
}
