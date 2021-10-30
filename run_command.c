#include "main.h"
/**
 * run_command - Executes the program referred to by path.
 * @args: Pointer to pointer to arguments.
 *
 * Return: On success - 1.
 */
int run_command(char **args)
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror(args[0]);
	}
	else
		wait(&status);

	return (1);
}

