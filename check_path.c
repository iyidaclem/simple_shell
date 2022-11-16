#include "simple_shell.h"

/**
*check_path - function to check if a file is a
*file or command exists
*@basepath: base path containing /bin/
*@filename: the file or command entered by the user
*Return: Returns 0 on success and -1 on failure
*/

int check_path(char **basepath, char *filename)
{
	int i;
	struct stat file_stat;
	char *path;

	if (filename == NULL)
		return (-1);
	path = _strchr(filename, '/');
	if (path == NULL)
	{
		*basepath = malloc(sizeof(char) * (5 + _strlen(filename)));
	if (basepath == NULL)
	{
		/*free(*basepath);*/
		return (-1);
	}
	_strcat(*basepath, "/bin/");
	_strcat(*basepath, filename);
	}
	else
	{
		*basepath = malloc(sizeof(char) * (_strlen(filename)));
		if (basepath == NULL)
		{
		/*	free(*basepath);*/
			return (-1);
		}
		_strcat(*basepath, filename);
	}
	i = stat(*basepath, &file_stat);
	if (i == -1)
	{
		return (-1);
	}
	return (0);
}
