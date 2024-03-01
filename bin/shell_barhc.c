#include <stdio.h>
#include "main.h"




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
