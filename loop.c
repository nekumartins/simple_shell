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
		line = nafshReadLine();
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
	int buffsize = MAX;
	int position = 0;
	char *buffer = malloc(sizeof(char) * buffsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "nafsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* Read a character */
		c = getchar();

		/* If we hit EOF, replace it with a null character and return. */
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		/* If we have exceeded the buffer, reallocate.*/
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
