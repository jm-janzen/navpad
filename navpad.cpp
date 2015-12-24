#include <stdio.h> // TODO replace w/ iostream
#include <string>
#include <cstring>
#include <dirent.h>
using namespace std;

/* XXX bugs:
 * 1)   entering N greater than sizeof num files: segmentation fault
 * 2)   entering directory typeof int: segmentation fault
 * 3)   attempting to read file (not dir): segmentation fault
 */
 
/*
 * prototypes
 */
void prompt();
void read(string);
string match(int);

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
    string got;

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
    printf("got:%s\n", got.c_str());
    read(got);
}

/*
 * read cwd and store for action
 */
void read(string l) {
    DIR* d = opendir(l.c_str());
    if (d == NULL) {
        printf("Error! Could not open directory %s", l.c_str());
    }

    int idx = 0;
    while ((dir = readdir(d)) != NULL) {
        char* fileName = dir->d_name;
        if (!strncmp(fileName, ".", 1) != 0) {
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
string match(int a) {
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

