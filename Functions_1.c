#include "shell.h"

/**
 * _memset - copies the value of b into n characters pointed at s
 * @s: points to the place in memory to write to
 * @b: what you want to replace it with
 * @n: number of characters to be replaced
 *
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

/**
 * _strcat - finds the end of a strings and copies the string from there
 * @dest: destination array
 * @src: source array
 *
 * Return: returns the destination file
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	for (j = 0 ; src[j] != '\0' ; j++, i++)
	{
		dest[i] = src[j];
	}

	dest[i] =  '\0';
	return (dest);
}

/**
 * _strcpy - copys array from one pointer to another
 * @dest: pointer to destination file
 * @src: pointer to source file
 *
 * Return: the array
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = src[i];
	return (dest);
}

/**
 * _strlen - prints the length of a string
 * @s: input string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int counter = 0;
	/* initialize a counter for the length */

	while (s[counter] != 0) /*uses s to create an array for the input*/
		counter++; /*counts every element*/
	return (counter); /*return end counter8*/
}

/**
 * _strstr - locates a substring in a string
 * @haystack: pointer to the string to search in
 * @needle: pointer to the substring of searched for bytes
 *
 * Return: the matched bytes otherwise null
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *Begin = haystack;
		char *pattern = needle;

		while (*haystack && *pattern && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}
		if (!*pattern)
			return (Begin);
		haystack = Begin + 1;
	}
	return (0);
}
