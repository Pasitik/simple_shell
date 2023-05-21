#include "main.h"

/**
 *notValidError - .....
 *
 * @exit_status: ...
 * Return: int
 */
int notValidError(char *exit_status)
{
	int i = 0;

	if (exit_status == NULL)
		return (0);
	while (exit_status[i] != '\0')
	{
		if (exit_status[i] > '9' || exit_status[i] < '0')
			return (1);
		i++;
	}
	return (0);
}


/**
 *print_failed_exit - .....
 *
 * @exit_status: ...
 * @argv: ...
 * Return: void
 */

void print_failed_exit(char *exit_status, char **argv)
{
	_eputs(argv[0]);
	_eputs(": 1: exit: Illegal number: ");
	_eputs(exit_status);
	_eputs("\n");
	free(exit_status);
	exit(2);
}


/**
 *free_array - .....
 *
 * @args: ...
 * Return: void
 */

void free_array(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);

}

/**
 * n_toks - ...
 *
 * @line: ...
 * Return: int
 */
void readline_error_handler(ssize_t read_line)
{
	if (read_line == -1)
	{
		perror("couldn't read line");
		exit(EXIT_FAILURE);
	}
}
/**
 * main - name of the function
 *
 * @argc: parameter 1
 * @argv: parameter 2
 * @envp: parameter 3
 * Return: char
 */
int main(int argc, char *argv[], char *envp[])
{
	char *line = NULL, **args = NULL, *exit_status = NULL;
	size_t len = 0;
	ssize_t read_line;
	int shell = isatty(STDIN_FILENO), is_term = -1;
	(void) argc;

	if (shell == 1)
	{
		while (1)
		{
			write(STDOUT_FILENO, "myshell> ", 9);
			read_line = my_getline(&line, &len, STDIN_FILENO);
			readline_error_handler(read_line);
			line[read_line - 1] =  (line[read_line - 1] == '\n') ?
				'\0' : line[read_line - 1];
			exempt_comments(&line);
			args = (char **) malloc((n_toks(line) + 1) * (sizeof(char *)));
			tonkenization(args, line);
			terminate(args, &exit_status);
			if (_strcmp(args[0], "exit") == 0)
			{
				is_term = exit_status ?  _atoi(exit_status) : 0;
				free(line);
				free_array(args);
				if (notValidError(exit_status))
					print_failed_exit(exit_status, argv);
				free(exit_status);
				exit(is_term);
			}
			new_process(args, argv[0], envp);
			free(line);
			free_array(args);
			if (is_term == 0)
				break;
		}
	}
	else if (shell == 0)
		non_interactive(argv, envp);
	exit(EXIT_SUCCESS);
}
