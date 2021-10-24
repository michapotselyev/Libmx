#include "../inc/libmx.h"

int mx_count_words(const char *str, char c)
{
    if (str == NULL)
    {
        return -1;
    }

    bool word = true;
    unsigned count = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == c)
        {
            word = true;
        }

        else if (word)
        {
            word = false;
            count++;
        }

        i++;
    }

    return count;
}

