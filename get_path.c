#include "main.h"
/**
   * get_path - Search for file name in PATH and return the path to the file.
   * @filename: File name to be searched for.
   * Return: If path was found - path to the file.
   *         Otherwise - NULL.
   */
char *get_path(char *filename)
{
	char *dirs, *token, *txt, *path;
	char **directory;
	int i = 0, j = 0;
	struct stat stats;

	/* Get directories of executable programs*/
	dirs = getenv("PATH");
	token = strtok(dirs, ":");

	txt = malloc(500);
	directory = malloc(500);
	path = malloc(500);
	while (token != NULL)
	{
		directory[i] = token;
		i++;
		token = strtok(NULL, ":");
	}


/* Join txt to directory path & check if its true*/

	strcat(txt, "/");
	strcat(txt, filename);

	while (directory[j] != NULL)
	{
		strcpy(path, directory[j]);
		strcat(path, txt);
		if (stat(path, &stats) == 0)
			return (path);

		j++;
	}

	free(txt);
	free(path);
	return (NULL);
}
