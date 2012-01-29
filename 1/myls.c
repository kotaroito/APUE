#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "apue.h"

int main(int argc, char *argv[])
{
    DIR           *dp;
    struct dirent *dirp;

    if ( argc != 2 )
        err_sys("specify dir");

    if ((dp = opendir(argv[1])) == NULL )
        exit(1);
    
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
    exit(0);
}
