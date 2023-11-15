#include "shell.h"

/**
 * str_cmp - Compares two strings (name and variable) character by character up
 * to the specified length (length).
 * Returns 1 if the strings are not equal, -1 if the lengths are different,
 * and 0 if the strings are equal.
 * @name: Name supplied by the user to search for.
 * @variable: Variable to compare against.
 * @length: Length of the name.
 * Return: 1 if strings are equal, -1 if they are not.
 */
int str_cmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;
	/* Get the length of the variable string. */
	var_length = str_len(variable);
	/* If lengths are not equal, strings can't be the same. */
	if (var_length != length)
		return (-1);
	i = 0;
	/* Compare characters until a mismatch or end of the strings. */
	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1); /* Strings are not equal. */
		i++;
	}
	return (0); /* Strings are equal. */
}

/**
 * str_ncmp - Compares two strings (name and variable) up to
 * a specified length (length).
 * Returns 1 if the strings are equal up to the specified length,
 * and -1 otherwise.
 * @name: Name supplied by the user to search for.
 * @variable: Variable to compare against.
 * @length: Length to compare up to.
 * Return: 1 if strings are equal, -1 if they are not.
 */
int str_ncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;

	/* Compare characters up to the specified length. */
	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1); /* Strings are not equal. */
		i++;
	}
	return (1); /* Strings are equal. */
}

/**
 * str_cpy - Copies the string pointed to by src to buffer pointed to by dest.
 * Returns the pointer to dest.
 * @dest: String destination.
 * @src: String source.
 * Return: The pointer to dest.
 */
char *str_cpy(char *dest, char *src)
{
	int i;
	int j = str_len(src);
	/* Copy characters from src to dest. */
	for (i = 0; i <= j; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * str_len - Returns the length of the input string s. Counts characters until
 * the null terminator is encountered.
 * @s: String to be evaluated.
 * Return: Length of the string.
 */
int str_len(char *s)
{
	int i = 0;
	/* Count characters until the null terminator is encountered. */
	while (s[i] != '\0')
		i++;
	return (i);
}
