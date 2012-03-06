#include <stdio.h>
#include <unistd.h>
#include "error.h"

#define MAX_BUF 2046

int main(int argc, char* argv[])
{
    char buf[MAX_BUF];
    int  size = MAX_BUF;

    if ( getcwd(buf, size) == NULL ) {
        err_sys("getcwd failed");
    }

    printf("%s\n", buf);
}
