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
	size_t num_chars;

	*lineptr = (char *)malloc((unsigned long)n * sizeof(char));
	write(1, "Ctrl C for exit\n", 16);
	write(1, "$ ", 2);

	num_chars = getline(lineptr, n, stdin);
	/* If number of stream is less than 0 */
	if ((int)num_chars == -1)
		exit(0);

	return ((int)num_chars);
}
