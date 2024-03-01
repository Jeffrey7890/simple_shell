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

	
	/*
	if (search_command_in_path(command, environ) == -1)
	{
		fprintf(stderr, "%s: No such file or directory\n", file);
		return (-1);
	}
	*/
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

/**
 * update_cmdVec - concats the command to path
 * @command: cmdVec struct
 * @path: path found for the command
 */
void update_cmdVec(cmdVec_t *command, char *path)
{
	char *newStr;
	int newlen;

	newlen = strlen(path) + strlen(command->argV[0]) + 1;

	newStr = malloc(newlen);

	_mstrcat(newStr, path, command->argV[0]);
	command->argV[0] = newStr;

}

/**
 * search_command_in_path - searches the command in path env
 * @command: cmdVec_t struct
 * @argP: environment pointer
 * Return: 0 on success, -1 on fail
 */
int search_command_in_path(cmdVec_t *command, char **argP)
{
	char *PATH, *pDir, *file;

	file = strdup(command->argV[0]);
	PATH = get_path(argP);
	pDir = search_path(PATH, file);
	if (pDir != NULL)
	{

		if (strchr(command->argV[0], '/') == NULL)
			update_cmdVec(command, pDir);
	}
	else
	{
		free_line(&file);
		free_line(&PATH);
		return (-1);
	}

	free_line(&file);
	free_line(&PATH);
	PATH = NULL;
	file = NULL;
	return (0);
}


/**
 * _mstrcat - concats two strings to new string
 * @newStr: a mallocated string
 * @dest: destination
 * @src: source
 */
void _mstrcat(char *newStr, char *dest, char *src)
{
	unsigned int i = 0, j = 0;

	while (i < strlen(dest))
	{
		newStr[i] = dest[i];
		i++;
	}
	newStr[i] = '/';
	i++;
	while (j < strlen(src))
	{
		newStr[i] = src[j];
		i++;
		j++;
	}
}
