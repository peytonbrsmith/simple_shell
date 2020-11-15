#ifndef HOLBERTON_H
#define HOLBERTON_H

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int num_tokens;

char *line;

int shell_terminal;
int shell_interaction;

char *_strdup(char *str);

int _strcmp(char *s1, char *s2);

char **parse();

int launch_process(char **argv, char *envp[]);

void execute(char **tokens);

#endif /* HOLBERTON_H */
