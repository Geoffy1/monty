#include "monty.h"

/**
 * pint - print the value on top
 * @stack: stack given by main in start.c
 * @line_cnt: number of lines
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
