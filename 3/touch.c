#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 10

int main(int argc, char *argv[])
{
    int fd; 
    int i;
    char buf[BUFSIZE] = "1234567890";
    
    fd = open("./tmp", O_WRONLY | O_CREAT );

    for ( i = 0; i < 10; i++ ) {
        // can't write... why?
        write(fd, buf, 10); 
    }

    close(fd);
}
