#include "main.h"

/**
 * executeCommand - executes the program referred to by pathname
 * @args: array of pointers to strings
 */

void executeCommand(char **args)
{
	char *command = NULL, *actual_command = NULL;

	if (args)
	{
		/* get the command */
		command = args[0];

		actual_command = get_location(command);

		/* execute the command with execve */
		if (execve(actual_command, args, NULL) == -1)
		{
			perror("Error:");
		};

	}

}