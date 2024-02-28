#include "main.h"

/**
 * free_line - helper function to free line
 * @line: line to free
 */
void free_line(char **line)
{
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
}

