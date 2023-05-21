#include "main.h"

/**
 * first_tok - name of function
 *
 * @next_tok: parameter 1
 * @delim: parameter 3
 * @isdelim: parameter 4
 * Return: the function
 */

int first_tok(char *next_tok, char *delim, int *isdelim)
{
	int i = 0, j = 0;

	for  ( ; *(next_tok + j) != '\0'; j++)
	{
		i = 0;
		*isdelim = 0;
		while (delim[i] != '\0')
		{
			if (next_tok[j] == delim[i])
			{
				*isdelim = 1;
				break;
			}
			i++;
		}


		if (*isdelim == 1)
		{
			next_tok[j] = '\0';

			return (j);
		}
	}
	return (j);
}
