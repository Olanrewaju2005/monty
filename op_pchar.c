#include "monty.h"
/**
  * op_pchar - implements the pchar opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_pchar(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	temp = *head;
	if (!temp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
