#include "main.h"
/**
 * read_line - Read an entire line from stream into a buffer.
 * Return: Buffer containing read line.
 */
char *read_line()
{
	char *line = NULL;
	int bytes_size;
	size_t len = 0;

	bytes_size = getline(&line, &len, stdin);
	*(line + strlen(line) - 1) = '\0';

	if (bytes_size < 0)
		perror("Error");

	return (line);
}

/**
 * parse_line - Splits a string by given delimiter(s).
 * @line: String to be split;
 * Return: An array of pointers to parsed string.
 */
char **parse_line(char *line)
{
	char delim[] = " ";
	char *token;
	char **array;
	int index = 0, len = 100;

	array = malloc(sizeof(char *) * len);
	if (!array)
		perror("Unable to allocate memory");

	token = strtok(line, delim);

	while (token != NULL)
	{
		array[index] = token;
		index++;

		token = strtok(NULL, delim);
	}

	array[index] = NULL;
	return (array);
}

