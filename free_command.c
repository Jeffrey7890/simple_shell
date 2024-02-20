#include "main.h"
#include <stdlib.h>

/**
 * free_command - frees the line pointer
 * @line: line pointer allocated mem
 */
void free_command(char *line)
{
	if (line != NULL)
		free(line);
	line = NULL;
}
