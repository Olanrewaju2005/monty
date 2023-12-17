#include "monty.h"
/**
  * op_pop - implements the pop opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_pop(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
