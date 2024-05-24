#include <stdio.h>
#include <string.h>
#include "util.h"

#define PATH_MAX 4096

int main(int argc, char *argv[], const char *envp[]) {
    const char *searchpaths = get_env_value(envp, "MYPATH");
    if (searchpaths == NULL)
        searchpaths = get_env_value(envp, "PATH");

    if (argc == 1) {
        char dir[PATH_MAX+1];
        const char *remaining = searchpaths;

        printf("Directories in search path:\n");
        while (scan_token(&remaining, ":", dir, sizeof(dir)))
            printf("%s\n", dir);
    }

    return 0;
}    
