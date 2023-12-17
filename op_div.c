#include "monty.h"
/**
  * op_div - implements the div opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_div(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	int len, aux;

	temp = *head;
	for (len = 0; temp != NULL; len++)
		temp = temp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		fclose(term.file);
		free(term.content);
		free_vector(*head);
		exit(EXIT_FAILURE);
	}

	aux = temp->next->n / temp->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}
