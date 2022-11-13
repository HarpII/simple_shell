#include "shell.h"

/**
 * _memset - recreates the memset funtion
 *
 * Description: copies the value of c into n characters pointed at s
 * @s: points to the place in memory to write to
 * @b: what you want to replace it with
 * @n: number of characters to be replaced
 * Return: returns the pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	while (n--)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
