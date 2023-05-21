#include "main.h"

/**
 * print_n_int_error - name of the function
 *
 * @command: paramater 1
 * @str_path: parameter 2
 * @is_term: param 3
 * Return: the function
 */
void print_n_int_error(char *command, char *str_path, int is_term)
{

	if (is_term == 1)
	{
		_puts(command);
		_puts(": command not found\n");
	}
	else
	{
		_puts(str_path);
		_puts(": 1: ");
		_puts(command);
		_puts(": not found\n");
	}
	exit(127);
}

/**
 * cmd_location - name of the function
 *
 * @command: paramater 1
 * @str_path: parameter 2
 * Return: the function
 */

char *cmd_location(char *command, char *str_path)
{
	char *path, *pathcpy, *dir, *exe_path;
	int command_len, dir_len, size;
	int is_term = isatty(STDIN_FILENO);

	path = getenv("PATH");
	pathcpy = _strdup(path);
	command_len = _strlen(command);
	dir = strtok(pathcpy, ":");
	if (access(command, X_OK) == 0)
	{
		printf("valid");
		free(pathcpy);
		return (command);
	}

	while (dir)
	{
		dir_len = _strlen(dir);
		size = command_len + dir_len + 2;
		exe_path = (char *) malloc(size);
		_strcpy(exe_path, dir);
		_strcat(exe_path, "/");
		_strcat(exe_path, command);
		_strcat(exe_path, "\0");
		if (access(exe_path, X_OK) == 0)
		{
			free(pathcpy);
			return (exe_path);
		}
		else
		{
			free(exe_path);
			dir = strtok(NULL, ":");
		}
	}
	print_n_int_error(command, str_path, is_term);
	free(pathcpy);
	return (NULL);
}


