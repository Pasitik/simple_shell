#include "main.h"

/**
 * n_toks - name of function
 * @line: parameter of the function
 * Return: arg_count
 */
int n_toks(char *line)
{
	char *linecpy = NULL;
	int arg_count = 0;
	char *token;

	linecpy = (char *) malloc(sizeof(char) * (_strlen(line) + 1));
	_strcpy(linecpy, line);
	token = strtok(linecpy, " ");
	while (token != NULL)
	{
		arg_count++;
		token = strtok(NULL, " ");
	}
	free(linecpy);
	return (arg_count);
}
