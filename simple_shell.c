#include "shell.h"
/**
 * main - print the prompt and waait the command from user
 * @argc: number of arguement
 * @argv: program name
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *path, *s = 0;
	int read = 0, line = 0, exit_num = 0, fd = isatty(STDIN_FILENO);
	size_t len = 0;
	char **t;
	(void)argc;

	while (1)
	{
		if (fd)
			write(1, "$ ", 2);
		read = getline(&s, &len, stdin);
		if (read == -1)
		{
			if (fd)
			{
				write(1, "\n", 1);
				line++;
			}
			break;
		}
		s[read - 1] = 0;
		
		t = argue(s);

		if (strcmp(s, "env") == 0)
                        builtin_env();
		
		if (strcmp(s, "exit") == 0)
		{	
			exit_num = t[1] ? atoi(t[1]) : exit_num;
			free(t);
			free(s);
			exit(exit_num);
		}
		
		else
		{
			path = getpath(s);
			if (path != NULL)
			{
				excuteme(path, t);
				if (strcmp(s, path) != 0)
					free(path);
			}
			else if (path == NULL && t[0] != NULL)
			{
 				fprintf(stderr, "%s: %d: %s: not found\n", argv[0], line, t[0]);
				exit_num = 127;
			}
			free(t);
		}

	}

		free(s);
	exit(exit_num);
}
