#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    if (buf_size == 0)
    {
        return -2;
    }

    buf_size = 1;
    int res = 0;
    int bytes;
    char *temp = *lineptr;
    *lineptr = NULL;
    char *buffer = mx_strnew(buf_size);

    while ((bytes = read(fd, buffer, buf_size)) > 0)
    {
        if (mx_get_char_index(buffer, delim) >= 0)
        {
            buffer[mx_get_char_index(buffer, delim)] = '\0';

            if (!*lineptr && !buffer)
            {
                *lineptr = NULL;
            }

            else if (!*lineptr && buffer)
            {    
                *lineptr = mx_strdup(buffer);
            }
            
            else if (*lineptr && !buffer)
            {    
                *lineptr = mx_strdup(*lineptr);
            }
            
            else
            {
                char *new_str = mx_strnew(mx_strlen(*lineptr) + mx_strlen(buffer));
                new_str = mx_strcat(mx_strcpy(new_str, *lineptr), buffer);
                char *to_delete = (char*)*lineptr;
                mx_strdel(&to_delete);
                *lineptr = new_str;
            }

            res += mx_strlen(buffer);
            free(buffer);
            free(temp);
            return res;
        }

        if (!*lineptr && !buffer)
        {
            *lineptr = NULL;
        }

        else if (!*lineptr && buffer)
        {    
            *lineptr = mx_strdup(buffer);
        }
        
        else if (*lineptr && !buffer)
        {    
            *lineptr = mx_strdup(*lineptr);
        }
        
        else
        {
            char *new_str = mx_strnew(mx_strlen(*lineptr) + mx_strlen(buffer));
            new_str = mx_strcat(mx_strcpy(new_str, *lineptr), buffer);
            char *to_delete = (char*)*lineptr;
            mx_strdel(&to_delete);
            *lineptr = new_str;
        }
        
        res += bytes;
    }

    if (res == 0)
    {
        *lineptr = temp;
        free(buffer);

        if (bytes == -1)
        {    
            return -2;
        }

        else
        {   
            return -1;
        }
    }

    free(buffer);
    return res;
}

