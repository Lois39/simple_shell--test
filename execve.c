#include "main.h"
void executeCommand(char **args)
{
char *command = NULL;
if (args)
{
/* get the command */
command = args[0];
/* execute the command with execve */
if (execve(command, args, NULL) == -1)
{
perror("Error:");
}
}
}
