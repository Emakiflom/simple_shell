#include "shell.h"

/**
 * free_all - This function is designed to free dynamically allocated memory
 * atthe end of the main loop in your shell program.
 * The function uses the free function to release the memory occupied
 * by each dynamically allocated variable.
 * It checks whether fullpath was dynamically allocated
 * (flag == 1) before attempting to free it.
 * @tokens: Pointer to tokens array.
 * @path: Pointer to path variable.
 * @line: Pointer to user input buffer.
 * @fullpath: Pointer to full path.
 * @flag: Flag marking if full_path was malloc'd.
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag)
{
	/*  Free dynamically allocated path variable */
	free(path);
	/* Free dynamically allocated tokens array */
	free(tokens);
	/* Free dynamically allocated user input buffer */
	free(line);
	/* Check if fullpath was dynamically allocated before freeing */
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - This function is responsible for freeing a double pointer (array)
 * and the memoryoccupied by the strings it points to.
 * The function uses for loop to iterate each element of the double pointer.
 * It uses the free function to release the memory occupied by the strings
 * pointed to by the double pointer.
 * Finally, it frees the memory occupied by the double pointer
 * itself using free(array).
 * @array: Double pointer to free.
 * @length: Length of the double pointer.
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;
	/* Loop through each element of the double pointer */
	for (i = 0; i < length; i++)
	{
		/* Free the memory occupied by the strings pointed to by double pointer */
		free(array[i]);
	}
	/* Free the memory occupied by the double pointer itself*/
	free(array);
}
