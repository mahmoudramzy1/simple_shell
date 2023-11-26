#include "shell.h"
/**
 * builtin_env - print the environment
 * @s: user's command
 */
void builtin_env(void)
{
	int i = 0;

	 while (environ[i])
                        {
                                printf("%s\n", environ[i]);
                                i++;
                        }
                        i = 0;

}
