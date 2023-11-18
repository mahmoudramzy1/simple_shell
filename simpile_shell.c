#include "shell.h"

extern char **environ;



int main(void)
{
<<<<<<< HEAD
    pid_t child;
    char *path;
    int read = 0;
    char *s = 0;
    size_t len = 0;
    char *prompt = "$ ";
    char **t = 0;
    int status;
    int n = 0;
    int j = 0;
    /*int i = 0;*/
    
    while(1)
    {
        write(1, prompt, 2);
        read = getline(&s, &len, stdin);
	if (read == -1)
            break;
        s[read - 1] = 0;
	n = countword(s);
	t = malloc((n + 1) * sizeof(char *));
	if (t == NULL)
		return (0);
	t[j] = strtok(s, " ");
	/*if (strcmp(s, "env"))
	{
		while (environ[i])
		{	
			printf("%s\n", environ[i++]);
		}
	}*/
	while(t[j])
=======
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
	* while (environ[i]) 
	printf("%s\n", environ[i++]);*/

	while (1)
>>>>>>> 68a9fb94c3cacdd773cc2ed189e3a64fa9198006
	{
		write(1, prompt, 2);
		read = getline(&s, &len, stdin);
		if (read == -1)
			break;
		s[read - 1] = 0;
		n = countword(s);
		t = malloc((n + 1) * sizeof(char *));
		t[j] = strtok(s, " ");
		while (t[j])
	}
<<<<<<< HEAD
	t[j] = NULL;
        path = getpath(s);
        if (path != NULL)
        {

        child = fork();
	if (child == 0)
        {
		execve(path, t, environ);
          
               	exit(0);
	}
	
	else if (child < 0)
		perror("fork error");
	else
		waitpid(child, &status, 0);
	}
	else
	{
		perror("command not found");
	}
	n = 0;
    }
        return(0);   
=======
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
		return (0);
>>>>>>> 68a9fb94c3cacdd773cc2ed189e3a64fa9198006
}
