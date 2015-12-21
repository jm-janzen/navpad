#include <stdio.h>
#include <string.h>
#include <dirent.h>

/* XXX bugs:
 * 1)   entering N greater than sizeof num files: segmentation fault
 * 2)   entering directory typeof int: segmentation fault
 * 3)   attempting to read file (not dir): segmentation fault
 */
 
/*
 * prototypes
 */
void prompt();
void read(char*);
char* match(int);

struct  dirent *dir;
char*   dirStack[255];
int     answer;
int     noRun;

int main(void) {
    read("."); // start us off
    do {
        prompt();
    } while (1);
}

/* TODO
 * validate answer
 */
void prompt() {
    char* got;

    do {
        printf("\n> ");
        scanf("%d", &answer);
    } while (getchar() != '\n');
    switch (answer) {
        case (0):
            printf("going back\n");
            read("../");
            break;
        default:
            printf("default\n");
    }

    got = match(answer);
    printf("got:%s\n", got);
    read(got);
}

/*
 * read cwd and store for action
 */
void read(char* l) {
    DIR* d = opendir(l);
    if (d == NULL) {
        printf("Error! Could not open directory %s", l);
    }

    int idx = 0;
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
            if (idx == 0) {
                printf("[%d]\t%s\n", idx, "../");
            }
            idx++; // start at [1], [0] reserved for prev dir
            dirStack[idx] = fileName;
            printf("[%d]\t%s\n", idx, dirStack[idx]);
        }
    }
    closedir(d);
}

/*
 * match answer == index in directory stack
 */
char* match(int a) {
    printf("match(%d)\n", a);
    if (a == 0) {
        return "../";
    }
    for (int i = 0; i < sizeof(dirStack); i++) {
        if (i == a) {
            printf("Found %s\n", dirStack[i]);
            return dirStack[i];
        }
    }
}

