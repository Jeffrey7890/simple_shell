#include "shell.h"
#include "error.h"


/**
  * _forkexecute - executes the command
  * @argv: array of char pointers of command
  * @envp: environment array of ponters
  */
void _forkexecute(char **argv, char **envp)
{
	pid_t child;

 /*	char *env_args[] = {"PATH=/bin", (char *)0}; */

	int status;

	child = fork();
	if (child < 0)
	{
		printshe("Error");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{

		execve(argv[0], argv, envp);
		exit(EXIT_FAILURE);
	}

	if (wait(&status) != child)
		printshe("Error");
}

