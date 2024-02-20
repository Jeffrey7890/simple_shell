#ifndef __SHELL_MAIN__
#define __SHELL_MAIN__

#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * struct command - datatstructure to hold command and arguments
 * @cmdline: command line
 * @arg: argument to command
 * @next: next command if piped
 */
typedef struct command
{
	char *cmdline;
	char *arg;
	struct command *next;
} command_t;

command_t *add_command(command_t **head, char *cmd, char *arg);
void free_command_list(command_t *head);
void print_command(command_t *head);

void free_command(char *line);
int getcommand(void);
void prompt(void);
int handle_read(ssize_t *n);


#endif
