#include "main.h"

/**
 * main - Simple shell.
 *
 * Description: Display a promt and wait for the user to type a command.
 * Split the input into arguments and execute it.
 * Display result on the screen and display promt again.
 *
 * Return: If successful - 1.
 */
int main(void)
{
	char *str;
	char **args;
	int status = 1;

	while (status)
	{
		printf("$ ");
		str = read_line();
		args = parse_line(str);
		status = run_command(args);
	}

	free(str);
	free(args);

	return (1);
}

