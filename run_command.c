#include "main.h"
char *_strchr(char *s, char c);


/**
 * run_command - Executes the program referred to by path.
 * @args: Pointer to pointer to arguments.
 * @argv: Array of strings from the input of the main function.
 * Return: On success - 1.
 */
int run_command(char **args, char **argv)
{
	int status;
	pid_t pid1;
	pid_t pid2;
	char *args0;

	(void)argv;

/* Check if first command doesnt have a '/' */

	if (!strchr(args[0], '/'))
	{
		args0 = get_path(args[0]);
		if (args0 != NULL)
		{
			pid1 = fork();
			if (pid1 == 0)
			{
				if (execve(args0, args, NULL) == -1)
					perror(args0);
			}
			else
				wait(&status);
		}
	}


	/* Run command that has a '/' */
	pid2 = fork();

	if (pid2 == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror(args[0]);
	}
	else
		wait(&status);

	return (1);
}




/**
 * _strchr - Locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */
char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index] >= '\0'; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return ('\0');
}
