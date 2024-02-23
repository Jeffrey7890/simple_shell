#include <stdio.h>
#include "main.h"


/**
 * input_data - collects input from user
 * Return: 1 on success of -1 on fail
 */
int input_data(void)
{
	cmdVec_t *command;
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;

	nread = getline(&line, &n, stdin);
	if (nread != EOF && *line != '\n')
	{
		command = construct_cmdVec(line);
		print_cmdVec(command);
		free_cmdVec(command);
	}
	free(line);
	line = NULL;
	n = 0;

	return (handle_read(&nread));
}

/**
 * main - beautiful code that passes betty checks
 * Return: 0 always
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		do {
			prompt();
		} while (input_data() == 1);
	}
	else
	{
		prompt();
		input_data();
	}
	return (0);
}
