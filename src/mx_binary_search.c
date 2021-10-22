#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    int beg = 0;
    int end = size - 1;
    int itr = 0;

    while (beg <= end)
    { 
        itr++;
        int mid = (end + beg) / 2;

        if (mx_strcmp(arr[mid],s) > 0)
        {
            end = mid - 1;
        }

        else if (mx_strcmp(arr[mid],s) < 0)
        {
            beg = mid + 1;
        }

        else
        {
            *count = itr;
            return mid;
        } 
    }

    *count = 0;
    return -1;
}

