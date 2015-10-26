#include <stdio.h>
#include <dirent.h>
#include <string.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    char list[50];
    int ctr = 0;

    d = opendir(".");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
            list[ctr] = (char) dir->d_name;
        }
        closedir(d);
    }
    for (int i = 0; i < sizeof(list)/sizeof(int); i++) {
        printf("%s", list[i]);
    }

    getchar();
    return(0);
}
