#include "simple_shell.c"

/**
*main - Entry point into our shell program
*@argc: argument count
*@argv: argument to the main function
*@env:  array of environmental variables
*Return: Always success (0);
*/

int main(int argc, char **argv, **env)
{
	char *lineptr;
	size_t n;

	while (1)
	{
		show_prompt(&lineptr, &n);
		if (n == -1)
			continue;
		exec_cmd(lineptr, argv, env);
	}
	return (0);
}
