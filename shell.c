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
	signal(SIGINT, SIG_IGN);
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
int  mini_shell(char **argv, char **env)
{
	char *lineptr;
	size_t n = 32;

	lineptr = malloc(sizeof(char) * n);
	if (lineptr == NULL)
	{
		free(lineptr);
		perror("Failed");
		return (0);
	}
	show_prompt(&lineptr, &n);
	if ((int)n == -1)
	{
		free(lineptr);
		return (0);
	}
	exec_cmd(lineptr, n, argv, env);
	free(lineptr);
	return (0);

}
