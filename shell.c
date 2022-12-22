#include <stdio.h>
#include <stdlib.h>

#include <signal.h>

#include "shell.h"
#include "paths.h"



/**
  * main - c simple shell
  * @ac: nnumber of dmd line arg
  * @argc: array of cmd line arg
  * @envp: array of environment var
  * Return: alot of things
  */
int main(int ac, char **argc, char **envp)
{
	char *line = NULL, **argv = NULL, *chek;

	size_t len = 0;

	path_t *head = NULL;

	if (ac < 0)
	{
		perror("Ivalid ");
		exit(EXIT_FAILURE);
	}
	pup_paths(&head);
	while (printf("# "))
	{
		_nullgetline(&line, &len, head);
		argv = tokenize(line, ' ');
		_onexit(argv, line, head);
		chek = spath(head, argv[0]);
		if (chek)
		{
			strcpy(argv[0], chek);
			_forkexecute(argv, envp);
		}
		else
			printf("%s: No such file or direcotry\n", argc[0]);
		free_argv(argv);
		free(line);
		line = NULL;
	}
	return (0);
}
