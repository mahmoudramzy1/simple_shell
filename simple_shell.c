#include "shell.h"




int main(void)
{
    pid_t child;
    char *path, *s = 0;
    int read = 0, i = 0, status;
    size_t len = 0;
    char **t;
	/*int exit_code = 0;*/
    while(1)
    {
        write(1, "$ ", 2);
        read = getline(&s, &len, stdin);
        if (read == -1)
		break;
	s[read - 1] = 0;
	t = argue(s);
	/*if (strcmp(t[0], "exit") == 0)
	{
		if (t[1])
			exit_code = atoi(t[1]);
		free (t);
		free (s);
		exit(exit_code);
	}*/
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

        child = fork();
        if (child == 0)
        {
                execve(path, t, environ);
		free(path);
                exit(127);
	}
	else if (child < 0)
	{	perror("fork error");
		free(path);}
	else
	{
        	waitpid(child, &status, 0);
		free(path);}
	}
	else
		printf("command not found\n");
	free(t);
	}
	free(s);
    }
    return (0);
}
