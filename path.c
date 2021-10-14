#include "holberton.h"
/**
 * _strcpy - copies str from src to dest
 * @src: source string
 * @dest: destination string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = 0;

	while (*(src + len) != '\0')
	{
		len++;
	}

	for (i = 0; i <= len; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
/**
 * executepath - function to access PATH
 * @p: directory in PATH to access
 * @tokens: array of tokens to check
 */
void executepath(char *p, char **tokens)
{
	int status, len, len2;
	pid_t child;
	char *newp = NULL;

	for (len = 0; *(p + len) != '\0'; len++)
		;
	for (len2 = 0; tokens[0][len2] != '\0'; len2++)
		;
	newp = malloc(sizeof(char) * (len + len2 + 2));
	_strcpy(newp, p);
	_strcat(newp, "/"); /* concatenates the token onto its dir */
	_strcat(newp, tokens[0]);
	newp[(len + len2 + 1)] = '\0';

	child = fork(); /* forks a child */

	if (child == 0)
	{
		if (access(newp, X_OK) == 0) /* checks if we have execute permission */
		{
			execve(newp, tokens, environ);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child) /* waits for child */
			;
	}
	if (status == 0)
		errno = 0;
	free(newp);
}

/**
 * searchpath - function to search PATH
 * @p: part of PATH to search
 * @tokens: array of tokens
 * Return: 0 for success
 */

int searchpath(char *p, char **tokens)
{
	struct dirent *de;
	int reached = 0, onpath = -1;

	p = strtok(p, ":"); /* moves to first path */
	while (p != NULL && reached != 1)
	{
		DIR *dr = opendir(p); /* opens current directory pointer */
		if (dr == NULL)
		{
			/* not found */
			return (0);
		}
		while ((de = readdir(dr)) != NULL)
			/* loops through reading directory contents */
		{
			if (_strcmp(de->d_name, tokens[0]) == 0)
			{           /* compares file name to token */
				executepath(p, tokens);
				/* if exists, attempt to execute */
				onpath = 0;
				/* breaks loops and sets it on path  */
				reached = 1;
				break;
			}
		}
		closedir(dr); /* close the open directory */
		if (reached == 0)
			p = strtok(NULL, ":");
		/* continue to look through dir until something is/isn't found*/
	}
	return (onpath);
}

/**
 * findonpath - find PATH in environ
 * @tokens: token to pass along to PATH
 * Return: 0 for success
 */

int findonpath(char **tokens)
{
	int i = 0, onpath;
	char *p = NULL;
	char *path = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
			/* loops through environ to get path */
		{
			path = _strdup(environ[i]);
			strtok(path, "=");
			p = strtok(NULL, "="); /* singles out the actual paths */
			onpath = searchpath(p, tokens); /* search em' */
			break;
		}
	}
	free(path);
	return (onpath); /* return whether or not its on path */
}
