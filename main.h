#ifndef __SHELL_MAIN__
#define __SHELL_MAIN__

#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

/**
 * struct cmdVec - data struct for command line
 * @argV: argument vect for execv
 * @cnt: number of args
 */
typedef struct cmdVec
{
	char **argV;
	int cnt;
} cmdVec_t;


cmdVec_t *construct_cmdVec(char *line);
int input_data(char *file, char **environ);
void sigHandler(int sig);
void free_cmdVec(cmdVec_t *command);
void print_cmdVec(cmdVec_t *command);
int prompt(void);
int handle_read(ssize_t *n);

int execute_cmd(cmdVec_t *command, char *line, char *file, char **environ);
int handle_exec(int n, char *file);

#endif
