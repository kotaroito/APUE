#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include "error.h"

int main(void)
{
    int  pid, shmid;
    int *ip;

    if ((shmid = shmget(IPC_PRIVATE, sizeof(int), 0600)) < 0 )
        err_sys("shmget");

    if ((ip = shmat(shmid, 0, 0)) == (void *) -1) {
        err_sys("shmat");
    }


    *ip = 1;

    if ((pid = fork()) < 0) {
        err_sys("fork");
    }
    else if ( pid == 0 ) {
        *ip = 100;
        exit(EXIT_SUCCESS);
    }
    waitpid(pid, NULL, 0);

    if (shmctl(shmid, IPC_RMID, 0) < 0)
        err_sys("shmctl");
   
    printf("*ip=%d\n", *ip);
    return EXIT_SUCCESS;
}
