#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "monty.h"
/**
 * print - print the top value on the stack
 * @stack: Is the pointer to the top element of stack
 * @line_number: Is the number of the current line
 * Return: Nothing
*/
void print(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - Remove the top element in the stack
 * @stack: Is the pointer to the top element
 * @line_number: Is the number of the current line
 * Return: Nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *current = *stack;

	if (current != NULL)
	{
		top = current;
		current = current->prev;
		free(top);

		(*stack) = current;
		return;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap - This function swaps the top two elements of the stack.
 * @stack: This i sthe pointer to the top of the stack
 * @line_number: Is the number of the current line
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *tmp, *top = *stack;
	unsigned int n;

	if (top && top->prev)
	{
		current = top;
		tmp = top->prev;
		n = tmp->n;

		tmp->n = current->n;
		current->n = n;
		return;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * add - This function add the two top elements of stack
 * @stack: Is the pointer to the first element of stack
 * @line_number: Is the number of the current line
 * Return: 0 on success or -1 on error
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current && current->prev)
	{
		current->prev->n += current->n;
		pop(stack, line_number);
		return;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
