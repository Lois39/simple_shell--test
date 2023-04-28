#include "main.h"

/**
 * executeCommand - executes the program referred to by pathname
 * @args: array of pointers to strings
 */

void executeCommand(char **args)
{
	char *path = NULL, *actual_path = NULL;

	if (args)
	{
		/* get the command */
		path = args[0];

		actual_path = get_path(path);

		/* execute the command with execve */
		if (execve(actual_path, args, NULL) == -1)
		{
			perror("Error:");
		};

	}

}