#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO "fifo1"

int main(void)
{
    FILE *fp;
    int i;
    char *str;

    if (mkfifo(FIFO, 0644) < 0)
        perror("mkfifo");

    if ((fp = fopen(FIFO, "w")) == NULL)
        perror("fopen");

    str = calloc(0, 3);

    for (i = 0; i < 26; i++) {
        sprintf(str, "%c\n", 'a' + i);
        fputs(str, fp);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
