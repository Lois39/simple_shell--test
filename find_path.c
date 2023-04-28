#include "main.h"
/*
 *main - A simple shell program that executes user commands
 *
 * return: 0 on success, non-zero value on failure
 */
int main(void)
{
char command[200];
char path[200];
while (1)
{
write(STDOUT_FILENO, "Shell $ ", 8);
scanf("%s", command);
if (strcmp(command, "exit") == 0)
{
break;
}
sprintf(path, "which %s", command);
FILE* cmd = popen(path, "r");
if (!cmd)
{
write(STDERR_FILENO, "Error trying to run command\n", 28);
continue;
}
char output[200];
fgets(output, sizeof(output), cmd);
if (strlen(output) > 0)
{
write(STDOUT_FILENO, output, strlen(output));
}
else
{
write(STDOUT_FILENO, "Command cannot be found\n", 24);
}
pclose(cmd);
}
return (0);
}
