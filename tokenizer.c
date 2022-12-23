#include "shell.h"
/* #include "paths.h" */

/**
  * _cmdparse - parse command by add \0
  * @cmd: command
  * Return: int
  */
int _cmdparse(char *cmd)
{
	cmd[strlen(cmd) - 1] = '\0';
	return (0);
}

/**
  * tokenize - it separets th cmdlin with delim
  * @cmdline: command line arg
  * @delim: delimiter to seperate with
  * Return: char
  */
char **tokenize(char *cmdline, char delim)
{
	int count, i = 0;

	char *token, **argv;

	/* printf("%s\n", cmdline); */
	count = count_delim(cmdline, delim);
	/* printf("count malloc [%ld]\n", count * sizeof(argv)); */
	argv = malloc((count + 1) * sizeof(argv));

	if (argv == NULL)
	{
		free(argv);
		exit(97);
	}

	token = strtok(cmdline, &delim);

	while (token != NULL)
	{
		/*printf("token [%s]\n", token);*/
		argv[i] = strdup(token);
		/*printf("argv[i] [%s]\n", argv[i]);*/
		token = strtok(NULL, &delim);
		i++;
	}
	/*printf("argv[0] %s\n", argv[0]);*/

	argv[i] = NULL;

	/* free(cmdline); */
	return (argv);
}

/**
  * free_argv - frees the **argv
  * @argv: array of char pointers
  */
void free_argv(char **argv)
{
	int i;

	if (argv != NULL)
	{
		/*/printf("\n------------memfree--------------\n");*/
		for (i = 0; argv[i] != NULL; i++)
		{

			/* printf("before free[%s] i[%d]\n", argv[i], i); */
			free(argv[i]);
			/* argv[i] = NULL; */
			/*printf("after free[%s]\n", argv[i]);*/
		}

		free(argv);
	}
}

/**
  * count_delim - it counts all the dlimiter in cmd
  * @str: string wth separted delim
  * @del: char
  * Return: int
  */
int count_delim(const char *str, const char del)
{
	const char *ptr = str;

	int cnt = 1;

	while (*ptr != '\0')
	{
		if (del == *ptr)
			cnt++;
		ptr++;
	}
	return (cnt);
}

