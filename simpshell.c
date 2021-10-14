#include "holberton.h"

/**
 * main - entry point of the shell, checks interactivity
 * @argc: arg count
 * @argv: array of arguments
 *
 * Return: 0 on success or other integer
 */

int main(int argc, char *argv[])
{
	size_t bufsize = 0;
	char *line = NULL;
	int i, num_tokens = 0, cmdcount = 1, shell_interaction;

	signal(SIGINT, SIG_IGN); /* Check interactivity */
	shell_interaction = isatty(STDIN_FILENO);
	if (shell_interaction == 0 && argc == 1) /* if non-interactive */
	{
		while (getline(&line, &bufsize, stdin) > 0) /* grabs input */
		{
			num_tokens = numcount(line); /* counts the # of tokens */
			parse(line, num_tokens, argv, cmdcount);
			line = NULL;
			/* sends line and numtoken to parser */
		}
		free(line);
		return (0);
	}
	while (shell_interaction)/* if interactive */
	{
		/* Shell prompt */
		write(1, "($) ", 4);
		num_tokens = 0; /* resets token count to 0 */
		i = getline(&line, &bufsize, stdin); /* grabs input */
		if (i < 0)
		{
			free(line);
			write(1, "\n", 1);
			/* frees, skips line, and repeats for failed input or CTRL - D */
			break;
		}
		num_tokens = numcount(line); /* counts tokens */
		parse(line, num_tokens, argv, cmdcount);
		cmdcount++;
		/* sends line and numtoken to parser - tracks fails*/
		line = NULL; /* resets line to null */}
	return (0);
}
