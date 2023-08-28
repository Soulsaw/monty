#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include "monty.h"
/**
 * get_instruc - Is a function permit to get another function
 * @opcode: Is the instruction given by the user
 * Return: A pointer to the function
 */
void (*get_instruc(const char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instrucs[] = {
		{"push", push},
		{"pall", pall},
		{"print", print},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	while (instrucs[i].opcode)
	{
		if (strcmp(instrucs[i].opcode, opcode) == 0)
			return (instrucs[i].f);
		i++;
	}
	return (NULL);
}

/**
 * execute_instruction - This function permit to execute any instruction
 * @stack: The pointer to the top element
 * @line_number: The number of the current line
 * @opcode: The instruction to execute
 * @arg: Is the argument to the push instruction
 * Return: Nothing
 */
void execute_instruction(stack_t **stack, unsigned int line_number,
const char *opcode, const char *arg)
{
	void (*instruct)(stack_t **, unsigned int);
	int value;

	instruct = get_instruc(opcode);
	if (instruct != NULL)
	{
		if (strcmp(opcode, "nop") == 0)
			return;
		if (strcmp(opcode, "push") == 0 && arg != NULL)
		{
			value = atoi(arg);
			instruct(stack, value);
		}
		else if (strcmp(opcode, "push") == 0 && arg == NULL)
		{
			fprintf(stderr, "L%u:usage:push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			instruct(stack, line_number);
		}
		return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * push - This function permits to push a integer in the stack
 * @stack: Is the pointer to the top element
 * @value: Is an integer that we want to add in the stack
 * Return: The node of the new element
 */
void push(stack_t **stack, unsigned int value)
{
	stack_t *top, *current = *stack;

	top = (stack_t *)malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		return;
	}
	top->n = value;
	top->next = NULL;
	top->prev = NULL;

	if (current == NULL)
	{
		*stack = top;
		return;
	}

	top->prev = current;
	current->next = top;

	*stack = top;
}
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Is the pointer to the top element of stack
 * @line_number: Is the number of the current line
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
	line_number += 1;
}
/**
 * free_stack - This function free all alloc of the stack
 * @stack: Is a pointer to the top element of stack
 * Return: Nothing
*/
void free_stack(stack_t *stack)
{
	stack_t *top;

	while (stack != NULL)
	{
		top = stack;
		stack = stack->prev;
		free(top);
	}
}
