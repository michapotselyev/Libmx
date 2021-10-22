#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr)
{
    if (nbr < 1)
    {
        return 0;
    }

    unsigned long size = 0;
    unsigned long help = nbr;

    while (help)
    {
        unsigned long num = (help % 16);

        if (num > 9)
        {
            num += (unsigned long)'a' - 10;
        }

        else
        {
            num += (unsigned long)'0';
        }

        size++;
        help /= 16;
    }

    if (size < 0)
    {
        return NULL;
    }

    char *tmp = (char *)malloc(size + 1);

    for (unsigned long i = 0; i <= size; i++)
    { 
        tmp[i] = '\0';
    }

    while (nbr)
    {
        unsigned long num = (nbr % 16);
        if (num > 9)
        {
            num += (unsigned long)'a' - 10;
        }

        else
        {
            num += (unsigned long)'0';
        }

        tmp[--size] = (char)num;
        nbr /= 16;
    }

    return tmp;
}

