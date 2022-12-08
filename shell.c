#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "error.h"


/**
  * main - prints prompt
  * Return: zero always
  */
int main(int ac, char **argc)
{
	char *line = NULL, *argv[2];

	size_t len = 0;

	if (ac < 1)
		return (1);


	argv[1] = NULL;

	while (printf("#cisfun$ "))
	{
		if (getline(&line, &len, stdin) == -1)
		{
			putchar('\n');
			exit(0);
		}
		_cmdparse(line);

		_forkexecute(argv, line, argc[0]);
		printf("%s", line);
	}


	return (0);
}
