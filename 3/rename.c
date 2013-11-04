/*
 * =====================================================================================
 *
 *       Filename:  rename.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/09/29 15時50分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "error.h"

int main(int argc, char** argv)
{

    char oldname[1024] = "/tmp/kotaro.tmp";
    char newname[1024] = "/tmp/kotaro";

    rename(oldname, newname);
}
