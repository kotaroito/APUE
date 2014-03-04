#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define DEF_PAGER "/usr/bin/less"
#define MAXLINE   1024

int main(int argc, char* argv[])
{
    int    n;
    int    fd[2];
    pid_t  pid;
    char   *pager, *argv0;
    char   line[MAXLINE];
    FILE   *fp;

    if (argc != 2)
        exit(EXIT_FAILURE);

    if ((fp = fopen(argv[1], "r")) == NULL)
        exit(EXIT_FAILURE);

    if (pipe(fd) < 0)
        perror("pipe");

    if ((pid = fork()) < 0) {
        perror("fork");
    }
    else if (pid > 0) { /* parent */
        close(fd[0]);

        while (fgets(line, MAXLINE, fp) != NULL) {
            n = strlen(line);
            if (write(fd[1], line, n) != n)
                perror("write");
        }

        if (ferror(fp))
            perror("fgets");

        close(fd[1]);
        fclose(fp);

        if (waitpid(pid, NULL, 0) < 0)
            perror("waitpid");

        exit(EXIT_SUCCESS);
    }
    else { /*  child  */
        close(fd[1]);

        if (fd[0] != STDIN_FILENO) {
            if( dup2(fd[0], STDIN_FILENO) != STDIN_FILENO) {
                perror("dup2");
            }
            close(fd[0]);
        }

        if ((pager = getenv("PAGER")) == NULL)
            pager = DEF_PAGER;

        if ((argv0 = strrchr(pager, '/')) != NULL) {
            argv0++;
        }
        else {
            argv0 = pager;
        }

        if (execl(pager, argv0,(char *)0) < 0)
            perror("execl");
    }

    return EXIT_SUCCESS;
}
