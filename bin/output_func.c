
#include "main.h"
#include <string.h>


/**
 * getcommand - gets line from command line
 * Return: 1 if success -1 if fail
 */
int getcommand(command_t **head)
{
	char *lineptr = NULL, *token;
	size_t n = 0;
	ssize_t nread;

	nread = getline(&lineptr, &n, stdin);

	if (nread != EOF && *lineptr != '\n')
	{
		token = strtok(lineptr, " ");
		token = strtok(NULL, " ");
		add_command(head, lineptr, token);

	}
	free(lineptr);
	lineptr = NULL;
	n = 0;

	return (handle_read(&nread));
}

/**
 * prompt - prompts the user with ($)
 */
int prompt(void)
{
	const char *PROMPT = "($) ";
	write(STDOUT_FILENO, PROMPT, 4);
	return (1);
}

