#include "main.h"

/**
 * exempt_comments - function to ignore comments
 *
 * @s: input string
 * Return: void
 */
void exempt_comments(char **s)
{
	int i = 0;

	while ((*s)[i] != '\0')
	{
		if ((*s)[i] == '#')
		{
			(*s)[i] = '\0';
			break;
		}
		i++;
	}
}
