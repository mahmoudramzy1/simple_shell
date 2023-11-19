#include "shell.h"
/**
 * main - print the prompt and waait the command from user
 * Return: 0
 */
int main(void)
{
	char *path, *s = 0;
	int read = 0, i = 0;
	size_t len = 0;
	char **t;

	while (1)
	{
		write(1, "$ ", 2);
		read = getline(&s, &len, stdin);
		if (read == -1)
			break;
		s[read - 1] = 0;
		t = argue(s);
		if (strcmp(t[0], "env") == 0)
		{
			while (environ[i])
			{
				printf("%s\n", environ[i]);
				i++;
			}
			free(t);
		}
		else
		{
			path = getpath(s);
		if (path != NULL)
		{
			excuteme(path, t);
		}
		else
			printf("command not found\n");
		free(t);
		}
	free(s);
	}
	return (0);
}
