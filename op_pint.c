#include "monty.h"
/**
  * op_pint - implements the pint opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_pint(stack_t **head, unsigned int line_no)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
