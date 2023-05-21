#include "main.h"

/**
 * isBuiltIn - handles built in functions
 *
 * @args: arguments obtained from commandline
 * Return: void
 */

int isBuiltIn(char *args[])
{
	char *BIcmds[] = {"cd", "setenv", "unsetenv", "env", NULL};
	int i = 0;

	while (BIcmds[i] != NULL)
	{
		if (_strcmp(BIcmds[i], args[0]) == 0)
		{
			return (1);
		}
		i++;
	}

	return (0);
}
