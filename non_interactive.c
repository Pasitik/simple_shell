#include "main.h"

int non_i_tokenization(char **args, char *line);



/**
 * non_interactive - name of function
 *
 * @argv: array of params
 * @envp: params
 *
 */
void non_interactive(char **argv, char **envp)
{
	char *lineptr = NULL;
	char **args = NULL;
	size_t n = 0;
	ssize_t line = 0;
	int n_args = 0, i = 0;


	line = getline(&lineptr, &n, stdin);

	args = (char **) malloc((n_toks(lineptr) + 1) * (sizeof(char *)));

	n_args = non_i_tokenization(args, lineptr);
	new_process(args, argv[0], envp);
    /*printf("%ld\n%s\n ", line, lineptr);*/
	printf("%ld\n", line);
	free(lineptr);
	while (i < n_args)
	{
		free(args[i]);
		i++;
	}
	free(args);

}

/**
 * non_i_tokenization - breaks command into toke
 *
 * @args: array of params
 * @line: line of commands
 * Return: void
 */

int non_i_tokenization(char **args, char *line)
{
	int arg_count = 0;
	char *token = NULL;
	char *linecpy = NULL;
	int i = 0, flag = 0;

	linecpy = (char *) malloc(sizeof(char) * (strlen(line) + 1));

	_strcpy(linecpy, line);

	token = strtok(linecpy, " \n");
	while (token != NULL)
	{
		flag = 0;
		if (args)
		{
			i = 0;
			while (i < arg_count)
			{
				if (strcmp(token, args[i]) == 0)
				{
					flag = 1;
					break;
				}
				i++;
			}
			if (flag == 0)
			{
				args[arg_count] = malloc(sizeof(char) * (_strlen(token) + 1));
				_strcpy(args[arg_count], token);
			}
		}
		/*free(token);*/
		if (flag == 0)
		{
			arg_count++;
		}
		token = strtok(NULL, " \n");
	}
	if (args)
	{
		args[arg_count] = NULL;
	}
	free(linecpy);
	/*free(token);*/
	return (arg_count);
}
