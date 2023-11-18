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
extern char **environ;

#endif
