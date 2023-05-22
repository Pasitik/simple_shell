#include "main.h"

/**
 * my_getline - afunction to get the cmd line input
 *
 * @line_ptr: pointer to line input
 * @n_chars: pointer to number of characters
 * @stream: pointer to stream
 * Return: the number of characters read
 */

int my_getline(char **line_ptr, size_t *n_chars, FILE *stream)
{
	int isFirstRead = 1;
	char *line = malloc(sizeof(char) * BUFFER_SIZE);
	int  read_chars = 0;
	/*n_chars = 0;*/
	int len = 0;
	size_t oldsize = 0, new_size = 0;

	int input_stream = (int)(intptr_t)stream;

	*n_chars = 0;

	while (1)
	{
		read_chars = read(input_stream, line + *n_chars, BUFFER_SIZE);
		if (read_chars == -1)
		{
			return (-1);
		}
		*n_chars += read_chars;
		if (isFirstRead == 0 && *n_chars >= oldsize)
		{
			new_size = oldsize * 2;
			line = _realloc(line, oldsize, new_size);
			oldsize = new_size;
		}
		if (isFirstRead == 1)
		{
			oldsize += BUFFER_SIZE;
			isFirstRead = 0;
		}

		len = (int) *n_chars;
		if (read_chars == 0 || line[len - 1] == '\n')
		{
			break;
		};
	}
	line[len] = '\0';
	*line_ptr = line;
	return (len);
}
