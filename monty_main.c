#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "monty.h"
#define BUFFER_SIZE 1024
/**
 * main - The entry point of program
 * @argc: The array size
 * @argv: The argument array
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char buffer[BUFFER_SIZE];
	char *token, *word = NULL, *ptr, *arg;
	ssize_t nread;
	unsigned int line_number = 0;
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE:monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = read(fd, buffer, sizeof(buffer))) > 0)
	{
		ptr = buffer;
		while ((word = __strtok_r(ptr, "\n", &ptr)) != NULL)
		{
			line_number++;
			token = strtok(word, " \t\n");
			if (token && token[0] != '#')
			{
				arg = strtok(NULL, " \t\n");
				execute_instruction(&stack, line_number, token, arg);
			}
		}
	}
	free_stack(stack);
	close(fd);

	return (EXIT_SUCCESS);
}
