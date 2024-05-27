#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

#define PATH_MAX 4096

int main(int argc, char *argv[], const char *envp[]) {
    const char *searchpaths = get_env_value(envp, "MYPATH");
    if (searchpaths == NULL)
        searchpaths = get_env_value(envp, "PATH");

    if (searchpaths == NULL) return 1;
    
    // if no arguments are given just print PATH variable paths
    if (argc == 1) {
        char dir[PATH_MAX+1];
        const char *remaining = searchpaths;

        printf("Directories in search path:\n");
        while (scan_token(&remaining, ":", dir, sizeof(dir)))
            printf("%s\n", dir);
        return 0;
    }


    for (int i = 1; i < argc; i++) {
    
   // printf("________> %s\n", argv[i]);
    char dir[PATH_MAX+1];
    const char *remaining = searchpaths;
    
    while (scan_token(&remaining, ":", dir, sizeof(dir))){
	char slash[] = "/";
        strcat(dir, slash);
        strcat(dir, argv[i]);

	if (access(dir, F_OK) != -1) {
	   printf("%s\n", dir);
           break;	   
	}

    }
    
    }
    return 0;
}    
