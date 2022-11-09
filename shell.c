#include "simple_shell.h"

/**
*main - Entry point into our shell program
*@argc: argument count
*@argv: argument to the main function
*@env:  array of environmental variables
*Return: Always success (0);
*/


int main(int argc, char **argv, char **env)
{
	while (argc > 0)
	{
		mini_shell(argv, env);
	}
	return (0);
}


/**
*mini_shell - helper function for main
*@argv: argument to the main function
*@env:  array of environmental variables
*Return: void
*/
void mini_shell(char **argv, char **env)
{
	char *lineptr;
	size_t n = 32;

	show_prompt(&lineptr, &n);
	if (n < 1)
		exit(0);
	exec_cmd(lineptr, argv, env);
}
