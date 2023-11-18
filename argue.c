#include "shell.h"

char **argue(char *n)
{
	int i = 0;
	int m = countword(n);
	char **t = malloc((m + 1) * sizeof(char *));
	t[i] = strtok(n, " ");
	while (t[i])
	{
		i++;
		t[i] = strtok(NULL, " ");

	}
	return (t);
}
