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
 * Return: tokens
 */
char **nafshSplitLine(char *line)
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
