#include "main.h"

/**
 * exec_builtIns - name of the function
 *
 * @args: paramater 1
 * @str_path: parameter 2
 * @envp: parameter 3
 *Return: the function
 */

void exec_builtIns(char **args, char *str_path, char *envp[])
{
	(void) str_path;
	(void) envp;

	if (_strcmp(args[0], "setenv") == 0)
	{
		_setenv(args[1], args[2]);
		return;
	}
	if (_strcmp(args[0], "env") == 0)
	{
		_env();
		return;
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		_unsetenv(args);
		return;
	}
	if (_strcmp(args[0], "cd") == 0)
	{
		_cd(args);
		return;
	}
}
