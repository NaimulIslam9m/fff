#include "headers.h"

int _rename(const char *old_path, const char *new_path) {
    rename(old_path, new_path);

    return 0;
}