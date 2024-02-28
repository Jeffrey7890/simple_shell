#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern char **environ;

char *get_path(char **env)
{
	char *PATH = NULL, **trav = env;

	PATH = strstr(*trav, "PATH=");
	while (*(++trav) != NULL)
	{
		if (PATH != NULL)
			break;
		PATH = strstr(*trav, "PATH=");
	}
	PATH = strdup(PATH);
	return (PATH);
}

int main(void)
{
	char *PATH = NULL;

	/**
	while (*(++trav) != NULL)
	{
		PATH = strstr(*trav, "PATH=");
		if (PATH != NULL)
			break;
	}

	PATH = strdup(PATH);
	*/

	PATH = get_path(environ);
	printf("%s\n", PATH);

	free(PATH);
	PATH = NULL;

	return (0);
}


