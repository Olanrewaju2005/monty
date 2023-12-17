#include "monty.h"
/**
  * op_add - implements the add opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_add(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int len = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n + temp->next->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}
