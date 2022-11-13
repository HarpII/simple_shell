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

/**
 * getToken - tokenizes the string
 *
 * @buf: buffer where string is held
 * @pattern: the demiliter
 *
 * Return: tokenized string of pointers
 */
char **getToken(char **buf, char *pattern)
{
	int i = 1;
	char *tok;
	char **args;
	unsigned int tokCount;

	tokCount = countToks(*buf, pattern);

	tok = strtok(*buf, pattern);
	if (tok == NULL)
		perror("no command passed: "), exit(EXIT_FAILURE);
	args = malloc(sizeof(char *) * (tokCount + 1));
	if (args == NULL)
		perror("Error in Allocation"), exit(EXIT_FAILURE);
	args[0] = tok;

	while (tok != NULL)
	{
		tok = strtok(NULL, pattern);
		if (tok != NULL)
			args[i] = tok, i++;
	}
	args[i] = NULL;
	return (args);
}
