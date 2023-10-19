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
	char *prompt = "$ ", *newLine = "\n";
	bool interactive = isatty(STDIN_FILENO);

	signal(SIGINT, nafshSigHandler);
	do {
		if (interactive)
		{
			write(STDOUT_FILENO, prompt, 2);
			fflush(stdout);
		}

		/* Read a line of input */
		line = nafshReadLine();

		if (line == NULL)
		{
			/* Handle Ctrl+D (EOF) by exiting the shell gracefully */
			write(STDOUT_FILENO, newLine, 1);
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
		write(STDERR_FILENO, "nafsh: allocation error\n", 24);
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
				write(STDERR_FILENO, "nafsh: allocation error\n", 24);
				exit(EXIT_FAILURE);
			}
		}
	}
}
