#include "shell.h"
#include "error.h"


void _forkexecute(char **argv, char *file)
{
	pid_t child;

	int status;

	if ((child = fork()) < 0)
	{
		printshe("Error");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execve(argv[0], argv, NULL);


		printshe(file);
		exit(EXIT_FAILURE);
	}

	if (wait(&status) != child)
		printshe("Error");
}	

