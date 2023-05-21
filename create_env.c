#include "main.h"

/**
 * create_env - name of the function
 *
 * @counter: parameter 1
 * @new_len: parameter 2
 * @new_env: parameter 3
 * Return: the funtion
 */

void create_env(int counter, int new_len, char *new_env)
{
	if (environ == NULL)
	{
		exit(1);
	}

	environ[counter] = NULL;
	environ[counter - 1] = malloc(sizeof(char) * new_len);
	if (environ[counter - 1] == NULL)
	{
		exit(-1);
	}

	_strcpy(environ[counter - 1], new_env);
}

