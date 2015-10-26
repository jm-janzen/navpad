#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    int idx;
    char* dirStack[255];
    d = opendir(".");
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
                printf("\[%d\]\t %s\n"
                  , idx, fileName);
            }
        }
        closedir(d);
    }

    getchar();
    return(0);
}
