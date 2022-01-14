#include "headers.h"

int explore(const char *path) {
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(path);
    if (pDir == NULL) {
        printf("Cannot open directory '%s'\n", path);
    }

    while ((pDirent = readdir(pDir)) != NULL)
        printf("%s\n", pDirent -> d_name);

    closedir(pDir);

    return 0;
}