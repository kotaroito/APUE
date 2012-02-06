#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifndef ERROR_H
#define ERROR_H
void err_doit(int useerrno, const char *fmt, va_list ap);
void err_ret(const char *fmt, ...);
void err_quit(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
#endif
