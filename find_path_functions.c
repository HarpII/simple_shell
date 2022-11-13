#include "shell.h"

/**
 * getKeyValue - gets pointer to the value string
 *
 * @key: key we want to find
 * Return: pointer to key value after the =
 */
char *getKeyValue(char *key)
{
	int i = 0;
	char *tmp = NULL;

	while (environ[i] && tmp == NULL)
	{
		tmp = _strstr(environ[i], key);
		i++;
	}
	tmp = _strstr(tmp, "="), tmp++;
	return (tmp);
}
/**
 * getPathArgs - finds command path
 *
 * @prog: command we want to run
 * Return: executable path of command
 */
char *getPathArgs(char *prog)
{
	char *temp;
	char **temp_arg;
	char *temp_envi;

	temp = getKeyValue("PATH");
	temp_envi = _stralloc(1, temp);
	temp_arg = getToken(&temp_envi, ":");
	temp = get_x_args(temp_arg, prog);

	free(temp_envi);
	free(temp_arg);
	return (temp);
}
/**
 * get_x_args - tests if path is executable
 *
 * @env_paths: path stings
 * @program: command
 * Return: string with full path
 */
char *get_x_args(char **env_paths, char *program)
{
	int i = 1;
	char *temp;

	temp = _stralloc(3, env_paths[0], "/", program);
	while (access(temp, X_OK) == -1 && env_paths[i] != NULL)
	{
		free(temp);
		temp = _stralloc(3, env_paths[i], "/", program);
		i++;
	}
	if (env_paths[i] == NULL)
		return (NULL);
	else
		return (temp);
}

/**
 * _stralloc - allocates and concats a string without realloc
 * @count: number of arguements
 * Return: the concat and allocated string
 */
char *_stralloc(int count, ...)
{
	va_list list;
	char *temp_arg;
	char *temp_ptr;
	char *temp_return;
	int String_length;
	int a_len;

	va_start(list, count);

	temp_arg = va_arg(list, char *), count--;
	a_len = _strlen(temp_arg);

	temp_return = malloc(sizeof(char) * a_len + 1);
	if (temp_return == NULL)
		exit(EXIT_FAILURE);

	_strcpy(temp_return, temp_arg);

	while (count != 0)
	{
		temp_arg = va_arg(list, char *), count--;
		String_length = _strlen(temp_return), a_len = _strlen(temp_arg);

		temp_ptr = malloc(sizeof(char) * (String_length + a_len) + 1);
		if (temp_ptr == NULL)
			perror("check if second malloc failed");

		if (temp_return != NULL)
			_strcpy(temp_ptr, temp_return), free(temp_return);
		_strcat(temp_ptr, temp_arg), temp_return = temp_ptr;
	}

	va_end(list);
	return (temp_return);
}

