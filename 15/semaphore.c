#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

#define SEM_SIZE 1
#define CONCURRENCY 10

int my_sem_incr(int semid)
{
    struct sembuf semoparray[1];
    semoparray[0].sem_num = 0;
    semoparray[0].sem_op  = 1;
    semoparray[0].sem_flg = 0;

    return semop(semid, semoparray, 1);
}

int my_sem_decr(int semid) {
    struct sembuf semoparray[1];
    semoparray[0].sem_num = 0;
    semoparray[0].sem_op  = -1;
    semoparray[0].sem_flg = 0;

    return semop(semid, semoparray, 1);
}

int my_sem_curr(int semid) {
    return semctl(semid, 0, GETVAL);
}

void wait_all(void) {
    int i;
    for (i =0; i < CONCURRENCY; i++)
        wait(NULL);
}


int main(void)
{
    int semid;
    int semnum;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short  *array;
    } arg;

    int i;
    int pid;

    // semaphoreの集合（ここでは要素数1）を得る
    if ((semid = semget(IPC_PRIVATE, SEM_SIZE, 0666)) < 0) {
        perror("semget");
    }

    // semaphore集合の要素番号0に対して、2をセットする
    arg.val = 2;
    semnum  = 0;
    if (semctl(semid, semnum, SETVAL, arg) < 0) {
        perror("semctl:SETVAL");
    }

    for (i = 0; i < CONCURRENCY; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
        }
        else if (pid == 0) { /* child */
            my_sem_decr(semid); // semaphoreが正になるまでブロック

            printf("pid[%d]\n", getpid());
            sleep(2);
            my_sem_incr(semid);

            exit(EXIT_SUCCESS);
        }
    }

    wait_all();
    printf("wait_all() done\n");


    // semaphoreを削除する
    if (semctl(semid, semnum, IPC_RMID) < 0) {
        perror("semctl:IPC_RMID");
    }

    return EXIT_SUCCESS;
}
