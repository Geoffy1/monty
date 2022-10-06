#include "monty.h"
/**
 * _sub -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_count: line counter
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_count)
{
	int result;
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_count); /*For top node*/
	(*stack)->n = result;
}
