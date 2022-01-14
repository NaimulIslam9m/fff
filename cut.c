#include "headers.h"

int cut(const char *src_path, const char *dst_path) {
    open(dst_path, O_TRUNC);
    copy(src_path, dst_path);
    open(src_path, O_TRUNC);

    return 0;
}