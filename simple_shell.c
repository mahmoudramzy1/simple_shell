#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
        char *s = NULL;
        size_t n = 0;
        char *token;
        char **tokenArray;
        int status, i = 0;
        pid_t child_pid;
        int m;
        /*char *pathtoken;
        char *p = {"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"};
        char *command = NULL;*/

        while (1)
        {
                write(1, "#cisfun$ ", 9);
                m = getline(&s, &n, stdin);
                if (m == -1)
                        exit(1);

                token = strtok(s, " \t\n");
                tokenArray = malloc(sizeof(char *) * 1024);
                while (token)
                {
                        tokenArray[i] = token;

                        token = strtok(NULL, "\t\n");
                        i++;
                }
                tokenArray[i] = NULL;
                /* pathtoken = strtok(p, ":");
                while (pathtoken)
                {
                        command = malloc(strlen(pathtoken) + strlen(tokenArray[0]) + 2);
                        if (command == NULL)
                        {
                                perror("error allocate");
                                exit(2);
                        }

                        strcpy(command, pathtoken);
                        strcat(command, "/");
                        strcat(command, tokenArray[0]);
                        if (access(command, F_OK) == 0)
                                break;
                        free(command);
                        pathtoken = strtok(NULL, ":");
                }*/
                child_pid = fork();
                if (child_pid == -1)
                        perror("Error");
                else if (child_pid == 0)
                {
                        execve(tokenArray[0], tokenArray, NULL);

                        perror("error");

                }
                else
                {
                        wait(&status);
                }
                free(tokenArray);
                i = 0;
        }

}
