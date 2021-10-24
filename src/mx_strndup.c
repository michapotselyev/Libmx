#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    size_t len = (size_t)mx_strlen(s1);

    if (n < len)
    {
        len = n;
    }

    char *tmp = mx_strnew(len);
    mx_strncpy(tmp, s1, len);
    return tmp;
}

