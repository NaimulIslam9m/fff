#include "headers.h"

const int CMD_SIZE = 1000;
const int WORD_NUMBER = 100;

int main() {
    char *cmd = (char *) malloc(CMD_SIZE * sizeof(char));
    while (scanf(" %[^\n]", cmd) != EOF && strcmp(cmd, "q") != 0) {
        char **words = (char **) malloc(WORD_NUMBER);
        int word_cnt = 0;

        if (cmd == NULL || words == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }

        char *word = strtok(cmd, " ");
        while (word != NULL) {
            *(words + word_cnt) = word;
            word_cnt++;
            word = strtok(NULL, " ");
        }

        if (word_cnt == 3) {
            if (strcmp(*words, "cpy") == 0) {
                copy(*(words + 1), *(words + 2));
            } else if (strcmp(*words, "cut") == 0) {
                cut(*(words + 1), *(words + 2));
            } else if (strcmp(*words, "rnm") == 0) {
                _rename(*(words + 1), *(words + 2));
            }
        } else if (word_cnt == 2) {
            if (strcmp(*words, "exp") == 0) {
                explore(*(words + 1));
            } else if (strcmp(*words, "del") == 0) {
                _delete(*(words + 1));
            }
        } else if (word_cnt == 1) {
            if (strcmp(*words, "cls") == 0) {
                printf("\e[1;1H\e[2J");
            }
        }

        free(words);
    }
    return 0;
}