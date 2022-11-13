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

/**
 * _strcat - concatenates two strings
 *
 * Description: finds the end of a strings and copies the string from there
 * @dest: destination array
 * @src: sourse array
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
 *
 * Description: loops through array and copies each element
 * @dest: pointer to destination file
 * @src: pointer to source file
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
 * Description: cycles through the array of s until its false
 * @s: input from file
 * Return: returns the length
 */
int _strlen(char *s)
{
	int myCount = 0;

	while (s[myCount] != 0)
		myCount++;
	return (myCount);
}

/**
 * _strstr - locates a substring in a string
 *
 * Description: finds the matching bytes of substring in string
 * @haystack: pointer to the string to search in
 * @needle: pointer to the substring of searched for bytes
 * Return: the matched bytes otherwise null
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *Start = haystack;
		char *pattern = needle;

		while (*haystack && *pattern && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}
		if (!*pattern)
			return (Start);
		haystack = Start + 1;
	}
	return (0);
}

