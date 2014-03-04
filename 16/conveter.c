#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int    i = 0x0a0b0c0d;
    char *cp = (char *)&i;
    printf("%02x\n", *cp);
    return EXIT_SUCCESS;
}
