#include "shell.h"
/**
 * path_err - call path and if detect an error print error massage
 * @exit_num: exit number
 * @s: user's command
 * @t: the array of arguement
 * @a: program name
 * @line: line number
 * Return: exit number
 */
int path_err(int exit_num, char *s, char **t, char *a, int line)
{
	char *path;

	path = getpath(s);

	if (path != NULL)
	{
		excuteme(path, t);
		if (strcmp(s, path) != 0)
			free(path);
	}
	else if (path == NULL && t[0] != NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", a, line, t[0]);
		exit_num = 127;
	}
	free(t);
	return (exit_num);
}
