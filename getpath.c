#include "shell.h"
/**
 * getpath - checks the path of the file
 * @str: user's command
 * Return: the full path of excutable file
 */

char *getpath(char *str)
{
	char *result;
	char *tokenpath;
	char *cpypath;
	char *p = getenv("PATH");

	if (access(str, X_OK) == 0)
		return (str);
	if (p != 0)
	{
		cpypath = strdup(p);
		tokenpath = strtok(cpypath, ":");
		while (tokenpath)
		{
			result = malloc(strlen(tokenpath) + strlen(str) + 2);
			strcpy(result, tokenpath);
			strcat(result, "/");
			strcat(result, str);
			strcat(result, "\0");
			if (access(result, X_OK) == 0)
			{
				free(cpypath);
				return (result);
			}
			free(result);
			tokenpath = strtok(NULL, ":");
		}
	}
	free(cpypath);
	return (NULL);
}
