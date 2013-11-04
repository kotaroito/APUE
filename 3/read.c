/*
 * =====================================================================================
 *
 *       Filename:  read.c
 *
 *    Description:  read
 *
 *        Version:  1.0
 *        Created:  2013/09/29 15時34分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "error.h"

#define BUFFSIZE 1024

int main(int argc, char** argv) 
{
   int fd;
   char buff[BUFFSIZE];
   int n;
   int i;

   fd = open("/tmp/kotaro", (O_RDONLY));
   while ( n = read(fd, buff, 1) > 0 ) {
       write(STDOUT_FILENO, buff, n);
   }
   close(fd);
}

