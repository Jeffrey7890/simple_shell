#include "main.h"


command_t *add_command(command_t **head, char *cmd, char *arg)
{
	command_t *new_command;

	new_command = malloc(sizeof(command_t));

	if (new_command == NULL)
		return (NULL);

	new_command->cmdline = cmd;
	new_command->arg = arg;
	new_command->next = *head;
	*head = new_command;

	return (new_command);
}

void print_command(command_t *head)
{
	command_t *trav = head;

	while (trav != NULL)
	{
		printf("cmd: [%s] arg: [%s]\n", trav->cmdline, trav->arg);
		trav = trav->next;
	}
}
