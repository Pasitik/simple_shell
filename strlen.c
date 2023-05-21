#include "main.h"

/**
 * _strlen- name of the function
 *
 * @s: parameter 1
 *Return: int
 */

int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
