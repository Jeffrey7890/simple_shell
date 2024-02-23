#include <stdio.h>
#include "main.h"


/**
 * main - beautiful code that passes betty checks
 * Return: 0 always
 */
int main()
{
	command_t *head = NULL;
	char **argVec = NULL;
	unsigned int len = 3;
	


	if (isatty(STDIN_FILENO))
	{
		do {
			prompt();
			argVec = construct_arg_vec(head, 3);
			print_command(head);
			free_command_list(head);
			head = NULL;
			free_argV(argVec, len);
		} while (getcommand(&head) == 1);
	}
	else
	{
		prompt();
		if (getcommand(&head) == 1)
		{
			argVec = construct_arg_vec(head, 3);
			print_command(head);
			free_command_list(head);
			head = NULL;
			free_argV(argVec, len);
		}
	}
	/* print_command(head); */


	return (0);
}
