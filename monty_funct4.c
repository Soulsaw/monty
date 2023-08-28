#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include "monty.h"
/**
 * _putchar - This function print a character
 * @c: Is the ascci code
 * Return: The output standard
*/
int _putchar(int c)
{
	return (write(1, &c, 1));
}
/**
 * pchar_stack - This function print the equivalent ascii value
 * @stack: Is the pointer to the top element
 * @line_number: The number of
 * Return: Nothing
*/
void pchar_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack)
	{
		_putchar((*stack)->n);
		_putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr_stack - This function permit to print the ascii value
 * @stack: Pointer
 * @line_number: Is the
 * Return: Nothing
 */
void pstr_stack(stack_t **stack, unsigned int line_number)
{
	while (*stack && (*stack)->n != 0)
	{
		pchar_stack(stack, line_number);
		*stack = (*stack)->prev;
	}
}
/**
 * rotl_stack - This function
 * @stack: Pointer
 * @line_number: Is the
 * Return: Nothing
 */
void rotl_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *tmp, *top;

	if (current)
	{
		tmp = *stack;
		top = (stack_t *)malloc(sizeof(stack_t));
		if (top == NULL)
		{
			fprintf(stderr, "malloc failed\n");
			return;
		}
		top->n = tmp->n;
		top->next = NULL;
		top->prev = NULL;
		while (current->prev)
		{
			current = current->prev;
		}
		current->prev = top;
		top->next = current;

		*stack = tmp;
		pop(stack, line_number);
	}
}
