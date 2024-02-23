#include "../main.h"
#include <string.h>


int main(void)
{

	command_t *head = NULL;

	char *cmd = NULL, *token;
	size_t n;

	//cmd = strdup("/bin/ls -la");
	
	getline(&cmd, &n, stdin);

	token = strtok(cmd, " "); 
	token = strtok(NULL, " ");
	add_command(&head, cmd, token);
	free(cmd);
	cmd = NULL;
	token = NULL;
	getline(&cmd, &n, stdin);
	token = strtok(cmd, " "); 
	token = strtok(NULL, " ");
	add_command(&head, cmd, token);
	free(cmd);
	cmd = NULL;
	print_command(head);
	free_command_list(head);

	return (0);
}
