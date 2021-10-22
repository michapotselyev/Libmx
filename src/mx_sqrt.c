#include "../inc/libmx.h"

int mx_sqrt(int x)
{
    if (x <= 0)
    {
        return 0;
    }

    int tmp = 1;
    int count = 1;

    while (x > count && count > 0)
    {
        tmp++;
        count = tmp * tmp;
    }

    if (count == x)
    {
        return tmp;
    }

    return 0;
}

