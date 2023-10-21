#include "nafsh.h"

/**
 * nafshLaunch - Launch process
 * @args: arguments
 * Return: Always 1
 */
int nafshLaunch(char **args)
{
	pid_t pid;
	int status, i;

	if (args[0] == NULL)
		/* An empty command was entered. */
		return (1);

	for (i = 0; i < nafshBuiltins(); i++)
	{ /* Check if the command is a built-in function. */
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	pid = fork(); /* Fork a new process to execute the command. */
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1) /* Child process */
		{
			perror("nafsh");
			exit(2); /* Return exit status of 2 on error */
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)

		perror("nafsh");/* Forking error */
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (WEXITSTATUS(status));
}
