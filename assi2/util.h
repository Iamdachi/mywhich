#ifndef UTIL_H
#define UTIL_H


#include <stdbool.h>
#include <stddef.h>


const char * get_env_value(const char * envp[], const char * key);
bool scan_token(const char **p_input, const char *delimiters, char buf[], size_t buflen);

#endif // UTIL_H
