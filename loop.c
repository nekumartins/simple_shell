#include "nafsh.h"


/**
 * nafshSigHandler - Prints a new prompt upon a signal.
 * @signum: The signal.
 */
void nafshSigHandler(int signum)
{
	char *newPrompt = "\n$ ";

	(void)signum;
	signal(SIGINT, nafshSigHandler);
	write(STDIN_FILENO, newPrompt, 3);
}

/**
 * nafsh - Main loop function
 * Return: none
 */

void nafsh(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, nafshSigHandler);

	do {
		printf("$ ");
		fflush(stdout);

		/* Read a line of input */
		line = nafshReadLine();

		if (line == NULL)
		{
			/* Handle Ctrl+D (EOF) by exiting the shell gracefully */
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
