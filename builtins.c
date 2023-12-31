#include "nafsh.h"

/*
* Function Declarations for builtin shell commands:
* List of builtin commands, followed by their corresponding functions.
*/
char (*builtin_str[]) = {
	"cd",
	"help",
	"exit"
};

/*Define the array of pointers to built-in functions */
int (*builtin_func[]) (char **) = {
	&nafshCd,
	&nafshHelp,
	&nafshExit
};
/**
 * nafshBuiltins - Built in Function
 * Return: size
 */

int nafshBuiltins(void)
{
	int size = sizeof(builtin_str) / sizeof(char *);

	return (size);
}

/* Builtin function implementations.*/

/**
 * nafshCd - Built in Function
 * @args: arguments
 * Return: Always 1
 */
int nafshCd(char **args)
{
	if (args[1] == NULL)
	{
		chdir(getenv("HOME"));
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("nafsh");
		}
	}
	return (1);
}

/**
 * nafshHelp - Built in Function
 * @args: arguments
 * Return: Always 1
 */
int nafshHelp(char **args)
{
	int i;
	(void)args;
	printf("Neku and Favour's NAFSH\n");
	printf("Type program names and arguments, then hit enter.\n");
	printf("The following  functions are built in:\n");

	for (i = 0; i < nafshBuiltins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");

	return (1);
}

/**
 * nafshExit - Built in Function
 * @args: arguments
 * Return: Always 1
 */
int nafshExit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{

	int exit_status = nafshAtoi(args[1]);

		if (exit_status == 0 && *args[1] != '0')
		{
			char error_message[] = "nafsh: exit: numeric argument required\n";

			write(STDERR_FILENO, error_message, strlen(error_message));
			exit(2);
		}
		if (exit_status < -2147483647 || exit_status > 2147483647)
		{
			char error_message[] = "nafsh: exit: numeric argument out of range\n";

			write(STDERR_FILENO, error_message, strlen(error_message));
			exit(2);
		}
		status = (int) exit_status;
	}
	exit(status);
}
