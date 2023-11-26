#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int countword(char *str);
char *getpath(char *str);
char **argue(char *n);
void excuteme(char *path, char **t);
void builtin_env(char *s);
void exit_fun(char *s, char **t);
int path_err(int exit_num, char *s, char **t, char *a, int line);
extern char **environ;

#endif
