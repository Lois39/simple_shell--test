#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Display a prompt and wait for the user to type a command
 *
 * Return: 0
 */

int main(void)
{
	char *temp = NULL;
	size_t bytes = 5;

	temp = malloc(sizeof(char) * bytes);

	if (temp == NULL)
	{
		return (0);
	}

	write(1, "shell$", 6);

	getline(&temp, &bytes, stdin);

	free(temp);

	return (0);
}
