#include <strings.h>
#include <string.h>
#include "util.h"

const char * get_env_value(const char * envp[], const char * key) {
    // TODO
    for (int i = 0; envp [i] != NULL; i++) {
        char * result = strstr(envp[i], key);
	if (result == envp[i]) {
	    return (result + strlen(key) + 1);
	}
    }
    return "get_env_value called!\n\0";
}

bool scan_token(const char **p_input, const char *delimiters, char buf[], size_t buflen) {
    // TODO
    return "scan_token called!\n\0";
}
