/*
 * =====================================================================================
 *
 *       Filename:  pipe.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/11/16 17時09分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "error.h"

#define MAXLINE 1024

int main (void)
{
    int   n;
    int   fd[2];
    pid_t pid;
    char  line[MAXLINE];

    if (pipe(fd) < 0) {
        err_sys("pipe error");
    }

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid > 0) { /* parent  */
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
    } else { /* child */
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }
    exit(0);
}
