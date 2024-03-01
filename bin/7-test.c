#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../main.h"
#include <stdlib.h>



int main(void)
{
	pid_t n = 0;
	int status = 0, nN = 0;
	char *line = NULL;
	size_t nread = 0;

	char *argV[] = {"/bin/ls", NULL};


	cmdVec_t *command = NULL;

	printf("Exec\n");

	prompt();
	if (getline(&line, &nread, stdin) == -1)
	{
		free(line);
		line = 0;
		nread = 0;
		exit(0);
	}

	command = construct_cmdVec(line);
	if ((n = fork()) == 0)
	{
		printf("Child process %d\n", n);
		/* nN = execve((const char*) command->argV[0], command->argV, NULL);*/
		nN = execve("/bin/ls", argV, NULL);
		if (nN == -1)
		{
			free(line);
			line = NULL;
			nread = 0;
			free_cmdVec(command);
			exit(-1);
		}

		/*print_cmdVec(command);*/

	}
	
	free(line);
	line = NULL;
	nread = 0;
	free_cmdVec(command);

	
	if (wait(&status) == -1)
		printf("error parent wait\n");

	printf("\nParent process of child %d\n", n);

	return (0);
}
