
#include "main.h"
#include <string.h>


/**
 * getcommand - gets line from command line
 * Return: 1 if success -1 if fail
 */
int getcommand(void)
{
	char *lineptr, *token;
	size_t n = 0;
	ssize_t nread;
	command_t *head = NULL;

	nread = getline(&lineptr, &n, stdin);


	token = strtok(lineptr, " "); 
	token = strtok(NULL, " ");
	add_command(&head, lineptr, token);
	if ((handle_read(&nread) == -1))
	{
		free_command_list(head);

		printf("%s \n", token);
		return (-1);
	}
	print_command(head);
	
	return (1);
}

/**
 * prompt - prompts the user with ($)
 */
void prompt(void)
{
	const char *PROMPT = "($) ";

	write(STDOUT_FILENO, PROMPT, 4);
}
