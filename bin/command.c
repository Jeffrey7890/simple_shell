#include "main.h"
#include <string.h>


char **construct_arg_vec(command_t *head, unsigned int n)
{
	/* static char *argV[3]; */
	
	char **argV;	

	if (head != NULL)
	{
		argV = malloc(sizeof(void *) * n);

		if (argV == NULL)
			return (NULL);
		argV[0] = NULL;
		argV[1] = NULL;
		argV[2] = NULL;

		if (head->cmdline != NULL)
		{
			argV[0] = strdup(head->cmdline);
		}
		if (head->arg != NULL)
		{
			argV[1] = strdup(head->arg);
		}
		argV[2] = NULL;
		return (argV);
	}
	return (NULL);

}

void print_argV(char *argVec[], unsigned int len)
{
	unsigned int i;

	if (argVec != NULL)
	{
		for (i = 0; i < len; i ++)
			if (argVec[i] != NULL)
				printf("%s ", argVec[i]);
	}
}


command_t *add_command(command_t **head, const char *cmd, const char *arg)
{
	command_t *new_command;

	new_command = malloc(sizeof(command_t));

	if (new_command == NULL)
		return (NULL);

	new_command->cmdline = NULL;
	new_command->arg = NULL;
	if (cmd != NULL)
		new_command->cmdline = strdup(cmd);
	if (arg != NULL)
		new_command->arg = strdup(arg);
	new_command->next = *head;
	*head = new_command;

	return (new_command);
}

void print_command(command_t *head)
{
	command_t *trav = head;

	while (trav != NULL)
	{
		printf("cmd: %s arg: %s", trav->cmdline, trav->arg);
		trav = trav->next;
	}
}


