#include <stdio.h>
#include <string.h>
#include "util.h"

int main(int argc, char* argv[]) {
    // usage of scan _token
    const char* input = "super-dr-awesome-magnificent";
    char buf[10];
    const char * remaining =input; 

    while(scan_token(&remaining, "-", buf, sizeof(buf))) {
        printf("Next token is: %s\n", buf);
    }    
    return 0;
}
