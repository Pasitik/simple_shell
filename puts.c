#include "main.h"

/**
 * _puts - check the code
 *
 * @str: param
 * Return: Always 0.
 */
void _puts(char *str)
{
	int len = 0;

	while (*(str + len) != '\0')
	{
		_putchar(*(str + len));
		len++;
	}
}
