#include "main.h"

/**
 * modify_env - name of function
 *
 * @env_ptr: parameter 1
 * @env_string: parameter 2
 * @new_env: parameter 3
 * @env_name: parameter 4
 * @env_len: parameter 5
 * @counter: parameter 6
 * @env_modified: parameter 7
 * Return: the function
 */

void modify_env(char **env_ptr, char *env_string, char *new_env,
char *env_name, int *env_len, int *counter, int *env_modified)
{

	env_string = (char *)malloc(_strlen(env_name) + 2);
	if (env_string == NULL)
	{
		free(new_env);
		perror("failed to allocate memory");
		exit(1);
	}

	_strcpy(env_string, env_name);
	_strcat(env_string, "=");
	*env_len = _strlen(env_string);

	while (*env_ptr != NULL)
	{
		if (_strncmp(*env_ptr, env_string, *env_len) == 0)
		{
			*env_ptr = new_env;
			*env_modified = 1;
			free(env_string);
			break;
		}
		(*counter)++;
		env_ptr++;
	}
}
