#include "shell.h"

/**
 * errors - This function is designed to print error messages
 * based on the given error number.
 * It uses a switch statement to handle different error cases.
 * For each case, it writes a predefined error messag
 * to the standard error stream (stderr).
 * In cases 1 and 3, it uses the perror function to print and
 * additional error message based on the current value of errno.
 * Case 4 writes a predefined empty path error message to stderr.
 * The str_len function (presumably a string length function) is used
 * to determine the length of the error messages.
 * If the error number does not match any case, the function returns
 * without performing any action.
 * @error: Error number associated with perror statement.
 * Return: void
 */

void errors(int error)
{
	switch (error)
	{
		case 1: /* Writes fork error to stderr */
			write(STDERR_FILENO, ERR_FORK, str_len(ERR_FORK));
			perror("Error");
			break;
		case 2: /* Writes execve error to stderr */
			perror("Error");
			break;
		case 3: /* Writes malloc error to stderr */
			write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
			break;
		case 4: /* Writes empty path error to stderr */
			write(STDERR_FILENO, ERR_PATH, str_len(ERR_PATH));
			break;
		default:
			return;
	}
}
