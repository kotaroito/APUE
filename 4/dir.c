#include <dirent.h>
#include <stdio.h>
#include "error.h"

int main(int argc, char** argv)
{
    DIR           *dp;
    struct dirent *dirp;

    if ( (dp = opendir(".")) == NULL ) {
        err_sys("can't open");
    }

    while ( (dirp = readdir(dp)) != NULL ) {
        printf("%s\n", dirp->d_name);
    }

    if ( closedir(dp) < 0 ) {
        err_sys("can't close");
    }
}
