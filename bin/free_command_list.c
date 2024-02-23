#include "main.h"


void free_command_list(command_t *head)
{
	command_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->cmdline);
		free(head->arg);
		free(head);
		head = tmp;
	}
	head = NULL;
}

void free_argV(char **argVec, unsigned int n)
{
	unsigned int i;
	if (argVec != NULL)
	{
		for (i = 0; i < n; i++)
		{
			free(argVec[i]);
			argVec[i] = NULL;
		}
		free(argVec);
		argVec = NULL;
	}
}
