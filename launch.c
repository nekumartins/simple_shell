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
	int i;
	 /* Remove comments from the arguments */
	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '#')
		{
			args[i] = NULL;
			break;
		}
	}
	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("nafsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("nafsh");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGKILL)
		{
			/*Program was terminated by SIGKILL*/
			exit(EXIT_SUCCESS);
		}
		return (WEXITSTATUS(status));
	}
			return (1);
}
