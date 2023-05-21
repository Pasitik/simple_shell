#include "main.h"

/**
 * _setenv - name of the function
 *
 * @env_name: parameter 1
 * @env_value: parameter 2
 * Return: the function
 */

int _setenv(char *env_name, char *env_value)
{
	char **env_ptr = environ, *new_env = NULL, *env_string = NULL;
	int counter = 0, name_len, value_len, new_len, env_len;
	int env_modified = 0;

	if ((env_name == NULL || env_name[0] == '\0') ||
	(env_value == NULL || env_value[0] == '\0'))
	{
		_env();
		return (1);
	}

	name_len = _strlen(env_name);
	value_len = _strlen(env_value);
	new_len = name_len + value_len + 2;

	new_env = (char *)malloc(new_len);
	if (new_env == NULL)
	{
		perror("failed to allocate memory");
		return (-1);
	}

	_strcpy(new_env, env_name);
	new_env[name_len] = '=';
	_strcpy(new_env + name_len + 1, env_value);


	modify_env(env_ptr, env_string, new_env, env_name, &env_len,
	&counter, &env_modified);

	counter++;
	if (env_modified == 0)
	{
		create_env(counter, new_len, new_env);
	}
	free(new_env);
	return (0);
}
