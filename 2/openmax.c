#include <errno.h>
#include <limits.h>
#include <stdio.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

int main(int argc, char *argv[])
{
   printf("%ld\n", openmax); 
}
