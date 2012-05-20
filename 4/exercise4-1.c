#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "error.h"

int main(int argc, char** argv)
{
    int            i;
    struct stat  buf;
    char        *ptr;

    for ( i = 1; i < argc; i++ ) {
        printf("%s: ", argv[i]);
        if ( stat(argv[i], &buf) < 0 ) {
            err_ret("stat error");
            continue;
        }

        if (S_ISREG(buf.st_mode))
            ptr = "regular";
        else if (S_ISDIR(buf.st_mode))
            ptr = "directory";

        printf("%s\n", ptr);
    }

    exit(0); 
}
