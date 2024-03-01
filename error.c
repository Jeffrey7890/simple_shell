#include "main.h"


/**
 * handle_read - handles read error from getline
 * @n: return value from getline
 * Return: 1 on safe and -1 on EOF
 */
int handle_read(ssize_t *n)
{
	if (*n > -1)
		return (1);
	switch (errno)
	{
		case ENOMEM:
			printf("\n");
			return (-1);
		default:
			return (1);
	}
}


/**
 * sigHandler - handle signals
 * @sig: signal mask
 */
void sigHandler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		exit(130);
	}
}

/**
 * handle_exec - handle error from execve
 * @file: name of this executable
 * Return: 0 on success and -1 on fail
 */
int handle_exec(char *file, char *cmd, int nCmd)
{
	switch (errno)
	{
		case ENOENT: 
			fprintf(stderr, "%s: %d: %s: not found\n", file, ++nCmd, cmd);
			return (-1);

		case EACCES:
			fprintf(stderr, "%s: file cannot be accessed\n", file);
			return (-1);
		default:
			return (1);
	}
}
