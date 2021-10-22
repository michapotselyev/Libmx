#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
    if (hex == NULL) return 0;
    unsigned long len = 0;
    unsigned long i = 0;
    unsigned long val = 0;
    unsigned long number = 0;     
    for (; hex[len] != '\0'; len++);
    len--;

    while(hex[i] != '\0')
    {  
        if(hex[i] >= '0' && hex[i] <= '9')
        {  
            val = hex[i] - 48;  
        }

        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {  
            val = hex[i] - 97 + 10;  
        }

        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {  
            val = hex[i] - 65 + 10;  
        }

        else
        {
            return 0;
        }

        unsigned long tmp = 1; 

        for (unsigned long j = 0; j < len; j++)
        {
            tmp *= 16;
        }

        number += val * tmp;
        i++;
        len--;
    }

    return number;
}

