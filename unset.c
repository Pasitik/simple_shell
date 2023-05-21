#include "main.h"

/**
 * unset - function used to unset an environ. works within _unsetenv()
 *
 * @env_index: ...
 * @counter: ...
 * Return: void
 */

void unset(int env_index, int counter)
{
	while (env_index > -1 && env_index != counter - 1)
	{
		if (environ[env_index + 1] != NULL)
		{
			environ[env_index] = (char *) malloc(sizeof(char) *
			(_strlen(environ[env_index + 1]) + 1));
			if (environ[env_index] == NULL)
			{
			return;
			}
			_strcpy(environ[env_index], environ[env_index + 1]);
		}
		else
		{
			environ[env_index] = NULL;
			free(environ[env_index + 1]);
			break;
		}
		env_index++;
	}
}

