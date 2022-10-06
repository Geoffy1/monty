#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap -  swaps whole data stored
 * @stack: stack in main
 * @line_cnt: number of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
