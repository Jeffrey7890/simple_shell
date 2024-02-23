#include "main.h"


/**
 * handle_read - handles read error from getline
 * @n: return value from getline
 * Return: 1 on safe and -1 on EOF
 */
int handle_read(ssize_t *n)
{
	switch (*n)
	{
		case EOF:
			return (-1);
		default:
			return (1);
	}
}
