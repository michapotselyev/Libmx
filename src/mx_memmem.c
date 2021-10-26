#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    uc_t *big_temp = NULL;
	uc_t *little_temp = NULL;

	if (big_len >= little_len && big_len > 0 && little_len > 0)
    {
		big_temp = (uc_t *)big;
		little_temp = (uc_t *)little;

		while (*big_temp)
        {
			if (mx_memcmp(big_temp, little_temp, little_len - 1) == 0)
            {
				return big_temp;
            }

			big_temp++;
		}
	}

	return NULL;
}

