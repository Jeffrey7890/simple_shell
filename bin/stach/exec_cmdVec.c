#include "main.h"
#include <sys/wait.h>


/* extern char **environ; */

/**
 * execute_cmd - function to execute command line
 * @command: cmdVec_t pointer
 * @line: line from getline func
 * @file: this file name
 * @environ: environment list
 * Return: 0 on success and -1 on fail
 */
int execute_cmd(cmdVec_t *command, char *line, char *file, char **environ)
{

	pid_t n = 0;
	int status = 0, nExec = 0;

	n = fork();
	if (n == 0)
	{
		nExec = execve((const char *) command->argV[0], command->argV, environ);
		if (nExec == -1)
		{
			handle_exec(file);
			free(line);
			line = NULL;
			free_cmdVec(command);
			exit(127);
		}
	}

	if (wait(&status) == -1)
	{
		/* print error to stderr */
		return (127);
	}
	return (WEXITSTATUS(status));
}
