#include <stdio.h>
#include <string.h>
#include <dirent.h>
 
void prompt();
void read(char*);

struct  dirent *dir;
int     idx;
char*   dirStack[255][255];
int     answer;
int     noRun;

int main(void) {
    read(".");
    prompt();
}

void prompt() {
    printf("> ");
    scanf("%d", &answer);
    /* TODO
     * read answer and compare to dirStack,
     * then print new list at that String.
     */
    read("b");
}
void read(char* l) {
    DIR* d = opendir(l);
    if (d) {
        /* TODO
         * flip and combine this logic
         * into on giant if statement
         */
        while ((dir = readdir(d)) != NULL) {
            char* fileName = dir->d_name;
            if (!strcmp(fileName, "..") || !strcmp(fileName, ".")) {
                /*
                 * skip this item
                 */
            } else if (!strncmp(".", fileName, 1)) {
                /*
                 * suppress display of hidden files
                 */
            } else {
                idx++;
                dirStack[noRun][idx]= fileName;
                printf("%s\n", dirStack[noRun][idx]);
            }
        }
        closedir(d);
    }
    noRun++;
}
