#include "main.h"

/**
 * num_length - numlength
 * @num_len: nums
 * Return: len
 */
int num_length(int num_len)
{
	unsigned int num1;
	int len = 1;

	if (num_len < 0)
	{
		len++;
		num1 = num_len * -1;
	}
	else
	{
		num1 = num_len;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}

/**
 * _itoa - name of function
 * @num_len: nums
 * Return: len
 */
char *_itoa(int num_len)
{
	char *buff;
	int len_num = num_length(num_len);
	unsigned int num1;

	buff = malloc(sizeof(char) * (len_num + 1));
	if (!buff)
		return (NULL);

	buff[len_num] = '\0';

	if (num_len < 0)
	{
		num1 = num_len * -1;
		buff[0] = '-';
	}
	else
	{
		num1 = num_len;
	}

	len_num--;
	do {
		buff[len_num] = (num1 % 10) + '0';
		num1 /= 10;
		len_num--;
	} while (num1 > 0);

	return (buff);
}
