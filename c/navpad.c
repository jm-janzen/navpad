#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    int i;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("\[%d\]\t %s\n"
              , i, dir->d_name);
            i++;
        }
        closedir(d);
    }

    getchar();
    return(0);
}
