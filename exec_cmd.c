#include "simple_shell.c"

/**
*exec_cmd - function that executes command
*entered by the user from terminal
*@str: command from the user
*@argv: arguments to the main function
*@env: environment from main function
*Return: void
*/

void exec_cmd(char *str, char **argv, char **env)
{
	char *str1;
	size_t n;
	char **exec_args;

	n = strlen(str);
	str1 = malloc(sizeof(char) * n - 1);
	exec_args = malloc(2 * sizeof(char *));
	if (str1 == NULL || exec_args == NULL)
	{
		exit(0);
	}

	memcpy(str1, str, n - 1);
	exec_args[0] = str1;

	if (execve(argv[0], exec_args, env) == -1)
	{
		perror(argv[0]);
		exit(0);
	}
}
