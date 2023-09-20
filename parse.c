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
		fprintf(stderr, "nafsh: allocation error\n");
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
				fprintf(stderr, "nafsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKDELIM);
	}
	tokens[position] = NULL;

	return (tokens);
}
