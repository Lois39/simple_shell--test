#include "main.h"

/**
 * main - Display a prompt and wait for the user to type a command
 *
 * Return: 0
 */

int main(int ac, char *argv[])
{
	char *temp = NULL, *temp_copy = NULL, *token;
	size_t bytes = 10;
	ssize_t n_read;
	const char *delim = " \n";
	int i, ntokens = 0;

	(void)ac;

	temp = malloc(sizeof(char) * bytes);

        if (temp == NULL)
        {
                return (0);
        }

	while (1)
	{
		write(1, "shell$ ", 7);

		n_read = getline(&temp, &bytes, stdin);

		if (n_read == -1)
		{
			printf("EXIT SHELL...\n");
			exit(EXIT_SUCCESS);
		}

		temp_copy = malloc(sizeof(char) * n_read);
		
		if (temp_copy == NULL)
		{
                	perror("memory allocation error");
                	return (-1);
		}

		strcpy(temp_copy, temp);

		token = strtok(temp, delim);

		while (!token)
		{
			token = strtok(NULL, delim);
			ntokens++;
		}

		argv = malloc(sizeof(char *) * ntokens);

		token = strtok(temp_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}

		argv[i] = NULL;

		executeCommand(argv);

	}
	free(temp_copy);
	free(temp);

	return (0);
}
