#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *getpath(char *str)
{
    char *result;
    char *tokenpath;
    char *cpypath;
    char *p = getenv("PATH");
    if(access(str, X_OK) == 0)
        return(str);
    if (p != 0)
    {
        cpypath = strdup(p);
        tokenpath = strtok(cpypath, ":");
        while(tokenpath)
        {
            result = malloc(strlen(tokenpath) + strlen(str) + 2);
            strcpy(result, tokenpath);
            strcat(result, "/");
            strcat(result, str);
            strcat(result, "\0");
            if (access(result, X_OK) == 0)
                return (result);
            tokenpath = strtok(NULL, ":");


        }


    }

    return (NULL);
}


int main(void)
{
    pid_t child;
    char *path;
    int read = 0;
    char *s = 0;
    size_t len = 0;
    char *prompt = "$ ";
    char **t = malloc(100);
    int status;
    /*int j = 0;
    int i = 0;
    while (environ[i])
        printf("%s\n", environ[i++]);*/

    while(1)
    {
        write(1, prompt, 2);
        read = getline(&s, &len, stdin);
	if (s == NULL)
		continue;
	else
	{
        if (read == -1)
            break;
        s[read - 1] = 0;
	t = argue(s);
        path = getpath(s);
	if (path != NULL)
        {

        child = fork();
        if (child == 0)
        {
                execve(path, t, environ);

                exit(127);
	}
	else if (child < 0)
		perror("fork error");
	else
        	waitpid(child, &status, 0);
        }
	else
		printf("command not found");
    }}
    return (0);
}