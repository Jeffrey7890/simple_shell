#include <stdio.h>
#include "main.h"

/**
 * main - beautiful code that passes betty checks
 * Return: 0 always
 */
int main(int ac, char **argc)
{
	if (ac > 1)
	{
		prompt();
		printf("%s\n", argc[0]);
		return (0);
	}
	do {
		prompt();
	} while (getcommand() == 1);

	return (0);
}
