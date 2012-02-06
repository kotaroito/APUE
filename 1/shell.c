#include <stdio.h>
#include <sys/types.h>
#include <string.h>

#define MAXLINE 4096

int main(int argc, char *argv[])
{
    char  buf[MAXLINE];
    pid_t pid;
    int   status;

    printf("%% ");
    while ( fgets(buf, MAXLINE, stdin) != NULL ) {
        printf("%zd\n", strlen(buf));
    }
}
