#include "main.h"

/**
 * get_env - name of function
 *
 * @name: parameter 1
 * Return: the funtion
 */

char *get_env(char *name)
{
	char **p;
	size_t len = _strlen(name);

	for (p = environ; *p != NULL; p++)
	{
		if (_strncmp(*p, name, len) == 0 && (*p)[len] == '=')
		{
			return (*p + len + 1);
		}
	}
	return (NULL);
}
