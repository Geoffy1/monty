#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>

#define INSTRUCTIONS		    \
	{			     \
		{"push", push},       \
		    {"pall", pall},   \
		    {"pint", pint},   \
		    {"pop", pop},     \
		    {"swap", swap},   \
		    {"nop", nop},     \
		    {"div", _div},    \
		    {"mul", _mul},    \
		    {"add", _add},    \
		    {"sub", _sub},    \
		    {"mod", mod},     \
		    {"pchar", pchar}, \
		    {"pstr", pstr},   \
		    {"rotl", rotl},   \
		    {"rotr", rotr},   \
		{		      \
			NULL, NULL	\
		}                     \
	}


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct help - argument for the current opcode
 * @data_struct: stack mode, stack (default) and queue
 * @argument: the arguments of the string
 *
 * Description: global structure used to pass data around the functions easily
 */
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

void push(stack_t **stack, unsigned int line_count);
void pall(stack_t **stack, unsigned int line_count);
void pint(stack_t **stack, unsigned int line_count);
void pop(stack_t **stack, unsigned int line_count);
void nop(stack_t **stack, unsigned int line_count);
void swap(stack_t **stack, unsigned int line_count);

void _add(stack_t **stack, unsigned int line_count);
void _sub(stack_t **stack, unsigned int line_count);
void _mul(stack_t **stack, unsigned int line_count);
void _div(stack_t **stack, unsigned int line_count);
void mod(stack_t **stack, unsigned int line_count);

void pchar(stack_t **stack, unsigned int line_count);


void rotl(stack_t **stack, unsigned int line_count);
void rotr(stack_t **stack, unsigned int line_count);
void stack(stack_t **stack, unsigned int line_count);
void queue(stack_t **stack, unsigned int line_count);
void pstr(stack_t **stack, unsigned int line_count);
void m_fs_close(int status, void *arg);
void free_lineptr(int status, void *arg);

int is_digit(char *string);
int isnumber(char *str);

void opcode(stack_t **stack, char *str, unsigned int line_count);

#endif /* _MONTY_H_ */
