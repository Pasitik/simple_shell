#include "main.h"

/**
 * _realloc - reallocates memmory
 *
 * @ptr: pointer to a string
 * @old_size: previeous size of reserved memory
 * @new_size: new size to be allocated
 * Return: a new pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);

		if (new_ptr == NULL)
			return (NULL);

		free(ptr);
		return (new_ptr);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
	{
		*(new_ptr + i) = ((char *) ptr)[i];
	}

	free(ptr);
	return (new_ptr);
}

