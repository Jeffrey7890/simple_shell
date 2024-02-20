#include "main.h"


void free_command_list(command_t *head)
{
	command_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->cmdline);
		free(head);
		head = tmp;
	}
}

