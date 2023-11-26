#include "shell.h"
/**
 * exit_fun - exit with the exit_number
 * @s: the command
 * @t: exit with number
 */
void exit_fun(char *s, char **t)
{
	int exit_num = 0;

	exit_num = t[1] ? atoi(t[1]) : exit_num;
	free(t);
	free(s);
	exit(exit_num);
}
