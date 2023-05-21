#include "main.h"

/**
 * _unsetenv - function used to unset an environ
 *
 * @args: cmd arguments
 * Return: void
 */

void _unsetenv(char **args)
{
	int env_len, env_index = -1, counter = 0;
	char **env_ptr;

	char *env_string = (char *)malloc(_strlen(args[1]) + 2);

	if (env_string == NULL)
	{
		perror("memory allocation failed");
		return;
	}

	_strcpy(env_string, args[1]);
	_strcat(env_string, "=");
	env_len = _strlen(env_string);

	for (env_ptr = environ; *env_ptr != NULL; env_ptr++)
	{
		if (_strncmp(*env_ptr, env_string, env_len) == 0)
		{
			env_index = counter;
			free(env_string);
		}
		counter++;
	}
	counter++;
	unset(env_index, counter);
}

