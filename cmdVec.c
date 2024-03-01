#include "main.h"
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 100

/**
 * prompt - prompts the user with ($)
 * Return: always return 1 ;)
 */
int prompt(void)
{
	const char *PROMPT = "#cisfun$ ";

	write(STDOUT_FILENO, PROMPT, 9);
	return (1);
}

/**
 * input_data - collects input from user
 * @file: name of executed file
 * @env: environment pointer
 * @exec_stat: status of last execution
 * Return: 1 on success of -1 on fail
 */
int input_data(char *file, char **env, int *exec_stat, int flag)
{
	cmdVec_t *command;
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;

	if (signal(SIGINT, sigHandler) == SIG_ERR)
		exit(-1);
	nread = getline(&line, &n, stdin);

	if (nread != -1 && *line != '\n')
	{
		command = construct_cmdVec(line);
		*exec_stat = execute_cmd(command, line, file, env);
		/* print_cmdVec(command); */
		free_cmdVec(command);
	}

	if (feof(stdin))
	{
		if (flag == 0)
			putchar('\n');
		free_line(&line);
		exit(*exec_stat);
	}
	free_line(&line);

	/*return (handle_read(&nread));*/
	return (handle_read(&nread));
}



/**
 * construct_cmdVec - constructs the char pointer array for exev
 * @line: line to parse
 * Return: cmdVec_t pointer
 */
cmdVec_t *construct_cmdVec(char *line)
{
	char *token;
	int cnt = 1, i = 0;
	cmdVec_t *command;

	if (line == NULL)
		return (NULL);

	command = malloc(sizeof(cmdVec_t));
	if (command == NULL)
		return (NULL);

	command->argV = malloc(sizeof(void *) * MAX_ARGS);
	if (command->argV == NULL)
		return (NULL);

	token = strtok(line, "\n");

	/* uncomment for taking multiple arguments */
	token = strtok(token, " ");
	while (token != NULL)
	{
		command->argV[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
		cnt++;
	}
	command->argV[i] = NULL;
	command->cnt = cnt;
	return (command);
}


/**
 * free_cmdVec - free allocated memory for command
 * @command: cmdVec_t struct for command
 */
void free_cmdVec(cmdVec_t *command)
{
	int i = 0;

	if (command == NULL)
		return;

	while (i < command->cnt)
	{
		free(command->argV[i]);
		command->argV[i] = NULL;
		i++;
	}
	free(command->argV);
	command->argV = NULL;
	free(command);
	command = NULL;
}


/**
 * print_cmdVec - for debuggin purposes to print cmdVect_t structs
 * @command: command to print
 */
void print_cmdVec(cmdVec_t *command)
{
	int i = 0;

	if (command != NULL)
		for (i = 0; i < command->cnt; i++)
			printf("argV[%d] %s | ", i, command->argV[i]);
}
