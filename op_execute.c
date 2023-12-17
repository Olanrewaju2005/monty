#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_no: line counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
	instruction_t opcodes[] = {
				{"push", op_push},
				{"pall", op_pall},
				{"pint", op_pint},
				{"pop", op_pop},
				{"swap", op_swap},
				{"add", op_add},
				{"nop", op_nop},
				{"sub", op_sub},
				{"div", op_div},
				{"mul", op_mul},
				{"mod", op_mod},
				{"pchar", op_pchar},
				{"pstr", op_pstr},
				{"rotl", op_rotl},
				{"rotr", op_rotr},
				{"queue", op_queue},
				{"stack", op_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	term.arg = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && op)
	{
		if (strcmp(op, opcodes[i].opcode) == 0)
		{	opcodes[i].f(stack, line_no);
			return (0);
		}
		i++;
	}
	if (op && opcodes[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
		fclose(file);
		free(content);
		free_vector(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
