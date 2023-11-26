#include "shell.h"
/**
 * builtin_env - print the environment
 * @s: user's command
 */
void builtin_env(char *s)
{
	int i = 0;

	if (strcmp(s, "env") == 0)
	{
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
	i = 0;
	}
}
