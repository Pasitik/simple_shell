#include "main.h"

/**
 * _strncmp - name of function
 * @s1: parameter 1
 * @s2: parameter 2
 * @len: param 3
 * Return: the function
 */

int _strncmp(char *s1, char *s2, int len)
{
int i = 0, counter = 0;

while (i < len)
{
if (*(s1 + i) == *(s2 + i))
{
counter++;
}
else
{
break;
}
i++;
}
return (len - counter);
}

