#ifndef HEADERS_H_
#define HEADERS_H_

#define _LARGEFILE64_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int explore(const char *path);
int copy(const char *src_path, const char *dst_path);
int cut(const char *src_path, const char *dst_path);
int _delete(char *path);
int _rename(const char *old_path, const char *new_path);
void ckerror(int val, char *str);
int help();

#endif