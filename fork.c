#include "shell.h"
#include "error.h"

extern char **environ;
void _forkexecute(char **argv, char **envp)
{
	pid_t child;

 /*	char *env_args[] = {"PATH=/bin", (char *)0}; */

	int status;

	if ((child = fork()) < 0)
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

