#include "shell.h"
/**
 * built_ns - array of structs to find matching command string
 * and return corresponding function
 * @args: contains value to match to first element of struct
 *
 * Return: matching function
 */
int built_ins(char **args)
{
	int a;
	built_t arr[] = {
		{"env", _env},
		{"exit", _bin_exit},
		{NULL, NULL}
	};

	for (a = 0; arr[a].cmd != NULL; a++)
	{
		if (_strcmp(args[0], arr[a].cmd) == 0)
			return (arr[a].f(args));
	}
	return (1);
}

/**
 * _env - function to print the environment
 *
 * @args: input
 *
 * Return: 2
 */
int _env(__attribute__ ((unused)) char **args)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (_SKIP);
}
/**
 * _bin_exit - function to exit the shell
 *
 * @args: input
 *
 * Return: 3
 */
int _bin_exit(__attribute__ ((unused)) char **args)
{
	return (_SHELL_END);
}
