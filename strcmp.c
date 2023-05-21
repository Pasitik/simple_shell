#include "main.h"
/**
 *_strcmp - compares two strings
 *@s1: A pointer to a character
 *@s2: A pointer to a character
 *Return: int
 */

int _strcmp(char *s1, char *s2)
{

char *first_str = s1;
char *second_str = s2;


while (*first_str != '\0' && *second_str != '\0' && *first_str == *second_str)
{
first_str++;
second_str++;
}

return (*first_str - *second_str);
}

