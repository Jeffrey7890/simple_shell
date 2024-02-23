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



command_t *add_command(command_t **head, const char *cmd, const char *arg);
command_t *construct_list(command_t **head, char *line);
void free_command_list(command_t *head);
void print_command(command_t *head);



command_t *add_command(command_t **head, const char *cmd, const char *arg);
command_t *construct_list(command_t **head, char *line);
void free_command_list(command_t *head);
void print_command(command_t *head);

char **construct_arg_vec(command_t *head, unsigned int n);
void print_argV(char *argVec[], unsigned int len);
void free_argV(char **argVec, unsigned int n);
void free_command(char *line);
int getcommand(command_t **head);
int prompt(void);
int handle_read(ssize_t *n);


#endif
