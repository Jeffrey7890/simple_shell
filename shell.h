#ifndef _SHELL_H
#define _SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "error.h"

void free_argv(char **);

int _cmdparse(char *cmd);

void _forkexecute(char **argv, char *file);

char **tokenize(char *cmdline, char delim);

int count_delim(const char *str, const char del);

#endif
