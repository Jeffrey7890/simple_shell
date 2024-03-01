#include <stdio.h>
#include "main.h"


/**
 * print_env - prints the environ vect
 * @envp: environ pointer
 */
void print_env(char **envp)
{
	char **trav = envp;

	printf("%s\n", *trav);

	while (*(++trav) != NULL)
		printf("%s\n", *trav);
}

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
		} while (input_data(argv[argc - 1], envP, &exec, 0) == 1);
	}
	else
	{
		while(input_data(argv[argc - 1], envP, &exec, 1) == 1);
	}
	return (0);
}
