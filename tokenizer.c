#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of tokens.
 * Takes a user input string (str) as input.
 * Allocates memory for an array of tokens (tokens) using the malloc function.
 * Uses the strtok function to tokenize the input string based on the
 * specified delimiters ("\n\t\r ").
 * Stores each token in the tokens array.
 * The array of tokens is terminated with a NULL
 * pointer to indicate the end of tokens.
 * Returns a pointer to the array of tokens.
 * @str: User input string to be tokenized.
 * Return: Pointer to an array of tokens.
 */
char **tokenizer(char *str)
{
	char **tokens;         /* Pointer to store the array of tokens */
	char *token;           /* Temporary variable to hold each token */
	unsigned int i;        /* Index variable */
	/* Allocate memory for the array of tokens */
	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3); /* Print error message and exit memory allocation */
		exit(EXIT_FAILURE);
	}
	/* strtok to extract tokens fro input str on delimiters("\n\t\r ") */
	token = strtok(str, "\n\t\r ");
	i = 0;
	/* Iterate through the tokens and store them in the tokens array */
	while (token != NULL)
	{
		tokens[i] = token;  /* Store the current token in the array */
		token = strtok(NULL, "\n\t\r ");  /* Get the next token */
		i++;               /* Move to the next index */
	}
	tokens[i] = NULL;  /* Set last element of array NULL mark end tokens */
	return (tokens);       /* Return the pointer to the array of tokens */
}
