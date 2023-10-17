#include "nafsh.h"

/**
 * nafshSplitLine - Split a line into tokens
 * @line: line
 * Return: tokens
 */
char **nafshSplitLine(char *line)
{
	int buffsize = TOKSIZE, position = 0;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		write(STDERR_FILENO, "nafsh: allocation error\n", 24);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKDELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffsize)
		{
			buffsize += TOKSIZE;
			tokens = realloc(tokens, buffsize * sizeof(char *));
			if (!tokens)
			{
				write(STDERR_FILENO, "nafsh: allocation error\n", 24);
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKDELIM);
	}
	tokens[position] = NULL;

	return (tokens);
}
