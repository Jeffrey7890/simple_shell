#ifndef __SHELL_MAIN__
#define __SHELL_MAIN__

#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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
void free_cmdVec(cmdVec_t *command);
void print_cmdVec(cmdVec_t *command);
int prompt(void);
int handle_read(ssize_t *n);


#endif
