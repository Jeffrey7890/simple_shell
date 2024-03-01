#include "main.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


/**
 * get_path - gets the env PATH
 * @env: environment pointer
 * Return: pointer to PATH
 */
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


/**
 * search_dir - search each directory in path for file
 * @dir: directory to search
 * @file: file to search for
 * Return: 0 on success or -1 on fail
 */
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
			closedir(dirFd);
			return (0);
		}
		dirPtr = readdir(dirFd);
	}
	closedir(dirFd);
	return (-1);
}


/**
 * search_path - search each in the env PATH
 * @path: environment path
 * @file: file to search for
 * Return: pointer to found path
 */
char *search_path(char *path, char *file)
{
	char *token;
	static char *dir;


	if (file[0] == '.')
	{
		token = strtok(file, "/");
		if (search_dir(token, file) == 0)
			return (file);
		else
			return (NULL);
	}
	token = strtok(file, "/");
	while (token != NULL)
	{
		file = token;
		token = strtok(NULL, "/");
	}
	token = strtok(path, "=");
	token = strtok(NULL, ":");
	while (token != NULL)
	{
		if (search_dir(token, file) == 0)
		{
			dir = token;
			return (dir);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}



