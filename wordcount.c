#include "shell.h"

int countword(char *str);
{
	int i = 0, w = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			w++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (w);
}
