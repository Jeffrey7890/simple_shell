#include "paths.h"

#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


/* #define VALGRIND_DEBUG */

extern char **environ;

char *spath(const path_t *head, char *cmd)
{
	char *ptr;

	struct stat st;

	const path_t *trv = head;

	/* printf("cmd [%s]", cmd);*/
	if (strchr(cmd, '/'))
	{
		/* printf("cmmand line: %s\n", cmd); */
		if (stat(cmd, &st) == 0)
		{
			/* printf("found paths [%s]\n", cmd); */
			return (cmd);
		}
		return (NULL);
	}

	while (trv != NULL && cmd != NULL)
	{
		/* todo: malloc funct */
		ptr = strdup(trv->path);
		strcat(ptr, "/");
		strcat(ptr, cmd);
		
		if (stat(ptr, &st) == 0)
		{
			return (ptr);
		}

		free(ptr);
		trv = trv->next;
	}

	/* printf("Return null nae [%s]\n", ptr); */

	return (NULL);
}
int pup_paths(path_t **head /*, char *path */)
{
	char *token = NULL, *ptr;
	
	#ifndef VALGRIND_DEBUG
	ptr = strdup(get_path(environ));
	#endif

	#ifdef VALGRIND_DEBUG 
	char *evg[] = {"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", (char *)0};
	ptr = strdup(get_path(evg));
	#endif
	
	if (/*path*/ptr == NULL || strlen(ptr) < 1)
	{
		perror("Invalid path");
		return (-1);
	}


	token = strtok(/*path*/ ptr, "=");

	/* creat an error func to check for env value */
	if (strcmp(token, "PATH") != 0)
	{
		free(ptr);
		ptr = NULL;
		perror("Invalid input, key!=PATH");
		return (-1);
	}

	while (token != NULL && head != NULL)
	{
		insert(head, token);
		token = strtok(NULL, ":");
	}
	/* strcpy(path, ptr);*/
	/*printf("path : [%s]\n", path);*/
	
	free(ptr);
	/*printf("ptr : [%s]\n", ptr);*/
	ptr = NULL;
	return (1);

}

char *get_path(char **env)
{

	int i = 0;

	/*printf("debuf :(\n");*/
	if (env == NULL)
	{
		perror("get_path arg is not env");

		return (NULL);
	}
		
	while(env[i] != NULL)
	{
		if (strstr(env[i], "PATH"))
		{
			/*printf("%s\n", env[i]);*/
			return(env[i]);
		}
		i++;
	}

	return (NULL);
}

void free_list(path_t *head)
{
	path_t *trv = head;

	while (trv != NULL)
	{
		trv = head->next;
		free(head->path);
		free(head);
		head = trv;
	}
}


void print_paths_list(const path_t *head)
{
	const path_t *trv = head;

	while (trv != NULL)
	{
		printf("%s\n", trv->path);
		trv = trv->next;
	}

}

struct paths *insert(path_t **head, char *str)
{
	path_t *cur = *head, *new_node;
	new_node =  malloc(sizeof(path_t));

	if (new_node == NULL || str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->path = strdup(str);

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (cur->next != NULL)
		cur = cur->next;

	cur->next = new_node;

	return (new_node);
}
