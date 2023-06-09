#include "main.h"

/**
 * main - Display a prompt and wait for the user to type a command
 * @ac: argument count
 * @av: pointer to array of strings
 *
 * Return: 0
 */

int main(int ac, char *av[])
{
	char *temp = NULL, *temp_copy = NULL, *token;
	size_t bytes = 10;
	ssize_t n_read;
	const char *delim = " \n";
	int i, ntokens = 0;

	(void)ac;

	temp = malloc(sizeof(char) * bytes);

	if (temp == NULL)
		return (0);

	while (1)
	{
		write(1, "shell$ ", 7);
		n_read = getline(&temp, &bytes, stdin);

		if (n_read == -1)
		{
			write(STDOUT_FILENO, "EXIT SHELL...\n", 14);
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

		av = malloc(sizeof(char *) * ntokens);
		token = strtok(temp_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}

		av[i] = NULL;

		executeCommand(av);
	}

	free(temp_copy);
	free(temp);

	return (0);

}
