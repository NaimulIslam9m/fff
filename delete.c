#include "headers.h"

int _delete(char *path) {
    unlink(path);

    return 0;
}