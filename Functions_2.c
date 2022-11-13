#include "shell.h"

/**
 * _strcmp - compares two strings and returns the difference
 * @s1: string 1
 * @s2: string 2
 *
 * Return: returns the diffrence of the ascii values
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2 || *s2 > *s1)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
