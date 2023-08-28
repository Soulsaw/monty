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
		return;
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
		return;
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
		return;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * _putchar - This function print a character
 * @c: Is the ascci code
 * Return: The output standard
*/
int _putchar(int c)
{
	return write(1, &c, 1);
}
/**
 * pchar_stack - This function print the equivalent ascii value
 * @stack: Is the pointer to the top element
 * Return: Nothing
*/
void pchar_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->n < 0 && (*stack)->n > 127)
		return (1);
	if (stack)
	{
		_putchar((*stack)->n);
		return (0);
	}
	return (-1);
}
/**
 * 
*/
void pstr_stack(stack_t **stack, unsigned int line_number)
{
	int b = 0;
	while (*stack && (*stack)->n != 0)
	{
		pchar_stack(stack, line_number);
		*stack = (*stack)->prev;
		b = 1;
	}
	if (b)
		return (0);
	else
	{
		_putchar('\n');
		return;
	}
}
/**
 * 
*/
void rotl_stack(stack_t **stack)
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
		pop_stack(stack);
	}
}