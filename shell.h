#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int countword(char *str);
<<<<<<< HEAD
char *getpath(char *str);

extern char **environ;
=======
char getpath(char str);
int countword(char *str);
>>>>>>> 68a9fb94c3cacdd773cc2ed189e3a64fa9198006

#endif
