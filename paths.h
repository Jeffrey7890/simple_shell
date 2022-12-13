#ifndef _PATH_H
#define _PATH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>




extern char **environ;

typedef struct paths
{
	char *path;
	struct paths *next;
}path_t;



char *spath(const path_t *head, char *cmd);
char *pathsear(path_t *head, char *cmd);

char *get_path(char **env);

int pup_paths(path_t **head, char *path);

void print_paths_list(const path_t *head);

struct paths *insert(path_t **head, char *p);

void free_list(path_t *head);


#endif
