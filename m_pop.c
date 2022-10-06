#include "monty.h"
/**
 * pop - pops the very top element of the stack
 * @stack: stack given by main in start.c
 * @line_count: line number for error messages
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp = NULL;
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}
