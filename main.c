#include "main.h"

/**
 * main - Simple shell.
 *
 * @argc: Number of arguments passed to the function.
 * @argv: Array of string passed to the function.
 *
 * Description: Display a promt and wait for the user to type a command.
 * Split the input into arguments and execute it.
 * Display result on the screen and display promt again.
 *
 * Return: If successful - 1.
 */
int main(int argc, char **argv)
{
	char *str;
	char **args;
	int status = 1;

	(void)argc;
	(void)argv;

	while (status)
	{
		printf("$ ");
		str = read_line();
		args = parse_line(str);
		status = run_command(args, argv);
		free(str);
		free(args);
	}

	return (1);
}

