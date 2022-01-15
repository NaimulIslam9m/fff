#include "headers.h"

unsigned number_of_files(const char *path) {
    DIR *pDir;

    pDir = opendir(path);
    if (pDir == NULL)
        fprintf(stderr, "Opening directory '%s': %s\n", path, strerror(errno));

    unsigned cnt = 0;
    while (readdir(pDir) != NULL)
        cnt++;

    if (errno != 0)
        fprintf(stderr, "%s\n", strerror(errno));

    closedir(pDir);
    return cnt;
}


int explore(char **words, const int word_cnt) {
    struct dirent *pDirent;
    DIR *pDir;

    const char *path = (word_cnt == 1 ? "." : words[1]);
    const unsigned file_number = number_of_files(path);

    unsigned *type = (unsigned *) malloc(file_number * sizeof(int));
    char **name = (char **) malloc(file_number * sizeof(char *));

    if (type == NULL || name == NULL)
        fprintf(stderr, "%s\n", strerror(errno));

    pDir = opendir(path);

    if (pDir == NULL)
        fprintf(stderr, "Opening directory '%s': %s\n", path, strerror(errno));

    for (int i = 0; (pDirent = readdir(pDir)) != NULL; i++) {
        name[i] = pDirent->d_name;
        type[i] = pDirent->d_type;
        printf("%s\n", name[i]);
    }

    if (errno != 0)
        fprintf(stderr, "%s\n", strerror(errno));

    printf("\n%d files\n", file_number);

    closedir(pDir);

    return 0;
}