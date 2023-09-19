#include "nafsh.h"
/*
  Function Declarations for builtin shell commands:
 */



/*
  List of builtin commands, followed by their corresponding functions.
 */

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

/* Define the array of pointers to built-in functions */ 
int (*builtin_func[]) (char **) = {
  &nafshCd,
  &nafshHelp,
  &nafshExit
};

int nafshBuiltins() 
{
    int size = sizeof(builtin_str) / sizeof(char *);
  return (size);
}

/*
  Builtin function implementations.
*/
int nafshCd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "nafsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

int nafshHelp(char **args)
{
  int i;
  printf("Neku and Favour's NAFSH\n");
  printf("Type program names and arguments, then hit enter.\n");
  printf("The following  functions are built in:\n");

  for (i = 0; i < nafshBuiltins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int nafshExit(char **args)
{
  return 0;
}