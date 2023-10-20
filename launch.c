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

	for (i = 0; args[i] != NULL; i++) /* Remove comments from the arguments */
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
		if (execvp(args[0], args) == -1)/*Child process*/
			perror("nafsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("nafsh");/*Fork error*/
	}
	else
	{
		do {/*Parent process*/
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGKILL)
			exit(EXIT_SUCCESS);/*Program was terminated by SIGKILL*/

		return (WEXITSTATUS(status));
	}
		return (1);
}
