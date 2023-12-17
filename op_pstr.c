#include "monty.h"
/**
  * op_pstr - implements the pstr opcode
  * @head: first node
  * @line_no: line number
  *
  * Return: void
  */
void op_pstr(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	(void)line_no;

	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
