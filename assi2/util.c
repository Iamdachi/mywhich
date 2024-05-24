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
    return NULL;
}

bool scan_token(const char **p_input, const char *delimiters, char buf[], size_t buflen) {
    // TODO
    size_t start_index = strspn(*p_input, delimiters);
    *p_input += start_index;
    
    size_t tok_len = strcspn(*p_input, delimiters);
    
    if (tok_len == 0) return false;

    if (tok_len > buflen) {
        tok_len = buflen - 1; // leave space for null terminator
    }

    strncpy(buf, *p_input, tok_len);
    buf[tok_len] = '\0';
    *p_input += tok_len;

    return true;
}
