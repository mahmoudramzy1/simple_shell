#include "shell.h"

int countword(char *str)
{
    int w = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ')
        {
            w++;
            while (str[i] != ' ' && str[i] != '\0')
            {
                i++;
            }
        }
        else
            i++;
    }
    return (w);
}
