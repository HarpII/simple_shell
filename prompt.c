#include "shell.h"
/**
 * promptShell - stats the shell prompt
 *
 * Return: returns value to continue or stop shell
 */
int promptShell(void)
{
	char *buffer = NULL;
	char *pPath = NULL;
	char **args = NULL;
	size_t length = 0;
	ssize_t getCheck;
	int stat = _NORMAL;

	stat = _NORMAL;
	write(STDOUT_FILENO, "$ ", 2);
	getCheck = getline(&buffer, &length, stdin);

	if (getCheck == -1)
	{
		stat = _SHELL_END;
		write(STDOUT_FILENO, "\n", 1);
	}
	else if (getCheck == 1)
		stat = _SKIP;

	if (stat == _NORMAL)
	{
		args = getToken(&buffer, "' '\n\t\r");
		stat = built_ins(args);
	}

	if (stat == _NORMAL && args[0][0] != '.')
		pPath = getPathArgs(args[0]);

	if (stat == _NORMAL)
		execute(pPath ? pPath : args[0], args);

	free(args);
	free(pPath);
	free(buffer);
	return (stat);
}

/**
 * execute - executes the command with its arguements
 *
 * @arg: the command
 * @args: arguements
 */
void execute(char *arg, char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(arg, args, NULL) == -1)
		{
			perror("Execute command failed");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid == -1)
		perror("Fork error");
	else
		wait(NULL);
}
