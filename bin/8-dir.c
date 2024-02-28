#include <stdio.h>
#include "../main.h"
#include <sys/types.h>                                                                                                                         
#include <dirent.h>                                                                                                                
#include <string.h>


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

int search_dir(char *dir, char *file)
{
	DIR *dirFd = NULL;
	struct dirent *dirPtr = NULL;

	if (dir == NULL || file == NULL)
		return (-1);


	dirFd = opendir(dir);
	if (dirFd == NULL)
		return (-1);

	dirPtr = readdir(dirFd);

	while (dirPtr != NULL)
	{
		if (_strcmp(dirPtr->d_name, file) == 0)
		{
			printf("found file %s\n", dir);
			closedir(dirFd);
			return (0);
		}
		dirPtr = readdir(dirFd);
	}
	closedir(dirFd);
	return (-1);
}

int search_path(char *path, char *file)
{
	char *token;
	
	token = strtok(file, "/");
	while (token != NULL)
	{
		printf("%s\n", token);
		file = token;
		token = strtok(NULL, "/");
	}
	token = strtok(path, "=");
	token = strtok(NULL, ":");
	while (token != NULL)
	{
		if (search_dir(token, file) == 0)
			return (0);
		token = strtok(NULL, ":");
	}

	return (-1);
}


int main(int argc, char *argV[], char *argP[])
{
	char *PATH;

	if (argc < 2)
	{
		fprintf(stderr, "%s [file]\n", argV[0]);
		return (-1);
	}

	PATH = get_path(argP);
	search_path(PATH, argV[1]);
	free(PATH);
	PATH = NULL;
}
