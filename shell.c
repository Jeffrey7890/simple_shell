#include <stdio.h>
#include <stdlib.h>

#include "shell.h"



/**
  * main - prints prompt
  * Return: zero always
  */
int main(int ac, char **argc)
{
	char *line = NULL, **argv = NULL;

	size_t len = 0;

	if (ac < 1)
		return (1);


	while (printf("#cisfun$ "))
	{
		if (getline(&line, &len, stdin) == -1)
		{
			putchar('\n');

			fflush(stdout);
			/* free_argv(argv); */
			exit(0);
		}
		_cmdparse(line); /* adds '\0' to end of string */

		fflush(stdout);

		argv = tokenize(line, ' ');

		/* printf("line [%p]: %s\n",(void*)line,line);*/
		/* create fork and executes command */
		_forkexecute(argv, line, argc[0]);
		
		line = NULL;
		free_argv(argv);
	}


	/* free_argv(argv); */
	return (0);
}
