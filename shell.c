#include "simple_shell.h"

/**
 * free_data - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
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


/**
*main - Entry point into our shell program
*@argc: argument count
*@argv: argument to the main function
*Return: Always success (0);
*/


int main(int argc, char **argv)
{
	data_shell datash;
	(void)argc;

	signal(SIGINT, get_sigint);
	set_data(&datash, argv);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}


