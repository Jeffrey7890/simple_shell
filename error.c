
#include "error.h"


/**
  * print_paths_list - prints the paths of liskt
  * @head: head of list
  */
void print_paths_list(const path_t *head)
{
	const path_t *trv = head;

	while (trv != NULL)
	{
		printf("%s\n", trv->path);
		trv = trv->next;
	}

}

/**
  * printshe - print error message
  * @src: string
  * Return: int
  */
int printshe(char *src)
{
	perror(src);
	return (0);
}
