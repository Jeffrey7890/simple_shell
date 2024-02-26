#include "main.h"


/**
 * handle_read - handles read error from getline
 * @n: return value from getline
 * Return: 1 on safe and -1 on EOF
 */
int handle_read(ssize_t *n)
{
	switch (*n)
	{
		case EOF:
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
 * @n: return value
 * @file: name of this executable
 * Return: 0 on success and -1 on fail
 */
int handle_exec(int n, char *file)
{
	switch (n)
	{
		case EACCES:
			fprintf(stderr, "%s: No such file or directory\n", file);
			return (-1);
		default:
			return (1);
	}
}
