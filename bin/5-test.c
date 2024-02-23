#include "../main.h"
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 100
cmdVec_t *construct_cmdVec(char *line)
{
	char *token;
	int cnt = 1, i = 0;
	cmdVec_t *command ;

	if (line == NULL || *line == '\n')
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
	free(line);
	line = NULL;
	return (command);
}


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

void print_cmdVec(cmdVec_t *command)
{
	int i = 0;
	if (command != NULL)
		for (i = 0; i < command->cnt; i++)
			printf("argV[%d] %s\n",i, command->argV[i]);
}


int main(void)
{
	cmdVec_t *command;
	char *line = NULL;
	size_t n = 0;

	
	prompt();
	getline(&line, &n, stdin);

	command = construct_cmdVec(line);
	printf("segging men\n");
	print_cmdVec(command);

	free_cmdVec(command);
	return(0);
}
