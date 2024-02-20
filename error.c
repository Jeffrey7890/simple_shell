#include "main.h"


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
