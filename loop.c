#include "nafsh.h"

/**
 * nafsh - Main loop function
 * Return: none
 */

void nafsh(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("nafsh$ ");
		fflush(stdout);

		/* Read a line of input, checking for EOF */
		line = nafshReadLine();

		if (line == NULL)
		{
			/* Handle Ctrl+D (EOF) by exiting the shell gracefully */
			printf("\n");
			break;
		}

		args = nafshSplitLine(line);
		status = nafshExecute(args);

		free(line);
		free(args);
	} while (status);
}

/**
 * nafshReadLine - Read line function
 * Return: line
 */

char *nafshReadLine(void)
{
	int buffsize = MAX, position = 0;
	char *buffer = malloc(sizeof(char) * buffsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "nafsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();

		if (c == EOF) /* If we hit EOF, return NULL to indicate Ctrl+D (EOF) */
		{
			free(buffer);
			return (NULL);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
		if (position >= buffsize)
		{
			buffsize += MAX;
			buffer = realloc(buffer, buffsize);
			if (buffer == NULL)
			{
				fprintf(stderr, "nafsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
