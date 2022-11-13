#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define _NORMAL 1
#define _SKIP 2
#define _SHELL_END 3

extern char **environ;

int promptShell(void);
char **getToken(char **buf, char *pattern);
void shellInstance(void);
void execute(char *arg, char **args);
char *getKeyValue(char *key);
char *getPathArgs(char *prog);
char *get_x_args(char **env_paths, char *program);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_memset(char *s, char b, unsigned int n);
int _strlen(char *s);
unsigned int countToks(char *str, char *delim);
char *_stralloc(int count, ...);
char *_strstr(char *haystack, char *needle);
int built_ins(char **args);
int _env(char **args);
int _bin_exit(char **args);
int _strcmp(char *s1, char *s2);

/**
 * struct built - built ins structure
 * @cmd: command to match
 * @f: function to return
 */
typedef struct built
{
	char *cmd;
	int (*f)(char **);
} built_t;
#endif/* SHELL_H */
