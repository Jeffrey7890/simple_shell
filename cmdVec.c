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
	const char *PROMPT = "($) ";

	write(STDOUT_FILENO, PROMPT, 4);
	return (1);
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

	token = strtok(line, " ");
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

