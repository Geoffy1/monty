#include "monty.h"

/**
 * _add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_count: script line number
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_count)
	{
	int result;
	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_cnt); /* For top node */
	(*stack)->n = result;
}
