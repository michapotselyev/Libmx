#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow)
{
    if (pow == 0)
    {
        return 1;
    }

    double tmp = 1;

    for(; pow > 0; pow--)
    {
        tmp *= n;
    }

    return tmp;
}

