#include "main.h"

/**
 * terminate - the terminating function
 *
 * @args: parameter 1
 * @line: parameter 2
 * Return: int
 */

char *terminate(char **args, char **line)
{

	*line = NULL;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			*line = malloc(sizeof(char) * (_strlen(args[1]) + 1));
			_strcpy(*line, args[1]);
		}
	}
	return (NULL);
}
