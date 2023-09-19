#include "nafsh.h"


int nafshLaunch(char **args)
{
  pid_t pid;
  pid_t waitPid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    /* Child process */ 
    if (execvp(args[0], args) == -1)
    {
      perror("nafsh");
    }
    exit(EXIT_FAILURE);
  } 
  else if (pid < 0) 
  {
    /* Error forking */ 
    perror("nafsh");
  } 
  else 
  {
    /* Parent process */ 
    do 
    {
      waitPid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    (void)waitPid;
  }

  return 1;
}

