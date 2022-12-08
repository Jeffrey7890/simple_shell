
#include "error.h"

int printshe(char *src)
{
	perror(src);
	/*
	char *tmp = malloc(strlen(src));

	if (tmp == NULL)
		return (-1);

	strcpy(tmp, src);
	strcat(tmp, " 1");
	perror(tmp);
	free(tmp);*/
	return (0);
}
