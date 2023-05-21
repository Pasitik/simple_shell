#include "main.h"
/**
* _strtok - free
* @str: char pointers (string)
* @delim: char pointers serving as delimiters
*
* Description: get string before delimiters, return string
* and reposition pointer to after string
*
* Return: void
*/
char *_strtok(char *str, char *delim)
{
	static char *str_ptr;
	char *n_str;
	int i = 0, j, last_i = 0, is_delim = 0, set_str = 0;

	if (delim == NULL)
		return (str);

	if (str)
		str_ptr = str;
	else if (!str_ptr || _strlen(str_ptr) == 0 ||
			(str_ptr[0] == '\0' || str_ptr[0] == EOF))
		return (NULL);

	n_str = malloc(sizeof(char) * (_strlen(str_ptr) + 1));
	if (n_str == NULL)
		return (NULL);

	for ( ; str_ptr[i] != '\0' && str_ptr[i] != EOF; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
			if (str_ptr[i] == delim[j])
			{
				is_delim = 1;
				continue;
			}

		if (is_delim && set_str)
			break;
		is_delim = 0;
		n_str[last_i++] = str_ptr[i];
		set_str = 1;
	}
	if (last_i == 0)
		return (NULL);
	n_str[last_i] = '\0';
	str_ptr = str = str_ptr + i;
	return (n_str);
}
