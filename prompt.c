#include "simple_shell.h"
/**
*show_prompt - a function that displays prompt($)
* and wait for user input
*@lineptr: pointer to string for storing user input
*@n: number of characters read from user input
*Return: Always success (0);
*/

int show_prompt(char **lineptr, size_t *n)
{
	*lineptr = (char *)malloc((unsigned long)n * sizeof(char));
	write(1, "$ ", 2);
	getline(lineptr, n, stdin);
	return (0);
}
