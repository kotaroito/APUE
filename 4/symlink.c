#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

    if ( symlink("actual", "symlink") == 0 ) {
            printf("success\n");
    }
}
