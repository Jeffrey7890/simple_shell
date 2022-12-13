#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "paths.h"

extern char **environ;

int main(int ac, char **argc)
{
	char *path, *line = NULL, **argv = NULL, *chek;

	size_t len = 0;

	path_t *head = NULL;

	path = get_path(environ);

	if (ac < 0)
	{
		perror("Ivalid ");
		exit(EXIT_FAILURE);
	}

	/* printf("Path: [%s]\n", path); */

	if (path)
		pup_paths(&head, path);

	/* print_paths_list(head); */

	while (printf("#cisfun$ "))
	{
		if (getline(&line, &len, stdin) == -1)
		{
			putchar('\n');
			free(line);
			line = NULL;
			exit(0);
		}
		line[strlen(line) - 1] = '\0';
		/* printf("command [%s]\n", line); */
		argv = tokenize(line, ' ');

		/*printf("argv [%s]\n", argv[0]);*/
		chek = spath(head, argv[0]);
		if (chek)
		{
			strcpy(argv[0], chek);
			_forkexecute(argv, argc[0]);
		}
		else
			printf("%s: No such file or direcotry\n", argc[0]);
			

		free_argv(argv);
		free(line);
		line = NULL;
	}

	free_list(head);

	return (0);
}
