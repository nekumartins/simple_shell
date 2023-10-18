#include "nafsh.h"

/**
 * nafshAtoi - Convert a string to an integer
 * @stri: line
 * Return: integer
 */
int nafshAtoi(char *stri)
{
	int result = 0;
	int sign = 1;

	if (*stri == '-')
	{
		sign = -1;
		stri++;
	}

	while (*stri != '\0')
	{
		if (*stri < '0' || *stri > '9')
		{
			break;
		}
		result = result * 10 + (*stri - '0');
		stri++;
	}

	return (sign * result);
}

/**
 * nafshSplitLine - Split a line into tokens
 * @line: line
 * @delim: delimiter
 * Return: tokens
 */
char **nafshSplitLine(char *line, char *delim)
{
	 int buffsize = TOKSIZE;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *token;
	int position = 0;

	if (!tokens)
	{
		write(STDERR_FILENO, "nafsh: allocation error\n", 24);
		exit(EXIT_FAILURE);
	}

	token = line;
	while (*line != '\0')
	{
		if (*line == *delim)
		{
			*line = '\0';
			tokens[position] = token;
			position++;
			token = line + 1;

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
		}
		line++;
	}
	tokens[position] = token;
	tokens[position + 1] = NULL;

	return (tokens);
}
