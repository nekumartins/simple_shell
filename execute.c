#include "nafsh.h"

int nafshExecute(char **args)
{
  int i;

  if (args[0] == NULL) {
    /* An empty command was entered. */ 
    return (1);
  }

  for (i = 0; i < nafshBuiltins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return nafshLaunch(args);
}
