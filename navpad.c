#include <stdio.h>
#include <string.h>
#include <dirent.h>
 
void prompt();
void read(char*);
char* match(int);

struct  dirent *dir;
int     idx;
char*   dirStack[255];
int     answer;
int     noRun;

int main(void) {
    while (1) {
        read(".");
        prompt();
    }
}

void prompt() {
    char* got;
    printf("\n> ");
    scanf("%d", &answer);
    /* TODO
     * read answer and compare to dirStack,
     * then show + print new list at that String.
     */

    got = match(answer);
    printf("got:%s\n", got);

    read(got); /* TODO take String variable from match, rather than literal value */
}

/*
 * read cwd and store for action
 */
void read(char* l) {
    printf("read(%s)\n", l);

    DIR* d = opendir(l);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            char* fileName = dir->d_name;
            if (!strcmp(fileName, "..") || !strcmp(fileName, ".")) {
                /*
                 * supress display of ./ ../
                 */
            } else if (!strncmp(".", fileName, 1)) {
                /*
                 * suppress display of hidden files
                 */
            } else {
                idx++;
                dirStack[idx] = fileName;
                printf("[%d]\t%s\n", idx, dirStack[idx]);
            }
        }
        closedir(d);
    }
}

/*
 * match answer == index in directory stack
 */
char* match(int a) {
    printf("match(%d)\n", a);
    for (int i = 0; i < sizeof(dirStack); i++) {
        //printf("for i < %d", sizeof(dirStack));
        if (i == a) {
            printf("Found %s\n", dirStack[i]);
            return dirStack[i];
        }
    }
}

