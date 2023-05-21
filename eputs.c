
#include "main.h"

/**
 * _eputs - check the code
 *
 * @str: param
 * Return: Always 0.
 */
void _eputs(char *str)
{
	int len = 0;

	while (*(str + len) != '\0')
	{
		write(2, str + len, 1);
		len++;
	}
}
