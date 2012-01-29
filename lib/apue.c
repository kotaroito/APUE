#include <stdio.h>
#include <stdlib.h>
#include "apue.h"

void err_sys(const char *fmt, ...)
{
    printf("%s\n", fmt);
    exit(1);
}
