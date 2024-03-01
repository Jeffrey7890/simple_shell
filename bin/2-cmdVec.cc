#include "main.h"
#include <sys/wait.h>


extern char **environ;

int execute_cmd(command_t *command, char *line)
{

	pid_t n = 0;
	int status = 0, nExec = 0;


	if ((n = fork()) == 0)
	{
		nExec = execve((const char*) command->argV[0], command->argV, environ);
		if (nExec == -1)
		{
			free(line);
			line = NULL;
			free_cmdVec(command);
			exit(-1);
		}
	}

	if (wait(&status) == -1)
	{
		/* print error to stderr */
		return (-1);
	}
	return (0);
}
