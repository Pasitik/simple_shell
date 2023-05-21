#include "main.h"

/**
 * _env - lists contents of the environ array
 *
 * Return: void
 */

void _env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
}
