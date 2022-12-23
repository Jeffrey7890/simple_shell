#include "shell.h"
#include "paths.h"

/**
  * _onexit - frees the args on exit
  * @argv: array of char pointers
  * @line: getline input
  * @head: head of list
  */
void _onexit(char **argv, char *line, path_t *head)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		free_list(head);
		free_argv(argv);
		free(line);
		line = NULL;
		exit(0);
	}
}

/**
  * free_argv_line - frees the dynamical argv
  * @argv: array of char  pointers
  * @line: getline input
  */
void free_argv_line(char **argv, char **line)
{
	free_argv(argv);

	free(*line);
	/* line = NULL; */
}

/**
  * _nullgetline - check error for getline
  * @line: getline arg
  * @len: getline arg
  * @head: linked list of pathas
  */
void _nullgetline(char **line, size_t *len, path_t *head)
{
	/* printf("terminations dsixc\n"); */
	if (line == NULL)
	{
		printf("NULL command\n");
		exit(1);
	}

	if (getline(line, len, stdin) == -1)
	{
		putchar('\n');
		free_list(head);
		free(*line);
		line = NULL;
		exit(0);
	}

	(*line)[strlen(*line) - 1] = '\0';
	/* printf("line [%s]\n",*line); */
}
