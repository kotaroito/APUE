#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include "error.h"

int main(int argc, char* argv[])
{
    DIR           *dp;
    struct dirent *dirp;

    if ( chdir("/tmp") < 0 ) {
        err_sys("chdir failed");
    }
    
    if ( (dp = opendir(".")) == NULL ) {
        err_sys("opendir failed");
    }

    while ( (dirp = readdir(dp)) != NULL ) {
        printf("%s\n", dirp->d_name);
    }
}
