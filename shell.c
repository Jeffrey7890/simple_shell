#include <stdio.h>
#include "main.h"


/**
 * main - beautiful code that passes betty checks
 * @argc: argument count
 * @argv: argument vector
 * @envP: environment vector
 * Return: 0 always
 */
int main(int argc, char *argv[], char **envP)
{

	if (isatty(STDIN_FILENO))
	{
		do {
			prompt();
		} while (input_data(argv[argc - 1], envP) == 1);
	}
	else
	{
		input_data(argv[argc - 1], envP);
	}
	return (0);
}
