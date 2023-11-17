#include "shell.h"

extern char **environ;



int main(void)
{
    pid_t child;
    char *path;
    int read = 0;
    char *s = 0;
    size_t len = 0;
    char *prompt = "$ ";
    char **t;
    int status;
    int n;
    int j = 0;
    /*int i = 0;
    while (environ[i]) 
        printf("%s\n", environ[i++]);*/
    
    while(1)
    {
        write(1, prompt, 2);
        read = getline(&s, &len, stdin);
        if (read == -1)
            break;
        s[read - 1] = 0;
	n = countword(s);
	t = malloc((n + 1) * sizeof(char *));
	t[j] = strtok(s, " ");
	while(t[j])
	{
		j++;
		t[j] = strtok(NULL, " ");
	}
        path = getpath(s);
        if (path != 0)
        {

        child = fork();
	if (child < 0)
	{
		perror("fork error");
	}
        if (child == 0)
        {
		t[0] = s;
		if (execve(path, t, environ) == -1)
			perror("execute error");
            
                exit(127);
	}
        waitpid(child, &status, 0);

                

            
        }
	else
		perror("command not found");
    }
        return(0);   
}
