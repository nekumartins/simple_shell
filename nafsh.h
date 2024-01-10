#ifndef NAFSH_H
#define NAFSH_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

#define MAX 1024
#define TOKSIZE 64
#define TOKDELIM " \t\r\n\a"

void nafshSigHandler(int signum);
void nafsh(void);
char *nafshReadLine(void);
char **nafshSplitLine(char *line);
int nafshLaunch(char **args);
int nafshCd(char **args);
int nafshHelp(char **args);
int nafshExit(char **args);

extern char *builtin_str[];

/*Define the array of pointers to built-in functions*/
extern int (*builtin_func[]) (char **);

int nafshAtoi(char *stri);
int nafshBuiltins(void);
int nafshExecute(char **args)

#endif /*NAFSH_H*/
