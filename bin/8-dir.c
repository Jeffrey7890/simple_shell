#include <stdio.h>
#include "../main.h"
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

/**
 * _mstrcat - concats two strings to new string
 * @newStr: a mallocated string
 * @dest: destination
 * @src: source
 */
void _mstrcat(char *newStr, char *dest, char *src)
{
	int new_len, i = 0, j = 0;

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


int main(int argc, char *argV[], char *argP[])
{
	char *PATH, *pDir, *file;
	cmdVec_t *command;

	if (argc < 2)
	{
		fprintf(stderr, "%s [file]\n", argV[0]);
		return (-1);
	}

	command = construct_cmdVec(argV[1]);
	printf("Command argV[0] %s\n", command->argV[0]);
	if (search_command_in_path(command, argP) == 0)
		print_cmdVec(command);
	putchar('\n');
	free_cmdVec(command);
	
	return (0);
}
