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

	int exec = 0;

	if (isatty(STDIN_FILENO))
	{
		do {
			prompt();
		} while (input_data(argv[argc - 1], envP, &exec) == 1);
	}
	else
	{
		input_data(argv[argc - 1], envP, &exec);
	}
	return (0);
}
