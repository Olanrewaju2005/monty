#include "monty.h"
/**
  * op_pall - implements the pall opcode
  * @head: first node of linked list (or queue)
  * @line_no: line number
  *
  * Return: void
  */
void op_pall(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	(void)line_no;
	temp = *head;
	if (!temp)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
