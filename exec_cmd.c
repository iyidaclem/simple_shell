#include "simple_shell.h"

/**
*exec_cmd - function that executes command
*entered by the user from terminal
*@str: command from the user
*@argv: arguments to the main function
*@env: environment from main function
*Return: void
*/

int  exec_cmd(char *str, char **argv, char **env)
{
	char *str1;
	size_t n;
	char **exec_args;
	pid_t new_pid, w;
	
	n = strlen(str);
	str1 = malloc(sizeof(char) * n - 1);
	exec_args = malloc(2 * sizeof(char *));
	if (str1 == NULL || exec_args == NULL)
	{
		return (0);
	}

	memcpy(str1, str, n - 1);
	exec_args[0] = str1;

	new_pid = fork();

	if(new_pid == 0)
	{
		if (execve(exec_args[0], exec_args, env) == -1)
		{
			perror(argv[0]);
			return (0);
		}
	}
	else
	{
		wait(&w);
		free(exec_args[0]);
		free(exec_args);
	}
	return (0);
}
