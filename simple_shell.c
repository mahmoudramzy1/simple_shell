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
	int fd = isatty(STDIN_FILENO);

	while (1)
	{
		if (fd)
			write(1, "$ ", 2);
		read = getline(&s, &len, stdin);
		if (read == -1)
		{
			write(1, "\n", 1);
			break;
		}
		s[read - 1] = 0;
		if (strcmp(s, "env") == 0)
		{
			while (environ[i])
			{
				printf("%s\n", environ[i]);
				i++;
			}
			i = 0;
		/*	free(s);*/
		}
		else
		{
			t = argue(s);
			path = getpath(s);
			if (path != NULL)
			{
				excuteme(path, t);
				free(path);
			}
			else if (path == NULL)
			{
 				printf("command not found\n");
			}
			free(t);
		}

	}
	free(s);
	return(0);
}
