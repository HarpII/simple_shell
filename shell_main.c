#include "shell.h"

/**
 * main - method to read input form user
 *
 * Return: 0 on success
 *
 */

int main(void)
{
	int stat;

	do {
		stat = promptShell();
	} while (stat != _SHELL_END);

	return (EXIT_SUCCESS);
}


