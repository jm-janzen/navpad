#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    int idx;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (!strcmp(dir->d_name, "..") || !strcmp(dir->d_name, ".")) {
                /*
                 * skip this item
                 */
            } else {
                idx++;
                printf("\[%d\]\t %s\n"
                  , idx, dir->d_name);
            }
        }
        closedir(d);
    }

    getchar();
    return(0);
}
