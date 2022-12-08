#ifndef _SHELL_H
#define _SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int _cmdparse(char *cmd);

void _forkexecute(char **argv, char *command, char *file);

#endif
