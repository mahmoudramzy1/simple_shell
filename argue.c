#include "shell.h"
/**
 * argue - tokenize the command and place it in array
 * @n: command
 * Return: array of command
 */

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
