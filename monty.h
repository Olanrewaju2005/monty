#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct term_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct term_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  term_t;
extern term_t term;

void op_pall(stack_t **head, unsigned int line_no);
void add_queue(stack_t **head, int i);
void op_push(stack_t **head, unsigned int line_no);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int i);
void free_vector(stack_t *head);
void op_add(stack_t **head, unsigned int line_no);
void op_div(stack_t **head, unsigned int line_no);
void op_mod(stack_t **head, unsigned int line_no);
void op_mul(stack_t **head, unsigned int line_no);
void op_nop(stack_t **head, unsigned int line_no);
void op_pchar(stack_t **head, unsigned int line_no);
void op_pint(stack_t **head, unsigned int line_no);
void op_pop(stack_t **head, unsigned int line_no);
void op_pstr(stack_t **head, unsigned int line_no);
void op_queue(stack_t **head, unsigned int line_no);
void op_rotl(stack_t **head, unsigned int line_no);
void op_rotr(stack_t **head, unsigned int line_no);
void op_stack(stack_t **head, unsigned int line_no);
void op_sub(stack_t **head, unsigned int line_no);
void op_swap(stack_t **head, unsigned int line_no);
int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file);

#endif
