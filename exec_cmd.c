#include "simple_shell.h"
/**
*exec_cmd - function that executes command passed to the simple shell
*entered by the user from terminal
*@str: command from the user
*@argv: arguments to the main function
*@env: environment from main function
*@n: number of characters read
*Return: void
*/
int  exec_cmd(char *str, size_t n, char **argv, char **env)
{
	char **exec_args, *basepath, *str1, *str2;
	pid_t new_pid;
	int  i = 1;

	str1 = malloc(sizeof(char) * n - 1);
	exec_args = malloc(1 * sizeof(char *));
	if (str1 == NULL || exec_args == NULL)
	{
		free(str1), free(exec_args), perror(argv[0]);
		return (0);
	}
	_memcpy(str1, str, _strlen(str) - 1);
	str2 = _strtok(str1, " ");
	if (str2 == NULL)
		return (0);
	if (check_path(&basepath, str2) == 0)
		exec_args[0] = basepath;
	else
	{
		free(basepath), free(str1), free(exec_args), perror(argv[0]);
		return (0);
	}
	while ((str2 = _strtok(NULL, " ")) != NULL)
		exec_args[i++] = str2;
	new_pid = fork();
	if (new_pid == 0)
	{
		if (execve(exec_args[0], exec_args, env) == -1)
			perror(argv[0]);
	}
	else
		wait(NULL);
	free(exec_args);
	while (i >= 1)
		free(exec_args[--i]);
	free(str1), free(basepath);
	return (0);
}
