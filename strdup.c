#include "main.h"

/**
 * _strdup - ...
 *
 * @str: ...
 * Return: ...
 */
char *_strdup(char *str)
{

	char *p;

	int i = 0;

	int len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*(str + len) != '\0')
	{
		len++;
	}

	p = (char *) malloc((sizeof(char) * len) + 1);
	if (p == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		*(p + i) = *(str + i);
	}
	return (p);
}

