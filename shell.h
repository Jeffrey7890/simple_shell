#ifndef _SHELL_H
#define _SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "paths.h"
#include "error.h"

void free_argv(char **);

int _cmdparse(char *cmd);

void free_argv_line(char **argv, char **line);

void _nullgetline(char **line, size_t *len, path_t *head);

void _onexit(char **argv, char *line, path_t *head);

void _forkexecute(char **argv, char **envp);

char **tokenize(char *cmdline, char delim);

int count_delim(const char *str, const char del);

#endif
