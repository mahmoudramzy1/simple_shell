#include "shell.h"
/**
 * main - print the prompt and waait the command from user
 * @argc: number of arguement
 * @argv: program name
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *s = 0;
	int read = 0, line = 0, exit_num = 0, fd = isatty(STDIN_FILENO);
	size_t len = 0;
	char **t;
	(void)argc;

	while (1)
	{
		line++;
		if (fd)
			write(1, "$ ", 2);
		read = getline(&s, &len, stdin);
		if (read == -1)
		{
			if (fd)
			{
				write(1, "\n", 1);
			}
			break;
		}
		s[read - 1] = 0;
		t = argue(s);

		builtin_env(s);
		if (strcmp(s, "exit") == 0)
			exit_fun(s, t);
		else
			exit_num = path_err(exit_num, s, t, argv[0], line);
	}
	free(s);
	exit(exit_num);
}
