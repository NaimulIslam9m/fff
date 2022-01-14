#include "headers.h"

const int FILE_SIZE = 1000;

int copy(const char *src_path, const char *dst_path) {
    int fd_src = open(src_path, O_RDWR);
    int fd_dst = open(dst_path, O_RDWR);
    char *str = (char *) malloc(FILE_SIZE * sizeof(char));

    read(fd_src, str, FILE_SIZE);
    write(fd_dst, str, strlen(str));

    return 0;
}