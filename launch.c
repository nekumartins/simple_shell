#include "nafsh.h"
/**
 * nafshLaunch - Launch process
 * @args: arguments
 * Return: Always 1
 */
int nafshLaunch(char **args)
{
	if (args[0] == NULL)
		/* An empty command was entered. */
		return (1);

	if (nafshExecuteBuiltins(args))
		return (1);

	if (nafshExecuteCommand(args))
		return (1);

	return (1);
}

/**
 * nafshExecuteBuiltins - Execute built-in functions
 * @args: arguments
 * Return: 1 if a built-in function was executed, 0 otherwise
 */
int nafshExecuteBuiltins(char **args)
{
	int i;

	for (i = 0; i < nafshBuiltins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (0);
}

/**
 * nafshExecuteCommand - Execute a command
 * @args: arguments
 * Return: 1 if the command was executed, 0 otherwise
 */
int nafshExecuteCommand(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("nafsh");
			exit(2);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("nafsh");
	}
	else
	{
		wait(&status);
	}

	return (1);
}
