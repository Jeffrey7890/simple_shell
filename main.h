#ifndef __SHELL_MAIN__
#define __SHELL_MAIN__

#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

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
int input_data(char *file, char **environ, int *exec, int flag, int nCmd);
void print_env(char **envp);
void sigHandler(int sig);
void free_cmdVec(cmdVec_t *command);
void print_cmdVec(cmdVec_t *command);
int prompt(void);
int handle_read(ssize_t *nread);
int _strcmp(char *s1, char *s2);
void free_line(char **line);

int execute_cmd(cmdVec_t *command, char *line, char *file, char **environ, int nCmd);
void update_cmdVec(cmdVec_t *command, char *path);
int search_command_in_path(cmdVec_t *command, char **argP);
char *search_path(char *path, char *file);
int search_dir(char *dir, char *file);
char *get_path(char **env);
void _mstrcat(char *newStr, char *dest, char *src);
int handle_exec(char *file, char *cmd, int nCmd);

#endif
