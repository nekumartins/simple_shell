#include "nafsh.h"

/**
 * nafshLaunch - Launch process
 * @args: arguments
 * Return: Always 1
 */
int nafshLaunch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("nafsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("nafsh");
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
