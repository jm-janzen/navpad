#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name != "..") {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    }

    getchar();
    return(0);
}
