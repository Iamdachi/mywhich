#include <stdio.h>
#include "util.h"

int main(int argc, char * argv[], const char * envp[]) {
    const char * key = "USER";
    const char * value = get_env_value(envp, key);
    printf("result of getenv: %s\n", value);
    return 0;
}
