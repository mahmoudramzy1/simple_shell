#include "shell.h"
/**
 * excuteme - fork the process and excute the program
 * @path: the full path of program
 * @t: the array of user's commadn
 * Return:0
 */
void excuteme(char *path, char **t)
{
	int status;
	pid_t child;

	child = fork();
	if (child == 0)
	{
		execve(path, t, environ);
		free(path);
		exit(127);
	}
	else if (child < 0)
	{
		perror("fork error");
		free(path);
	}
	else
	{
		waitpid(child, &status, 0);
		free(path);
	}
}
