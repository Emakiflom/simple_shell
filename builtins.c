#include "shell.h"

/**
 * shell_exit - Exits the shell.
 * This function is designed to be used as a built-in command to exit the shell
 * Return: The function returns -1 to indicate to the main shell loop that the
 * program should exit.
 */

int shell_exit(void)
{
	return (-1);
}

/**
 * shell_env - Prints environment variables.
 * This function prints the environment variables to the standard output.
 * It uses the `environ` variable, which is an external variable containing
 * the environment variables.
 * The function iterates through the `environ` array and prints each
 * environment variable followed by a newline character.
 * Return: The function returns 0.
 */
int shell_env(void)
{
	unsigned int i = 0;
	/* Iterate through the `environ` array */
	while (environ[i] != NULL)
	{
		/* Write the current environment variable to the standard output */
		write(STDOUT_FILENO, environ[i], str_len(environ[i]));
		/* Write a newline character to separate environment variables */
		write(STDOUT_FILENO, "\n", 1);
		/* Move to the next environment variable */
		i++;
	}

	/* Return 0 to indicate successful execution */
	return (0);
}
