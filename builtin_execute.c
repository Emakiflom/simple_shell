#include "shell.h"

/**
 * buiilt_in_execu - Executes built-in commands based on the provided tokens.
 * It checks if a command is provided, and if not, returns 1.
 * It iterates through an array of built-in commands
 * and their corresponding functions.
 * If the provided command matches a built-in command, it executes
 * the corresponding function and returns its status.
 * If the command is not a built-in, it returns 1.
 * @tokens: Arguments being passed.
 * Return: The return value depends on the execution of the built-in function.
 */
int buiilt_in_execu(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;
	/* Array of built-in commands and their corresponding functions */
	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};
	/* Check if no command is provided */
	if (tokens[0] == NULL)
		return (1);
	/* Get the length of the first token (command) */
	length = str_len(tokens[0]);
	/* Get the number of built-in commands */
	num = shell_no_builtins(builtin);
	/* Iterate through the array of built-in commands */
	for (i = 0; i < num; i++)
	{
		/* Check if the provided command matches the current built-in command */
		if (str_cmp(tokens[0], builtin[i].name, length) == 0)
		{
			/* Execute the corresponding built-in function and store its return value */
			status = (builtin[i].p)();
			/* Return the status, indicating the success or failure */
			/* of the built-in function */
			return (status);
		}
	}
	/* If the command is not a built-in, return 1 (considered as a success) */
	return (1);
}

/**
 * shell_no_builtins - Counts the number of built-in commands in the array.
 * It iterates through the array until a NULL entry is encountered
 * and counts the number of built-in commands.
 * Returns the total number of built-in commands.
 * @builtin: Array of built-in commands.
 * Return: The number of built-in commands.
 */
int shell_no_builtins(built_s builtin[])
{
	unsigned int i = 0;
	/* Iterate through the array until a NULL entry is encountered, */
	/* counting the number of built-in commands */
	while (builtin[i].name != NULL)
		i++;
	/* Return the total number of built-in commands */
	return (i);
}
