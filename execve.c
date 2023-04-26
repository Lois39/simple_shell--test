#include "main.h"

/**
 * executeCommand - executes the program referred to by pathname
 * @args: array of pointers to strings
 */

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
		};

	}

}
