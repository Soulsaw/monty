#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "monty.h"
/**
 * div_stack - This function divides the second
 * top element of the stack by the top element of the stack.
 * @stack: Is the pointer to the first element of stack
 * @line_number: Is the number of the current line
 * Return: 0 on success or -1 on error
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current && current->prev)
	{
		current->prev->n /= current->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * mul - This function  multiplies the second top element
 * of the stack with the top element of the stack.
 * @stack: Is the pointer to the first element of stack
 * @line_number: Is the number of the current line
 * Return: 0 on success or -1 on error
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current && current->prev)
	{
		current->prev->n *= current->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * mod - This function computes the rest of the division of
 * the second top element of the stack by the top element of
 * @stack: Is the pointer to the first element of stack
 * @line_number: Is the number of the current line
 * Return: 0 on success or -1 on error
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current && current->prev)
	{
		current->prev->n %= current->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
