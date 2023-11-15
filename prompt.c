#include "shell.h"

/**
 * prompt - This function checks whether the shell is in interactive mode by
 * examining the file descriptor's information. If it's in interactive mode
 * (determined by checking if the file is a character special file),
 * it prints the shell prompt.
 * The fd parameter represents the file descriptor associated with the file,
 * and buf is a structure containing information about the file, obtained
 * using the fstat function.
 * if (S_ISCHR(buf.st_mode)): Checks if the file is a character special file
 * (typically a terminal) by using the S_ISCHR macro.
 * @fd: File stream (file descriptor).
 * @buf: Buffer containing information about the file.
 */
void prompt(int fd, struct stat buf)
{
	/* Use the fstat function to get information about the file */
	/*  associated with the file descriptor (fd). */
	fstat(fd, &buf);
	/* Check if the file is a character special file */
	/*  (character device, like a terminal). */
	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT); /* If it's character special file print shell */
}

/**
 * _puts -  function to print the shell prompt (defined elsewhere
 * in the code as PROMPT).
 * Calculates the length of the input string using str_len.
 * Uses the write function to print the string to the standard output.
 * @str: String to print.
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;
	/* Calculate the length of the input string. */
	length = str_len(str);
	/* Use the write function to print the string to */
	/* the standard output (STDOUT_FILENO). */
	write(STDOUT_FILENO, str, length);
}
