#include "main.h"

/**
 * tonkenization - breaks command into toke
 *
 * @args: array of params
 * @line: line of commands
 * Return: void
 */

int tonkenization(char **args, char *line)
{
	int arg_count = 0;
	char *token = NULL;
	char *linecpy = NULL;

	linecpy = (char *) malloc(sizeof(char) * (_strlen(line) + 1));

	_strcpy(linecpy, line);

	token = strtok(linecpy, " ");
	while (token != NULL)
	{
		if (args)
		{
			args[arg_count] = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(args[arg_count], token);
		}
		/*free(token);*/
		arg_count++;
		token = strtok(NULL, " ");
	}
	if (args)
	{
		args[arg_count] = NULL;
	}
	free(linecpy);
	/*free(token);*/
	return (arg_count);
}
