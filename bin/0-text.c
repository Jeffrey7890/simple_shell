#include "main.h"
#include <string.h>


int main(void)
{

	command_t *head = NULL;

	char *cmd, *token;

	cmd = strdup("/bin/ls -la");

	token = strtok(cmd, " "); 
	token = strtok(NULL, " ");
	add_command(&head, cmd, token);


	cmd = strdup("/bin/ac -p");
	token = strtok(cmd, " "); 
	token = strtok(NULL, " ");
	add_command(&head, cmd, token);
	print_command(head);
	free_command_list(head);

	return (0);
}
